#include "Tile.h" 

Tile::Tile() {
    set = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] = 0;
        }
    }
}

Tile::Tile(const int (&_data)[3][3]) {
    set = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            data[i][j] = _data[i][j];
        }
    }
}

using std::swap;

void Tile::FlipHorizontally() {
    for (int i = 0; i < 3; i++) {
        swap(data[i][0], data[i][2]);
    }
}

void Tile::FlipVertically() {
    swap(data[0], data[2]); 
}

bool Tile::operator==(const Tile& other) const {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int FindTileIndex(const Tile& tile, const vector<Tile>& tileset) {
    for (int i = 0; i < tileset.size(); i++) {
        if (tileset[i] == tile) {
            return i;
        }
    }
    return -1;
}
