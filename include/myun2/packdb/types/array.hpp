#ifndef __github_com_myun2__packdb__types__array_HPP__
#define __github_com_myun2__packdb__types__array_HPP__

#include <vector>

namespace myun2
{
	namespace packdb
	{
		namespace types
		{
			template <typename T>
			class array
			{
			private:
				::std::vector<T> value;
			public:
				array(){}

				const void* serialize_value() const { return &value.begin(); }
				unsigned int size() const { return value.size() * sizeof(T); }
			};
		}
	}
}

#endif//__github_com_myun2__packdb__types__array_HPP__
