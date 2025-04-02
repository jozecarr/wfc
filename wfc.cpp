#include <raylib.h>

#include "Tile.h"
#include "Grid.h"
#include "BasicTiles.h"

#define TILE_SIZE 30

void DrawTile(int x, int y, const Tile& tile) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Color color = (tile.data[i][j] == 1) ? RAYWHITE : BLACK;
            DrawRectangle(x + j * TILE_SIZE, y + i * TILE_SIZE, TILE_SIZE, TILE_SIZE, color);
        }
    }
}

void DrawGrid(const Grid& grid) {
    for (int i = 0; i < grid.tiles.size(); i++) {
        for(int j = 0; j < grid.tiles[i].size(); j++) {
            int x = i * 3 * TILE_SIZE;
            int y = j * 3 * TILE_SIZE;
            DrawTile(x, y, grid.tiles[i][j]);
        }
    }
}

//test

int main() {
    InitWindow(800, 600, "WFC");

    Grid grid(5, 5);
    
    grid.tiles[3][3] = TTile;
    grid.tiles[4][3] = TTile;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawGrid(grid);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
