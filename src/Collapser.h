#ifndef COLLAPSER_H
#define COLLAPSER_H

#include "Tile.h"
#include "Grid.h"


class Collapser {
public:
    Collapser();
    int tileSize;
    Grid grid;
    vector<Tile> tileset;
    vector<vector<vector<int>>> entropies;

    void ResizeEntropies(int x, int y, int z);
    void InitEntropies();

    void Init(const Grid& _grid, const vector<Tile>& _tileset, int windowSizeX = 1000, int windowSizeY = 1000,  const char* windowTitle = "WFC");

    void run(int rate = 1);

    void DrawTile(int x, int y, const Tile& tile);
    void DrawGrid(const Grid& grid);
};

#endif
