


#ifndef ARROWFACTORY_H
#define ARROWFACTORY_H

#include "../Config/Utility.h"
#include "Arrow.h"

namespace arrow {
namespace factory {
  
	/*std::unique_ptr<Arrow> CreateArrow(AD::type::EType ArrowType, hexagon::ETiles TileName)
	{
		return utility::make_unique<Arrow>(ArrowType, TileName);
	}*/
	
	Arrow CreateArrow(AD::type::EType ArrowType, hexagon::ETiles TileName)
	{
		return Arrow(ArrowType, TileName);
	}
}} // Arrow::Factory


#endif // ARROWFACTORY_H
