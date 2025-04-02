#ifndef BASICTILES_H
#define BASICTILES_H

#include <Tile.h>

int TTile_data[3][3] = {
    {1, 1, 1},
    {0, 1, 0},
    {0, 1, 0}
}; 
Tile TTile(TTile_data);

int VertMidLineTile_data[3][3] = {
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0}
};
Tile VertMidLineTile(VertMidLineTile_data);

int HorizMidLineTile_data[3][3] = {
    {0, 0, 0},
    {1, 1, 1},
    {0, 0, 0}
};
Tile HorizMidLineTile(HorizMidLineTile_data);

int LeftLineTile_data[3][3] = {
    {1, 0, 0},
    {1, 0, 0},
    {1, 0, 0}
};
Tile LeftLineTile(LeftLineTile_data);

#endif 