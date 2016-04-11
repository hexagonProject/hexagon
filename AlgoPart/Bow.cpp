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

#include "Bow.h"


Bow::Bow() {}

void Bow::RotateBowToLeft()
{
    RotateBowToRight();
    RotateBowToRight();
    RotateBowToRight();
}

void Bow::RotateBowToRight()
{
    for(int i = 0; i < BowArrowDirections.size(); i++)
    {
        switch( BowArrowDirections[i] )
        {
        case BowDirections::Top:
            BowArrowDirections[i] = BowDirections::TopRight;
            break;
        case BowDirections::TopLeft:
            BowArrowDirections[i] = BowDirections::Top;
            break;
        case BowDirections::TopRight:
            BowArrowDirections[i] = BowDirections::DownRight;
            break;
        case BowDirections::Down:
            BowArrowDirections[i] = BowDirections::DownLeft;
            break;
        case BowDirections::DownLeft:
            BowArrowDirections[i] = BowDirections::TopLeft;
            break;
        case BowDirections::DownRight:
            BowArrowDirections[i] = BowDirections::Down;
            break;
        default:
            break;
        }
    }
}

void Bow::CreateBow(BowTypes::Types BowType)
{
    /*Do not call twice this function*/
    if(!BowArrowDirections.empty())
    {
//         cout << "ERROR bow arrow direction is already created\n";
        return;
    }

    switch( BowType )
    {
    case BowTypes::OnePoint:
    {
        BowArrowDirections.push_back( BowDirections::Top );
        break;
    }
    case BowTypes::TwoPointV1:
    {
        BowArrowDirections.push_back( BowDirections::DownRight );
        BowArrowDirections.push_back( BowDirections::Down );
        break;
    }
    default:
        break;
    }
}

vector<BowDirections::Directions> Bow::GetBowDirections()
{
    return BowArrowDirections;
}

