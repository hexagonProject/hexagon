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

#include "IMenuButtons.h"


IMenuButtons::IMenuButtons(SDL_Surface* m_Surface) : IBaseVisualizer(m_Surface) {}
IMenuButtons::~IMenuButtons() {}

void  IMenuButtons::OnInit() 
{

};

void  IMenuButtons::OnDraw()
{
    for(int it = 0; it < ICoordinates::eMenuButtons.size(); it++)
    {
        SDL_FillRect(m_Surface, &ICoordinates::eMenuButtons.at(it),
                     SDL_MapRGB(m_Surface->format, 255, 0, 0));
    }
    
    for(int it = 0; it < ICoordinates::eBowMenuButtons.size(); it++)
	{
	  SDL_FillRect(m_Surface, &ICoordinates::eBowMenuButtons.at(it),
					  SDL_MapRGB(m_Surface->format, 0, 255, 0));
	}
};
