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

#ifndef ARROW_H
#define ARROW_H

#include <vector>
#include "../Config/ArrowDefinitions.h"
#include "../Config/HexagonDefinitions.h"

namespace arrow{
class Arrow
{
private:
	std::vector<AD::direction::EDirections> m_ArrowDirections;
	hexagon::ETiles m_HisTileName;
	
	template<typename First = AD::direction::EDirections, typename... Args>
    void AddDirections(First ArgumentOne, Args... Remainder);
	
	AD::direction::EDirections GetDirectionToRight(AD::direction::EDirections CurrentDirection);
	
public:
	Arrow(AD::type::EType ArrowType, hexagon::ETiles TileName);
    ~Arrow();
	
	void RotateArrowLeft();
	void RotateArrowRight();
	
	hexagon::ETiles GetArrowOnTile() const;
	std::vector<AD::direction::EDirections> GetArrowDirections() const;
};
} // arrow
#endif // ARROW_H
