
#ifndef COORDINATES_H
#define COORDINATES_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <vector>

using std::vector;
using std::string;

//TODO namespace gui {};
namespace ICoordinates
{
const SDL_Rect eMainWindow ={  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 640 };

const vector<SDL_Rect> eMenuButtons =
{
    {25, 1*(25 + eMainWindow.h / 10), 125, eMainWindow.h / 10 },
    {25, 2*(25 + eMainWindow.h / 10), 125, eMainWindow.h / 10 },
    {25, 3*(25 + eMainWindow.h / 10), 125, eMainWindow.h / 10 },
    {25, 4*(25 + eMainWindow.h / 10), 125, eMainWindow.h / 10 },
    {25, 5*(25 + eMainWindow.h / 10), 125, eMainWindow.h / 10 },
};

const SDL_Rect HEX_TILE_MAP = { 150, 50, 0, 0 }; /*Change x,y to move all hexagon map */
const vector<SDL_Rect> eHexTile =
{
    {260, 30 , 0, 0 },
    {135, 100, 0, 0 },
    {385, 100, 0, 0 },
    {260, 170, 0, 0 },
    {260, 310, 0, 0 },
    {135, 240, 0, 0 },
    {385, 240, 0, 0 }
};

const vector<SDL_Rect> eBowMenuButtons = 
{
  {800, 225, 50, 50 },
  {800, 300, 50, 50 },
  {800, 375, 50, 50 }
};

};

namespace HexagonTiles
{
enum Tiles
{
    LeftTop,
    LeftDown,
    Top,
    Center,
    Down,
    RightTop,
    RightDown,
    HexTileCount
};
};

namespace BowDirections
{
enum Directions
{
    Top, TopLeft, TopRight, Down, DownLeft, DownRight,
    DirectionCount,
    begin = 0,
    end = (DirectionCount - 1)
};
};


namespace BowTypes
{
enum Types
{
// 	OnePoint,
// 	TwoPointV1, TwoPointV2, TwoPointV3,
// 	ThreePointV1, ThreePointV2, ThreePointV3, ThreePointV4,
// 	FourPointV1, FourPointV2, FourPointV3,
// 	FivePoint,
// 	SixPoint,
// 	TypesCount
    OnePoint,
    TwoPointV1,
    TypesCount
};
};

#endif // COORDINATES_H
