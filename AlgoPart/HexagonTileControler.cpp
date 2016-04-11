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

#include "HexagonTileControler.h"

HexagonTileControler::HexagonTileControler()
{
    HexTileContainer.push_back( HexTile(HexagonTiles::Top, 		 0, 1) );
    HexTileContainer.push_back( HexTile(HexagonTiles::LeftTop, 	 0, 0) );
    HexTileContainer.push_back( HexTile(HexagonTiles::RightTop,  0, 2) );
    HexTileContainer.push_back( HexTile(HexagonTiles::Center, 	 1, 1) );
    HexTileContainer.push_back( HexTile(HexagonTiles::LeftDown,  1, 0) );
    HexTileContainer.push_back( HexTile(HexagonTiles::RightDown, 1, 2) );
    HexTileContainer.push_back( HexTile(HexagonTiles::Down, 	 2, 1) );
}

void HexagonTileControler::SelectTile( HexagonTiles::Tiles TileName)
{
    for(int i = 0; i < HexTileContainer.size(); i++)
    {
        HexTileContainer[i].IsTileSelected = false;
        if(HexTileContainer[i].HexagonTileName.TileName == TileName)
        {
            HexTileContainer[i].IsTileSelected = true;
        }
    }
}

HexTile* HexagonTileControler::GetSelectedTile()
{
    for(int i = 0; i < HexTileContainer.size(); i++)
    {
        if(HexTileContainer[i].IsTileSelected)
        {
            return &HexTileContainer[i];
        }
    }
    return nullptr;
}


void HexagonTileControler::MoveBowTo(HexagonTiles::Tiles Destination)
{
    auto SelectedTile = GetSelectedTile();
    if( SelectedTile == nullptr)
    {
        cout <<"ERROR: You havent select any tile :) \n";
    }
    if(!SelectedTile->IsBowOnTile )
    {
        cout <<"ERORR: Bow doesn't exists \n";
    }

    int sourceY = SelectedTile->HexagonTileName.yPos;
    int sourceX = SelectedTile->HexagonTileName.xPos;

    bool IsMovePossible = false;
    for(auto it : SelectedTile->GetBowDirections())
    {
        if( AccessControler.IsLegalMove(make_pair(sourceY, sourceX), it) )
        {
            auto TileNameIndex = AccessControler.MoveDestinationCoords(make_pair(sourceY, sourceX), it);

            HexagonTiles::Tiles TileName;
            for(int i = 0; i < HexTileContainer.size(); i++)
            {
                if(TileNameIndex.first == HexTileContainer[i].HexagonTileName.yPos &&
                        TileNameIndex.second == HexTileContainer[i].HexagonTileName.xPos)
                {
                    TileName = HexTileContainer[i].HexagonTileName.TileName;
                    break;
                }
            }

            if(TileName == Destination)
            {
                IsMovePossible = true;
                SelectTile(Destination);
                cout << "GOOD - you move succesffully\n";
                break;
            }
        }
    }

    if(IsMovePossible == false)
    {
        cout << "You can not move there \n";
    }
}
void HexagonTileControler::HandleInput()
{
    /*Which Tile is clicked ?*/
    int input = 0;
    cin >> input;
    cin.ignore();

    switch( input )
    {
    case 1:
        SelectTile( HexagonTiles::Top );
        break;
    case 2:
        SelectTile( HexagonTiles::LeftTop );
        break;
    case 3:
        SelectTile( HexagonTiles::RightTop );
        break;
    case 4:
        SelectTile( HexagonTiles::Center );
        break;
    case 5:
        SelectTile( HexagonTiles::LeftDown );
        break;
    case 6:
        SelectTile( HexagonTiles::RightDown );
        break;
    case 7:
        SelectTile( HexagonTiles::Down );
        break;
    case 8:
    {
        auto SelectedTile = GetSelectedTile();
        if(SelectedTile == nullptr)
        {
            cout << "No tile selected \n";
            return;
        }

        cout << "Current arrow is: ";
        switch( SelectedTile->HexagonTileName.TileName )
        {
        case   HexagonTiles::Top:
            cout << " Top \n";
            break;
        case   HexagonTiles::LeftTop:
            cout << " LeftTop \n";
            break;
        case   HexagonTiles::RightTop:
            cout << " RightTop \n";
            break;
        case   HexagonTiles::Center:
            cout << " Center \n";
            break;
        case   HexagonTiles::LeftDown:
            cout << " LeftDown \n";
            break;
        case   HexagonTiles::RightDown:
            cout << " RightDown \n";
            break;
        case   HexagonTiles::Down:
            cout << " Down \n";
            break;
        default:
            break;
        }
        break;
    }
    case 9:
    {
        auto SelectedTile = GetSelectedTile();
        if( SelectedTile != nullptr )
        {
            SelectedTile->AddBow();
            cout << "Bow added \n";
        }
        else
        {
            cout <<"ERROR: You havent select any tile :) \n";
        }
        break;
    }

    case 10:
        cout << " Try move to HexagonTiles::Top, 		 \n";
        MoveBowTo(HexagonTiles::Top);
        break;
    case 11:
        cout << " Try move to HexagonTiles::LeftTop, 	 \n";
        MoveBowTo(HexagonTiles::LeftTop);
        break;
    case 12:
        cout << " Try move to HexagonTiles::RightTop,  \n";
        MoveBowTo(HexagonTiles::RightTop);
        break;
    case 13:
        cout << " Try move to HexagonTiles::Center, 	 \n";
        MoveBowTo(HexagonTiles::Center);
        break;
    case 14:
        cout << " Try move to HexagonTiles::LeftDown,  \n";
        MoveBowTo(HexagonTiles::LeftDown);
        break;
    case 15:
        cout << " Try move to HexagonTiles::RightDown, \n";
        MoveBowTo(HexagonTiles::RightDown);
        break;
    case 16:
        cout << " Try move to HexagonTiles::Down, 	 \n";
        MoveBowTo(HexagonTiles::Down);
        break;
    case 17:
    {
        cout << " Clear selected tiles \n";
        for(int i = 0; i < HexTileContainer.size(); i++)
        {
            HexTileContainer[i].IsTileSelected = false;
        }
        break;
    }
    case 18:
    {

        auto SelectedTile = GetSelectedTile();
        if( SelectedTile == nullptr)
        {
            cout << "ERROR: You havent select any tile :) \n";
        }
        if(!SelectedTile->IsBowOnTile )
        {
            cout << "ERORR: Bow doesn't exists \n";
        }

        cout << "Before Rotating Arrow to Right \n";
        printBow();
        SelectedTile->RotateBowToRight();
        cout << "After  Rotating Arrow to Right \n";
        printBow();
        break;
    }

    case 19:
    {

        auto SelectedTile = GetSelectedTile();
        if( SelectedTile == nullptr)
        {
            cout << "ERROR: You havent select any tile :) \n";
        }
        if(!SelectedTile->IsBowOnTile )
        {
            cout << "ERORR: Bow doesn't exists \n";
        }
        cout << " Current bow arow directions are: ";
        printBow();
        break;
    }
    default :
        break;
    }


}

void HexagonTileControler::printBow()
{
    auto SelectedTile = GetSelectedTile();
    auto bowDirections = SelectedTile->GetBowDirections();
    for(int i = 0; i < bowDirections.size(); i++)
    {
        switch( bowDirections[i] )
        {
        case BowDirections::Top:
            cout <<" BowDirections::Top";
            break;
        case BowDirections::TopLeft:
            cout <<" BowDirections::TopRight";
            break;
        case BowDirections::TopRight:
            cout <<" BowDirections::TopRight";
            break;
        case BowDirections::Down:
            cout <<" BowDirections::Down";
            break;
        case BowDirections::DownLeft:
            cout <<" BowDirections::DownLeft";
            break;
        case BowDirections::DownRight:
            cout <<" BowDirections::DownRight";
            break;
        default:
            break;
        }
    }
    cout << endl;
}
