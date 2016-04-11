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

#include "Visualizer.h"



void Visualizer::RefreshBackGround()
{
    SDL_FillRect(m_Surface, NULL, SDL_MapRGB(m_Surface->format, 233, 233, 233));
}

Visualizer::Visualizer()
{
    SDL_Init( SDL_INIT_VIDEO );
    IMG_Init( IMG_INIT_PNG );

    m_Window = SDL_CreateWindow(" Hexagon ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 640, NULL);
    m_Surface = SDL_GetWindowSurface(m_Window);

    IContainer.push_back( new IMenuButtons(m_Surface) );
    IContainer.push_back( new IHexagonMap(m_Surface) );
    IContainer.push_back( new IBowVisualizer(m_Surface) );

    for(int i = 0; i < IContainer.size(); i++)
    {
        IContainer[i]->OnInit();
    }
}

void Visualizer::UpdateScene()
{
    RefreshBackGround();
    for(int i = 0; i < IContainer.size(); i++)
    {
        IContainer[i]->OnDraw();
    }

    SDL_UpdateWindowSurface(m_Window);
}
