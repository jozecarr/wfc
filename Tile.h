#ifndef TILE_H  // Include guard
#define TILE_H

class Tile {
public:
    int data[3][3];

    // Constructors
    Tile();  // Default constructor
    Tile(const int (&_data)[3][3]);  // Constructor with data

    // Flip functions
    void FlipHorizontally();
    void FlipVertically();
};

#endif  // TILE_H
