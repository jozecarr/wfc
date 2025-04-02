#ifndef GRID_H  // Include guard
#define GRID_H

#include "Tile.h"  // Include the Tile class
#include <vector>
using std::vector;

class Grid {
public:
    vector<vector<Tile>> tiles;

    Grid(int sizeX, int sizeY);
};

#endif  // GRID_H
