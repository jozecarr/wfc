#ifndef GRID_H
#define GRID_H

#include "Tile.h" 
#include <vector>
using std::vector;

class Grid {
public:
    vector<vector<Tile>> tiles;

    Grid(int sizeX, int sizeY);
};

#endif