#ifndef __github_com_myun2__packdb__types__array2_HPP__
#define __github_com_myun2__packdb__types__array2_HPP__

namespace myun2
{
	namespace packdb
	{
		namespace types
		{
			template <typename T, unsigned int _BlockSize=32>
			class array2
			{
			private:
				unsigned T* p_allocated;
				unsigned int used;

				void allocate() { p_allocated = new T [_BlockSize]; }
				void deallocate() { delete[] p_allocated; }

				void used_countup() { used++; }
			public:
				array2() : p_allocated(0), used(0) { allocate(); }
				virtual ~array2() { deallocate(); }

				const T* data() const { return p_allocated; }
				const void* serialize_value() const { return data(); }
				unsigned int size() const { return used; }
				unsigned int data_size() const { return size() * sizeof(T); }

				T& at(unsigned int i) { return p_allocated[i + 1]; }
				const T& at(unsigned int i) const { return p_allocated[i + 1]; }
				T& tail() { return at(used); }
				const T& tail() const { return at(used); }

				const void* serialized() const {
					p_allocated[0] = size();
					return data();
				}

				void read_serialized(const void* s, unsigned int size) {
					//value = vector_t((const T*)s, (const T*)(s + size));
					value.assign((const T*)s, (const T*)(s + size));
				}

				T& operator [] (unsigned int i) {
					return at(i); }
				const T& operator [] (unsigned int i) const {
					return at(i); }

				bool append(const T& v) {
					if ( used+1 == _BlockSize )
						return false;
					used_countup();
					tail() = v;
					return true;
				}
			};
		}
	}
}

#endif//__github_com_myun2__packdb__types__array2_HPP__
