#ifndef COLLAPSER_H
#define COLLAPSER_H

#include "Tile.h"
#include "Grid.h"


class Collapser {
public:
    Collapser();
    int cellSize;
    Grid grid;
    vector<Tile> tileset;
    vector<vector<vector<int>>> entropies;

    void ResizeEntropies(int x, int y, int z);
    void InitEntropies();

    void Init(const Grid& _grid, const vector<Tile>& _tileset, int windowSizeX = 1000, int windowSizeY = 1000,  const char* windowTitle = "WFC");

    void DrawTile(int x, int y, const Tile& tile);
    void DrawGrid();
    void ShowEntropies();

    bool CheckAdjEqual(const bool (&adjacentSubtiles)[2][3]);
    void GetAdjSubtiles(int aX, int aY, int bX, int bY, const Tile &candidate, bool (&adjacentSubtiles)[2][3]);
    bool AdjacencyAllowed(int aX, int aY, int bX, int bY, const Tile &candidate);

    void UpdateAdjEntropies(int x, int y); // for when a tile is set, recalu

    void run(int rate = 1);

};

#endif
