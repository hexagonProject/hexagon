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

#ifndef HEXTILE_H
#define HEXTILE_H
#include "GridAccess.h"
#include "Bow.h"
class HexTile
{
private:
	struct TileCoord
	{
		HexagonTiles::Tiles TileName;
		int yPos, xPos;
		TileCoord() {}
		TileCoord(HexagonTiles::Tiles mainSrc, int y, int x) :
			TileName(mainSrc), yPos(y), xPos(x) {}

		bool operator==(HexagonTiles::Tiles Tile)
		{
			return TileName == Tile;
		}
	};
    Bow m_Bow;
public:

    TileCoord HexagonTileName;
    bool IsBowOnTile;
    bool IsTileSelected;

    HexTile(HexagonTiles::Tiles mainSrc, int yPos, int xPos);

    void AddBow();
    void DeleteBow();
    void RotateBowToLeft();
    void RotateBowToRight();
	
    vector<BowDirections::Directions> GetBowDirections();
};


#endif // HEXTILE_H
