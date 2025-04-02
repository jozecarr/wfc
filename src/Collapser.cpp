#include "Collapser.h"
#include "Tile.h"
#include <raylib.h>

Collapser::Collapser() : initGrid(5, 5) {
    tileSize = 20;
}

void Collapser::init(const Grid& _initGrid, int windowSizeX, int windowSizeY, const char* windowTitle) {
    InitWindow(windowSizeX, windowSizeY, windowTitle);
    initGrid = _initGrid;

    int gridWidth = initGrid.tiles.size();
    int gridHeight = (gridWidth > 0) ? initGrid.tiles[0].size() : 0;

    if (gridWidth > 0 && gridHeight > 0) {
        tileSize = std::min(windowSizeX / (gridWidth * 3), windowSizeY / (gridHeight * 3));
    }
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
        DrawGrid(initGrid);

        EndDrawing();
    }

    CloseWindow();
}
