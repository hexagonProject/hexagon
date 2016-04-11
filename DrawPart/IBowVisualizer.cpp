






#include "IBowVisualizer.h"
#include "ResourceLoader.h"

IBowVisualizer::IBowVisualizer(SDL_Surface* &m_mainSurface) : IBaseVisualizer(m_mainSurface) {}
IBowVisualizer::~IBowVisualizer() {}

void IBowVisualizer::OnInit()
{
	IBowDirContainer.resize(BowDirections::DirectionCount);

	IBowDirContainer.at(BowDirections::Down) = IMG_Load( "../Pictures/Arrow/DownArrow.png" );
	IBowDirContainer.at(BowDirections::DownLeft) = IMG_Load( "../Pictures/Arrow/DownLeftArrow.png" );
	IBowDirContainer.at(BowDirections::DownRight) = IMG_Load( "../Pictures/Arrow/DownRightArrow.png" );
	IBowDirContainer.at(BowDirections::Top) = IMG_Load( "../Pictures/Arrow/TopArrow.png" );
	IBowDirContainer.at(BowDirections::TopLeft) = IMG_Load( "../Pictures/Arrow/TopLeftArrow.png" );
	IBowDirContainer.at(BowDirections::TopRight) = IMG_Load( "../Pictures/Arrow/TopRightArrow.png" );
};

void IBowVisualizer::OnDraw()
{
  
	for(int it = 0; it < IBowDirContainer.size(); it++)
	{
		 SDL_Rect ArrowDest = {ICoordinates::eHexTile.at(it).x + ICoordinates::HEX_TILE_MAP.x 
		   , ICoordinates::eHexTile.at(it).y + ICoordinates::HEX_TILE_MAP.y 
		   , 0, 0};
		 SDL_BlitSurface( IBowDirContainer.at(it), NULL, m_Surface, &ArrowDest );
	}
};
