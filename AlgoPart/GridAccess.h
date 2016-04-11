/*
 * Copyright 2016 <copyright holder> <email>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef GRIDACCESS_H
#define GRIDACCESS_H

#include <stdexcept>
#include <algorithm>
#include <utility>
#include <vector>
#include "../Coordinates.h"
using namespace std;

class GridAccess
{
private:
    const bool HexagonGrid[3][3];
    struct DirectionCoord
    {
        BowDirections::Directions PointingDirection;
        int yPos, xPos;
        DirectionCoord(BowDirections::Directions dir, int y, int x) :
            PointingDirection(dir), yPos(y), xPos(x) {}

        bool operator==(BowDirections::Directions Direction)
        {
            return PointingDirection == Direction;
        }
    };
    vector<DirectionCoord> BowArrowDir;

    bool IsValidRange(int yPos, int xPos);
public:
    GridAccess();

    pair<int, int> MoveDestinationCoords( pair<int, int> source, BowDirections::Directions ArrowPoint );
    bool IsLegalMove( pair<int, int> source, BowDirections::Directions ArrowPoint);
};


#endif // GRIDACCESS_H
