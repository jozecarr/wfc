#ifndef GRID_H
#define GRID_H

#include "Tile.h" 
#include <vector>
using std::vector;

class Grid {
public:
    int sizeX;
    int sizeY;
    vector<vector<Tile>> tiles;

    Grid();
    Grid(int sizeX, int sizeY);
};

#endif