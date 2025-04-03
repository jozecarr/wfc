#include "Collapser.h"
#include "Tile.h"
#include <raylib.h>

Collapser::Collapser() : grid(5, 5) {
    tileSize = 20;
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
        tileSize = std::min(windowSizeX / (gridWidth * 3), windowSizeY / (gridHeight * 3));
    }

    InitEntropies();
}


void Collapser::DrawTile(int x, int y, const Tile& tile) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Color color = (tile.data[i][j] == 1) ? RAYWHITE : BLACK;
            DrawRectangle(x + j * tileSize, y + i * tileSize, tileSize, tileSize, color);
        }
    }
}

void Collapser::DrawGrid(const Grid& grid) {
    int gridWidth = grid.tiles.size();
    int gridHeight = (gridWidth > 0) ? grid.tiles[0].size() : 0;

    if (gridWidth > 0 && gridHeight > 0) {
        tileSize = std::min(GetScreenWidth() / (gridWidth * 3), GetScreenHeight() / (gridHeight * 3));
    }

    for (int i = 0; i < gridWidth; i++) {
        for (int j = 0; j < gridHeight; j++) {
            int x = i * 3 * tileSize;
            int y = j * 3 * tileSize;
            DrawTile(x, y, grid.tiles[i][j]);
        }
    }
}

void Collapser::run(int rate) {
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        // TODO MAIN STUFF
        DrawGrid(grid);

        EndDrawing();
    }

    CloseWindow();
}
