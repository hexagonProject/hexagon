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

#include "GridAccess.h"

GridAccess::GridAccess() :
  HexagonGrid
  {
    1, 1, 1,
    1, 1, 1,
    0, 1, 0
  }
{
																/*yPos, xPos*/
	BowArrowDir.push_back( DirectionCoord(BowDirections::Top, 		-1, 0  ));
	BowArrowDir.push_back( DirectionCoord(BowDirections::TopLeft, 	-1, -1 ));
	BowArrowDir.push_back( DirectionCoord(BowDirections::TopRight, 	-1, +1 ));
	BowArrowDir.push_back( DirectionCoord(BowDirections::Down, 		+1, 0  ));
	BowArrowDir.push_back( DirectionCoord(BowDirections::DownLeft, 	 0, -1 ));
	BowArrowDir.push_back( DirectionCoord(BowDirections::DownRight,  0, +1 ));
}

bool GridAccess::IsValidRange(int yPos, int xPos)
{
	bool InRangeX = (xPos >= 0 && xPos <= 2);
	bool InRangeY = ( yPos >= 0 && yPos <= 2 );

	bool IsValid = false;
	if(InRangeX && InRangeY)
	{
		IsValid = HexagonGrid[yPos][xPos];
	}

	return (IsValid);
}

pair<int, int> GridAccess::MoveDestinationCoords( pair<int, int> source, BowDirections::Directions ArrowPoint )
{
	/*Call this only if legal move is true :)*/
	if(IsLegalMove( source, ArrowPoint ) == false)
	{
		throw std::invalid_argument( "Try to access invalid index This is not legal move, at function MoveDestination \n" );
	}
	auto moveDir = find(BowArrowDir.begin(), BowArrowDir.end(), ArrowPoint);
	int destY = source.first + moveDir->yPos;
	int destX = source.second + moveDir->xPos;

	return make_pair(destY, destX);
}

bool GridAccess::IsLegalMove( pair<int, int> source, BowDirections::Directions ArrowPoint)
{
	int yPos = source.first;
	int xPos = source.second;

	auto moveDir = find(BowArrowDir.begin(), BowArrowDir.end(), ArrowPoint);
	int moveY = yPos + moveDir->yPos;
	int moveX = xPos + moveDir->xPos;

	bool IsLegal = false;
	if( IsValidRange( moveY, moveX ) )
	{
		IsLegal = true;
	}

	return (IsLegal);
}

