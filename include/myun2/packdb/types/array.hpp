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
				typedef ::std::vector<T> vector_t;
				vector_t value;
				static const int item_size = sizeof(T);
			public:
				array(){}

				const T* data() const { return &value.begin(); }
				const void* serialize_value() const { return &value.begin(); }
				unsigned int size() const { return value.size(); }
				unsigned int data_size() const { return size() * item_size; }

				template <typename _Writer>
				void serialize(_Writer& writer)
				{
					writer.write(size(), sizeof(unsigned int));
					writer.write(serialize_value(), data_size());
				}

				void read_serialized(const void* s, unsigned int size) {
					//value = vector_t((const T*)s, (const T*)(s + size));
					value.assign((const T*)s, (const T*)(s + size));
				}

				T& operator [] (unsigned int i) {
					return value[i]; }
				const T& operator [] (unsigned int i) const {
					return value[i]; }

				void append(const T& v) { value.push_back(v); }
			};
		}
	}
}

#endif//__github_com_myun2__packdb__types__array_HPP__
