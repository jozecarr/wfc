#ifndef BASICTILES_H
#define BASICTILES_H

#include "Tile.h"

bool vertMidLineTile_data[3][3] = {
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0}
};
Tile vertMidLineTile(vertMidLineTile_data);

bool horizMidLineTile_data[3][3] = {
    {0, 0, 0},
    {1, 1, 1},
    {0, 0, 0}
};
Tile horizMidLineTile(horizMidLineTile_data);

bool plusTile_data[3][3] = {
    {0, 1, 0},
    {1, 1, 1},
    {0, 1, 0}
}; 
Tile plusTile(plusTile_data);

bool TLCornerTile_data[3][3] = {
    {0, 1, 0},
    {1, 1, 0},
    {0, 0, 0}
};
Tile TLCornerTile(TLCornerTile_data);

bool TRCornerTile_data[3][3] = {
    {0, 1, 0},
    {0, 1, 1},
    {0, 0, 0}
};
Tile TRCornerTile(TRCornerTile_data);

bool BRCornerTile_data[3][3] = {
    {0, 0, 0},
    {0, 1, 1},
    {0, 1, 0}
};
Tile BRCornerTile(BRCornerTile_data);

bool BLCornerTile_data[3][3] = {
    {0, 0, 0},
    {1, 1, 0},
    {0, 1, 0}
};
Tile BLCornerTile(BLCornerTile_data);


#endif 