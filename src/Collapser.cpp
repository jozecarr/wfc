#include "Collapser.h"
#include "Tile.h"

#include <raylib.h>
#include <stdio.h>
#include <cmath>
#include <iostream>

Collapser::Collapser() : grid(5, 5) {
    cellSize = 20;
}

void Collapser::ResizeEntropies(int x, int y, int z) {
    entropies.resize(x);  // Resize to X rows (outermost dimension)
    for (int i = 0; i < x; ++i) {
        entropies[i].resize(y);  // Resize each row to Y columns
        for (int j = 0; j < y; ++j) {
            entropies[i][j].resize(z, true);  // Resize each cell (depth Z) and initialize with true
        }
    }
}

void Collapser::InitEntropies() {
    ResizeEntropies(grid.sizeX, grid.sizeY, tileset.size());

    for (int i = 0; i < grid.sizeX; i++) {
        for (int j = 0; j < grid.sizeY; j++) {
            if (grid.tiles[i][j].set) {
                int index = FindTileIndex(grid.tiles[i][j], tileset);
                if (index != -1) {
                    entropies[i][j][index] = true;
                }
            } else {
                for (int k = 0; k < tileset.size(); k++) {
                    entropies[i][j][k] = ;
                }
                
            }
        }
    }
}

void Collapser::Init(const Grid& _grid, const vector<Tile>& _tileset, int windowSizeX, int windowSizeY, const char* windowTitle) {
    InitWindow(windowSizeX, windowSizeY, windowTitle);
    grid = _grid;
    tileset = _tileset;

    int gridWidth = grid.tiles.size();
    int gridHeight = (gridWidth > 0) ? grid.tiles[0].size() : 0;

    if (gridWidth > 0 && gridHeight > 0) {
        cellSize = std::min(windowSizeX / (gridWidth * 3), windowSizeY / (gridHeight * 3));
    }

    InitEntropies();
}


void Collapser::DrawTile(int x, int y, const Tile& tile) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Color color = (tile.data[i][j] == 1) ? RAYWHITE : BLACK;
            DrawRectangle(x + j * cellSize, y + i * cellSize, cellSize, cellSize, color);
        }
    }
}

void Collapser::PrintTile(const Tile& tile) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char subtile = (tile.data[i][j] == 1) ? '1' : '0';
            printf("%c", subtile);
        }
        printf("\n");
    }
}

void Collapser::DrawGrid() {
    int gridWidth = grid.tiles.size();
    int gridHeight = (gridWidth > 0) ? grid.tiles[0].size() : 0;

    if (gridWidth > 0 && gridHeight > 0) {
        cellSize = std::min(GetScreenWidth() / (gridWidth * 3), GetScreenHeight() / (gridHeight * 3));
    }

    for (int i = 0; i < gridWidth; i++) {
        for (int j = 0; j < gridHeight; j++) {
            int x = i * 3 * cellSize; 
            int y = (gridHeight - j - 1) * 3 * cellSize; // invert y

            DrawTile(x, y, grid.tiles[i][j]);
        }
    }
}

int Collapser::GetEntropy(int x, int y) {
    int entropy = 0;
    for (int i = 0; i < tileset.size(); i++) {
        if (entropies[x][y][i]) entropy++;
    } return entropy;
}

void Collapser::DrawEntropies() {
    for (int x = 0; x < grid.sizeX; x++) {
        for (int y = 0; y < grid.sizeY; y++) {
            char text[10];  
            sprintf(text, "%d", GetEntropy(x,y));

            int posX = x * cellSize * 3;
            int posY = (grid.sizeY - y - 1) * cellSize * 3;  // invert y

            int textWidth = MeasureText(text, 20);
            int textHeight = 20;

            DrawText(text, posX + (cellSize * 3 - textWidth) / 2, posY + (cellSize * 3 - textHeight) / 2, 20, GREEN);

            DrawRectangleLines(posX, posY, cellSize * 3, cellSize * 3, RED);
        }
    }
}

bool Collapser::AdjacencyAllowed(int aX, int aY, int bX, int bY, const Tile &tileB) {
    int dX = bX - aX;
    int dY = bY - aY;

    if (abs(dX) + abs(dY) == 2) return true; // TODO maybe add diagonal adjacency rules, but for now, no

    const Tile& tileA = grid.tiles[aX][aY];

    for(int i = 0; i < 3; i++) {  
        int saX = (dY != 0) ? i : (dX == 1) ? 2 : 0;
        int sbX = (dY != 0) ? i : (dX == 1) ? 0 : 2;
        int saY = (dX != 0) ? i : (dY == 1) ? 0 : 2;
        int sbY = (dX != 0) ? i : (dY == 1) ? 2 : 0;

        /* saX, saY, sbX and sbY correspond to the x and y coordinates of the subtiles of a and b.
        For the x coordinates of the subtiles (the column), they first check if tile b has vertical offset
        from a if so, they will always be i, since it just goes across the row, similarly for the y coords.
        if not, it then checks the other axis, for example, in saX, if b is to the right, then the x
        coordinate of the subtiles will be 2, as this is the rightmost column of tile a. */

        if (tileA.data[saY][saX] != tileB.data[sbY][sbX]) {  
            return false;
        }
    }

    return true;
}

bool Collapser::CheckCanChangeEnts(int x, int y) {
    return (x >= 0 && x < grid.sizeX && y >= 0 && y < grid.sizeY && !grid.tiles[x][y].set);
}

bool Collapser::UpdateAdjEntropies(int x, int y) {
    int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    vector<bool> tempEntropies[4] = {{},{},{},{}};
    
    for(int i = 0; i < 4; i++) {
        bool noValidsFlag = true;
        int bX = x + dirs[i][0];
        int bY = y + dirs[i][1];

        if (CheckCanChangeEnts(bX, bY)) { // make sure the neighbor exists in the grid and isnt already set
            for(int j = 0; j < tileset.size(); j++) { // check each candidate of a cell, if its valid, keep it
                if (entropies[bX][bY][j] && AdjacencyAllowed(x, y, bX, bY, tileset[j])) {
                    tempEntropies[i].push_back(true);
                    noValidsFlag = false;
                } else {
                    tempEntropies[i].push_back(false);
                }
            }
        } else noValidsFlag = false;
        if (noValidsFlag) return false;
    }

    for (int i = 0; i < 4; i++) {
        int bX = x + dirs[i][0];
        int bY = y + dirs[i][1];

        if (CheckCanChangeEnts(bX, bY)) {
            entropies[bX][bY] = tempEntropies[i];
        }
    }
    
    return true;
}

pair<int, int> Collapser::GetLowestEntropyNeighbor(int x, int y) {
    int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int index = 0;
    int val = GetEntropy(x + dirs[0][0], y + dirs[0][1]);
    for (int i = 1; i < 4; i++) {
        int tempVal = GetEntropy(x + dirs[i][0], y + dirs[i][1]) < val;
        if (tempVal < val) {
            index = i; 
            val = tempVal;
        }   
    }
    return {x + dirs[index][0], y + dirs[index][1]};
}

void Collapser::Collapse(const vector<pair<int, int>> &setCells) {
    for (const auto &i : setCells) {
        if(UpdateAdjEntropies(i.first, i.second)){
            pair<int,int> lowestEntropyNeighbor = GetLowestEntropyNeighbor(i.first, i.second);
            //TODO continue
        } else {
            grid.tiles[i.first][i.second] = Tile();
        }
    }
}

void Collapser::run(int rate) {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        // TODO MAIN STUFF
        DrawGrid();

        DrawEntropies();

        EndDrawing();
    }

    CloseWindow();
}
