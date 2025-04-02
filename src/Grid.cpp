#include "Grid.h" 

Grid::Grid() {
    tiles.resize(5, vector<Tile>(5));
}

Grid::Grid(int sizeX, int sizeY) {
    tiles.resize(sizeX, vector<Tile>(sizeY));
}
