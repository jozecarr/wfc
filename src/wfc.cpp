#include "Collapser.h"
#include "Tile.h"
#include "Grid.h"
#include "BasicTiles.h"

#include <raylib.h>

#define TILE_SIZE 30

// test

int main() {
    Grid grid(10, 10);

    //example tile creation
    int exTile_data[3][3] = {
        {1, 1, 1},
        {0, 1, 0},
        {1, 1, 0}
    }; 
    Tile exTile(exTile_data);

    vector<Tile> tileset = {
        TTile,
        exTile,
        vertMidLineTile,
        horizMidLineTile,
        leftLineTile
    };
    
    //example grid initialisation
    grid.tiles[3][3] = TTile;
    grid.tiles[4][3] = exTile;
    grid.tiles[6][2] = horizMidLineTile;
    grid.tiles[8][9] = vertMidLineTile;
    grid.tiles[0][0] = TTile;

    Collapser collapser;
    collapser.Init(grid, tileset);
    collapser.run();

    return 0;
}
