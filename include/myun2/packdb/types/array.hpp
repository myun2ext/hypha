#ifndef __github_com_myun2__packdb__types__array_HPP__
#define __github_com_myun2__packdb__types__array_HPP__

#include <vector>

namespace myun2
{
	namespace packdb
	{
		namespace types
		{
			template <typename T, unsigned int _BlockSize=128>
			class array
			{
			private:
				::std::vector<T> value;
				static const int item_size = sizeof(T);
			public:
				array(){}

				const void* serialize_value() const { return value.begin(); }
				unsigned int size() const { return value.size(); }
				unsigned int data_size() const { return size() * item_size; }

				template <typename _Writer>
				void serialize(_Writer& writer)
				{
				}

				void read_serialized(const void* s, unsigned int size) {
				}
			};
		}
	}
}

#endif//__github_com_myun2__packdb__types__array_HPP__
