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

#ifndef ACCESSTILE_H
#define ACCESSTILE_H

#include "Arrow.h"
#include "../Config/HexagonDefinitions.h"

class AccessTile
{
private:
   struct HexMapIndexes
   {
	  int yPos, xPos;
   };
   
   const bool HexagonMap[3][3];
   bool IsOnBounds(int yPos, int xPos);
   
   HexMapIndexes GetIndexesByTile(hexagon::ETiles TileName);
   HexMapIndexes GetIndexesByArrowDir(AD::direction::EDirections ArrowDir);
public:
	AccessTile();
	bool IsPossibleMove(const arrow::Arrow& Source, hexagon::ETiles DestinationTileName);
};

#endif // ACCESSTILE_H
