#ifndef COLLAPSER_H
#define COLLAPSER_H

#include "Tile.h"
#include "Grid.h"

class Collapser {
public:
    Collapser();
    int tileSize;
    Grid initGrid;

    void init(const Grid& _initGrid, int windowSizeX = 1000, int windowSizeY = 1000,  const char* windowTitle = "WFC");

    void run(int rate = 1);

    void DrawTile(int x, int y, const Tile& tile);
    void DrawGrid(const Grid& grid);
};

#endif
