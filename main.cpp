


#include <iostream>
using namespace std;
#include "DrawPart/Visualizer.h"
#include "AlgoPart/HexagonTileControler.h"
#include "ControlPanel.h"

namespace RawInput
{
  enum eMenuButtons
  {
	NewGame, Pause, Statistic, Help, Exit
  };
  
  enum eHexMapTile
  {
    LeftTop,
    LeftDown,
    Top,
    Center,
    Down,
    RightTop,
    RightDown,
    HexTileCount
  };
  
  enum eBowConfig
  {
	TurnToLeft, TurnToRight, Move
  };
  
  const int NON_VALUE = 0;
};

struct RawInputHandler
{
   template<class RAWINPUT>
   RAWINPUT GetInput()
   {
	 
	 
   };
};

int main(int argc, char **argv)
{
    Visualizer m_Visualizer;
    ControlPanel m_Panel;
	
    bool bGameRunning = true;
    while(bGameRunning)
    {
        SDL_Event m_Event;
        while(SDL_PollEvent(&m_Event))
        {
//          m_Panel.HandleInput();
        }
        m_Visualizer.UpdateScene();
    }
    return 0;
}










