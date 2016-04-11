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

#ifndef IHEXAGONMAP_H
#define IHEXAGONMAP_H

#include "IBaseVisualizer.h"
#include "ResourceLoader.h"

class IHexagonMap : public IBaseVisualizer
{
private:
    ResourceLoader m_ResourceMgr;
    SDL_Surface* pic_HexTile;
    SDL_Surface* pic_HexTileSelected;
public:
    IHexagonMap(SDL_Surface* &m_mainSurface);
    virtual ~IHexagonMap();

    void OnInit();

    virtual void OnDraw() override;
};


#endif // IHEXAGONMAP_H
