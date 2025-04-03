#ifndef BASICTILES_H
#define BASICTILES_H

#include "Tile.h"

int TTile_data[3][3] = {
    {1, 1, 1},
    {0, 1, 0},
    {0, 1, 0}
}; 
Tile TTile(TTile_data);

int vertMidLineTile_data[3][3] = {
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0}
};
Tile vertMidLineTile(vertMidLineTile_data);

int horizMidLineTile_data[3][3] = {
    {0, 0, 0},
    {1, 1, 1},
    {0, 0, 0}
};
Tile horizMidLineTile(horizMidLineTile_data);

int leftLineTile_data[3][3] = {
    {1, 0, 0},
    {1, 0, 0},
    {1, 0, 0}
};
Tile leftLineTile(leftLineTile_data);

#endif 