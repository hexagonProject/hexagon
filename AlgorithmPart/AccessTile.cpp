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

#include "AccessTile.h"
#include <stdexcept>
AccessTile::AccessTile() : 
HexagonMap 
{
  {1,1,1},
  {1,1,1},
  {0,1,0}
}{}

bool AccessTile::IsOnBounds(int yPos, int xPos)
{
    bool OnBounds = false;

    if (yPos >= 0 && yPos <= 2)
    {
        OnBounds = true;
    }

    if(xPos >= 0 && xPos <= 2)
    {
        OnBounds = true;
    }
  
	OnBounds = HexagonMap[yPos][xPos];
	
    return (OnBounds);
}

AccessTile::HexMapIndexes AccessTile::GetIndexesByArrowDir(arrow::definitions::direction::EDirections ArrowDir)
{
	HexMapIndexes DestinationIndexes = {0, 0};
	
	switch( ArrowDir )
	{
	  case AD::direction::Top: 			{ DestinationIndexes = {-1, 0};   break; }
	  case AD::direction::TopLeft: 		{ DestinationIndexes = {-1, -1};  break; }
	  case AD::direction::TopRight: 	{ DestinationIndexes = {-1, +1};  break; }
	  case AD::direction::Down: 		{ DestinationIndexes = {+1, 0};   break; }
	  case AD::direction::DownLeft: 	{ DestinationIndexes = {0, -1};   break; }
	  case AD::direction::DownRight: 	{ DestinationIndexes = {0, +1};   break; }
	  default: { throw std::logic_error( " AccessTile - GetIndexesByArrowDir = Invalid direction" ); break; }
	};
	
	return (DestinationIndexes);
}

AccessTile::HexMapIndexes AccessTile::GetIndexesByTile(hexagon::ETiles TileName)
{
	HexMapIndexes SourceIndexes = {0, 0};
	
	switch( TileName )
	{
	  case hexagon::Top: 		{ SourceIndexes = {0, 1};   break; }
	  case hexagon::LeftTop: 	{ SourceIndexes = {0, 0};   break; }
	  case hexagon::RightTop: 	{ SourceIndexes = {0, 2};   break; }
	  case hexagon::Center: 	{ SourceIndexes = {1, 1};   break; }
	  case hexagon::LeftDown: 	{ SourceIndexes = {1, 0};   break; }
	  case hexagon::RightDown: 	{ SourceIndexes = {1, 2};   break; }
	  case hexagon::Down: 		{ SourceIndexes = {2, 1};   break; }
	  default: { throw std::logic_error( " AccessTile - GetIndexesByTile = Invalid TileName" ); break; }
	};
	
	return (SourceIndexes);
}

bool AccessTile::IsPossibleMove(const arrow::Arrow& Source, hexagon::ETiles DestinationTileName)
{
  //TODO(Fer) - NOT WORKING
	bool PossibleMove = false;
	
	auto SourceTileName = Source.GetArrowOnTile();
	auto SourceArrowDir = Source.GetArrowDirections();
	
	for( const auto &it : SourceArrowDir )
	{
		int movedYPos = GetIndexesByTile( SourceTileName ).xPos + GetIndexesByArrowDir(it).xPos;
		int movedXPos = GetIndexesByTile( SourceTileName ).yPos + GetIndexesByArrowDir(it).yPos;
		
        if( IsOnBounds(movedYPos, movedXPos) )
        {
            PossibleMove = true;
            break;
        }
	}
	
	return (PossibleMove);
}
