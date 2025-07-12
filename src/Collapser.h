#ifndef COLLAPSER_H
#define COLLAPSER_H

#include "Tile.h"
#include "Grid.h"

using std::pair;

class Collapser {
public:
    Collapser();
    int cellSize;
    Grid grid;
    vector<Tile> tileset;
    vector<vector<vector<bool>>> entropies;

    void ResizeEntropies(int x, int y, int z);
    void InitEntropies();

    void Init(const Grid& _grid, const vector<Tile>& _tileset, int windowSizeX = 1000, int windowSizeY = 1000,  const char* windowTitle = "WFC");

    void DrawTile(int x, int y, const Tile& tile);
    void PrintTile(const Tile& tile);    
    void DrawGrid();
    int  GetEntropy(int x, int y);
    void DrawEntropies();

    bool CheckCanChangeEnts(int x, int y);
    bool CheckAdjEqual(const bool (&adjacentSubtiles)[2][3]);
    bool GetAdjSubtiles(int aX, int aY, int bX, int bY, const Tile &TileB);
    bool AdjacencyAllowed(int aX, int aY, int bX, int bY, const Tile &TileB);

    bool UpdateAdjEntropies(int x, int y); // for when a tile is set, recalculate neighboring entropies.

    pair<int, int> GetLowestEntropyNeighbor(int x, int y);

    vector<pair<int, int>> Collapse(const vector<pair<int, int>> &setCells);

    void run(int rate = 1);

};

#endif
