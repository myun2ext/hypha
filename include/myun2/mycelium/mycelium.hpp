#ifndef __github_com_myun2__mycelium__mycelium_HPP__
#define __github_com_myun2__mycelium__mycelium_HPP__

#include <memory.h>

namespace myun2
{
	namespace mycelium
	{
		template <typename _Location>
		class mycelium
		{
		private:
			_Location location;
			unsigned int occupied;
		public:
			mycelium(_Location& locate) : location(locate) {}
			virtual ~mycelium() : occupied(0) {}

			void grow(){
				occupied++;
			}
		};
	}
}

#endif//__github_com_myun2__mycelium__mycelium_HPP__
