#include "Collapser.h"
#include "Tile.h"
#include <raylib.h>
#include <stdio.h>
#include <cmath>

Collapser::Collapser() : grid(5, 5) {
    cellSize = 20;
}

void Collapser::ResizeEntropies(int x, int y, int z) {
    entropies.resize(x);  // Resize to X rows (outermost dimension)
    for (int i = 0; i < x; ++i) {
        entropies[i].resize(y);  // Resize each row to Y columns
        for (int j = 0; j < y; ++j) {
            entropies[i][j].resize(z, 0);  // Resize each cell (depth Z) and initialize with 0
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
                    entropies[i][j] = {index};
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

void Collapser::DrawGrid() {
    int gridWidth = grid.tiles.size();
    int gridHeight = (gridWidth > 0) ? grid.tiles[0].size() : 0;

    if (gridWidth > 0 && gridHeight > 0) {
        cellSize = std::min(GetScreenWidth() / (gridWidth * 3), GetScreenHeight() / (gridHeight * 3));
    }

    for (int i = 0; i < gridWidth; i++) {
        for (int j = 0; j < gridHeight; j++) {
            int x = i * 3 * cellSize;
            int y = j * 3 * cellSize;
            DrawTile(x, y, grid.tiles[i][j]);
        }
    }
}

void Collapser::ShowEntropies() {
    for (int x = 0; x < grid.sizeX; x++) {
        for (int y = 0; y < grid.sizeY; y++) {
            char text[10];  
            sprintf(text, "%d", entropies[x][y].size());

            int posX = x * cellSize * 3;
            int posY = y * cellSize * 3;
            
            DrawText(text, posX + 5, posY + 5, 20, GREEN);
            DrawRectangleLines(posX, posY, cellSize * 3, cellSize * 3, RED);
        }
    }
}

bool Collapser::CheckAdjEqual(const bool (&adjacentSubtiles)[2][3]) {
    for (int i = 0; i < 3; i++) {
        if (adjacentSubtiles[0][i] != adjacentSubtiles[1][i]) return false;
    } return true;
}

void Collapser::GetAdjSubtiles(int aX, int aY, int bX, int bY, bool (&adjSubtiles)[2][3]) {
    int dX = bX - aX;
    int dY = bY - aY;

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

        adjSubtiles[0][i] = grid.tiles[aX][aY].data[saX][saY];
        adjSubtiles[1][i] = grid.tiles[aX][aY].data[sbX][sbY];
    }
}

bool Collapser::AdjacencyAllowed(int aX, int aY, int bX, int bY) {
    int dX = bX - aX;
    int dY = bY - aY;

    if (abs(dX) + abs(dY) == 2) return true; // TODO maybe add diagonal adjacency rules, but for now im not
    
    bool adjacentSubtiles[2][3];
    GetAdjSubtiles(aX, aY, bX, bY, adjacentSubtiles);
    return CheckAdjEqual(adjacentSubtiles);
}

// TODO function to recalculate the entropy of a tile based on its neighbors

void Collapser::RecalculateEntropies() {
    
}

void Collapser::run(int rate) {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        // TODO MAIN STUFF
        DrawGrid();

        ShowEntropies();
        

        EndDrawing();
    }

    CloseWindow();
}
