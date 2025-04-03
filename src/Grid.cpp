#include "Grid.h" 

Grid::Grid() {
    sizeX = 5;
    sizeY = 5;
    tiles.resize(5, vector<Tile>(5));
}

Grid::Grid(int _sizeX, int _sizeY) {
    sizeX = _sizeX;
    sizeY = _sizeY;
    tiles.resize(sizeX, vector<Tile>(sizeY));
}
