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

#include "Arrow.h"
#include <stdexcept>

namespace arrow {

template<typename First, typename... Args>
void Arrow::AddDirections(First ArgumentOne, Args... Remainder)
{
	/*TODO(Fer) - If Owner is EnemyPlayer -> Mirror Arguments eg: Down -> Top.*/
	for (First it : { ArgumentOne, Remainder... })
	{
		m_ArrowDirections.push_back(it);
	}
}

AD::direction::EDirections Arrow::GetDirectionToRight(AD::direction::EDirections CurrentDirection)
{
	  AD::direction::EDirections NextDirection = CurrentDirection;
	  
	  switch( CurrentDirection )
	  {
		case AD::direction::Top:		 { NextDirection =  AD::direction::TopRight;  break; }
		case AD::direction::TopRight:	 { NextDirection =  AD::direction::DownRight; break; }
		case AD::direction::TopLeft: 	 { NextDirection =  AD::direction::Top; 	  break; }
		case AD::direction::Down: 		 { NextDirection =  AD::direction::DownLeft;  break; }
		case AD::direction::DownLeft: 	 { NextDirection =  AD::direction::TopLeft;   break; }
		case AD::direction::DownRight: 	 { NextDirection =  AD::direction::Down; 	  break; }
		default: { throw std::logic_error( " This Arrow Directions doesn't exists, at GetDirectionToRight Function" ); break; }
	  }
	  return (NextDirection);
}

Arrow::~Arrow() {}
Arrow::Arrow(definitions::type::EType ArrowType, hexagon::ETiles TileName)
{
	m_HisTileName = TileName;
	
	using namespace AD::direction;  /* Arrow::Definitions::EDirections */
	using namespace AD::type; 		/* Arrow::Definitions::EType*/

	switch( ArrowType )
	{
	  case OnePoint:   	 { AddDirections(Down); break; }
                               
	  case TwoPointV1: 	 { AddDirections(Down, DownRight);		break; }
	  case TwoPointV2: 	 { AddDirections(Down, TopRight);		break; }
	  case TwoPointV3: 	 { AddDirections(Down, Top); 			break; }
                           
	  case ThreePointV1: { AddDirections(Down, DownRight, TopRight);		 break; }
	  case ThreePointV2: { AddDirections(Down, DownRight, Top);          	 break; }
	  case ThreePointV3: { AddDirections(Down, TopRight, Top);           	 break; }
	  case ThreePointV4: { AddDirections(Down, DownLeft, DownRight);      	 break; }
                           
	  case FourPointV1:	 { AddDirections(Down, DownRight, TopRight, Top);            break; }
	  case FourPointV2:  { AddDirections(Down, DownRight, DownLeft, Top);            break; }
	  case FourPointV3:  { AddDirections(Down, Top, DownRight, TopLeft);             break; }
                           
	  case FivePoint: 	 { AddDirections(Down, DownLeft, DownRight, TopLeft, TopRight);         break; }
	  case SixPoint: 	 { AddDirections(Down, DownLeft, DownRight, TopLeft, TopRight, Top);    break; }

	  default: { throw std::logic_error( " This ArrowType doesn't exists, at Arrow class constructor" ); break; }
	};
}

void Arrow::RotateArrowLeft()
{
	RotateArrowRight();
	RotateArrowRight();
	RotateArrowRight();
}

void Arrow::RotateArrowRight()
{
    for(auto &it : m_ArrowDirections)
    {
        it = GetDirectionToRight(it);
    }
}

hexagon::ETiles Arrow::GetArrowOnTile() const
{
	return m_HisTileName;
}

std::vector< AD::direction::EDirections > Arrow::GetArrowDirections() const
{
    return m_ArrowDirections;
}

} // arrow
