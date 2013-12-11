#ifndef __github_com_myun2__mycelium__colony_HPP__
#define __github_com_myun2__mycelium__colony_HPP__

#include <memory.h>

namespace myun2
{
	namespace mycelium
	{
		template <typename _Location>
		class colony
		{
		private:
			_Location location;
		public:
			colony(_Location& locate) : location(locate) {}
			virtual ~colony(){}
		};
	}
}

#endif//__github_com_myun2__mycelium__colony_HPP__
