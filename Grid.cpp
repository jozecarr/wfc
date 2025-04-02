#include "Grid.h" 

Grid::Grid(int sizeX, int sizeY) {
    tiles.resize(sizeX, vector<Tile>(sizeY));
}
