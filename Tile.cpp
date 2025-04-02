#include "Tile.h" 
#include <vector>
using std::swap;

Tile::Tile() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] = 0;
        }
    }
}

Tile::Tile(const int (&_data)[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] = _data[i][j];
        }
    }
}

void Tile::FlipHorizontally() {
    for (int i = 0; i < 3; i++) {
        swap(data[i][0], data[i][2]);
    }
}

void Tile::FlipVertically() {
    swap(data[0], data[2]); 
}
