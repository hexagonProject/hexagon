


#ifndef UTILITY_H
#define UTILITY_H

#include <memory>
namespace utility {
  
  	template<typename T, typename ...Args>
	std::unique_ptr<T> make_unique( Args&& ...args )
	{
		return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
	}
  
};


#endif // UTILITY_H