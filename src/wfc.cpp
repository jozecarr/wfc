#include "Collapser.h"
#include "Tile.h"
#include "Grid.h"
#include "BasicTiles.h"

#include <raylib.h>

#define TILE_SIZE 30



int main() {
    Grid grid(100, 100);
    
    grid.tiles[3][3] = TTile;
    grid.tiles[4][3] = TTile;
    grid.tiles[0][0] = TTile;
    grid.tiles[29][87] = TTile;
    
    Collapser collapser;
    collapser.init(grid);
    collapser.run();

    return 0;
}
