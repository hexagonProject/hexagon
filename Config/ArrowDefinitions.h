

#ifndef ARROWDEFINITION_H
#define ARROWDEFINITION_H

namespace arrow{
namespace definitions{
  
namespace direction{
  
enum EDirections
{
	/*0*/Top, 
	/*1*/TopLeft, 
	/*2*/TopRight, 
	/*3*/Down, 
	/*4*/DownLeft, 
	/*5*/DownRight,
	
	DirectionSize
};
} /* Direction */
	
namespace type{
  
enum EType
{ 
  OnePoint,
  
  TwoPointV1, 
  TwoPointV2, 
  TwoPointV3,
  
  ThreePointV1, 
  ThreePointV2,
  ThreePointV3, 
  ThreePointV4,
  
  FourPointV1, 
  FourPointV2, 
  FourPointV3,
  
  FivePoint,
  SixPoint,
  
  TypeSize
};
} /* Type */

}} /*Arrow::Definitions*/
 
namespace AD = arrow::definitions;

#endif // ARROWDEFINITION_H