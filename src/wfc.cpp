#include "Collapser.h"
#include "Tile.h"
#include "Grid.h"
#include "BasicTiles.h"

#include <iostream>

#define TILE_SIZE 30

// test

int main() {
    Grid grid(10, 10);

    vector<Tile> tileset = {
        vertMidLineTile,
        horizMidLineTile,
        plusTile,
        TLCornerTile,
        TRCornerTile,
        BRCornerTile,
        BLCornerTile
          
    };
    
    //example grid initialisation
    grid.tiles[6][2] = horizMidLineTile;
    grid.tiles[8][9] = vertMidLineTile;

    Collapser collapser;
    collapser.Init(grid, tileset);

    collapser.UpdateAdjEntropies(6,2);
    collapser.UpdateAdjEntropies(8,9);    

    collapser.run();

    return 0;
}
