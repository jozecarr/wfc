#ifndef TILE_H
#define TILE_H

class Tile {
public:
    int data[3][3];

    Tile();
    Tile(const int (&_data)[3][3]);

    void FlipHorizontally();
    void FlipVertically();
};

#endif