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

#include "IHexagonMap.h"


IHexagonMap::IHexagonMap(SDL_Surface* &m_mainSurface) : IBaseVisualizer(m_mainSurface) {}
IHexagonMap::~IHexagonMap() {}

void IHexagonMap::OnInit()
{
//    pic_HexTile = m_ResourceMgr.GetPicture_PNG( "../Pictures/HexTile.png", m_Surface);
//    pic_HexTileSelected = m_ResourceMgr.GetPicture_PNG( "../Pictures/HexTileSelected.png", m_Surface );
	  pic_HexTile = IMG_Load("../Pictures/HexTile.png");
	  pic_HexTileSelected = IMG_Load("../Pictures/HexTileSelected.png");
};

void IHexagonMap::OnDraw()
{
    for(int it = 0; it < ICoordinates::eHexTile.size(); it++)
    {

        SDL_Rect HexTileRect =
        {
            ICoordinates::HEX_TILE_MAP.x + ICoordinates::eHexTile.at(it).x,
            ICoordinates::HEX_TILE_MAP.y + ICoordinates::eHexTile.at(it).y,
            ICoordinates::HEX_TILE_MAP.w + ICoordinates::eHexTile.at(it).w,
            ICoordinates::HEX_TILE_MAP.h + ICoordinates::eHexTile.at(it).h
        };

        SDL_BlitSurface( pic_HexTile, NULL, m_Surface, &HexTileRect );
    }
};
