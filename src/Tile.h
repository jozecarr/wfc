#ifndef TILE_H
#define TILE_H

#include <vector>
using std::vector;

class Tile {
public:
    bool data[3][3];
    bool set;

    Tile();
    Tile(const int (&_data)[3][3]);

    bool operator==(const Tile& other) const;

    void FlipHorizontally();
    void FlipVertically();
};

int FindTileIndex(const Tile& tile, const vector<Tile>& tileset);

#endif