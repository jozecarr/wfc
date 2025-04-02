#include <raylib.h>

#include "Tile.h"
#include "Grid.h"

#define TILE_SIZE 30

int TTile_data[3][3] = {
    {1, 1, 1},
    {0, 1, 0},
    {0, 1, 0}
}; 
Tile TTile(TTile_data);


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

int main() {
    InitWindow(800, 600, "Raylib 3x3 Tile Drawing");

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
