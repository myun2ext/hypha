#ifndef __github_com_myun2__packdb__types__array2_HPP__
#define __github_com_myun2__packdb__types__array2_HPP__

namespace myun2
{
	namespace packdb
	{
		namespace types
		{
			template <typename T, unsigned int _Size=31>
			class array2
			{
			private:
				typedef struct indata_type {
					unsigned char code;
					unsigned char subcode;
					unsigned char _reserv1;
					unsigned char used;
					T data[_Size];

					indata_type() {
						code = 0;
						subcode = 0;
						_reserv1 = 0;
						used = 0;
					}
				} indata_t;
				indata_t indata;

				void used_countup() { indata.used++; }
			public:
				array2(){}
				virtual ~array2(){}

				indata_type* internal() { return &indata; }
				const indata_type* internal() const { return &indata; }

				const T* data() const { return indata.data; }
				const void* serialize_value() const { return data(); }
				unsigned int size() const { return indata.used; }
				unsigned int data_size() const { return size() * sizeof(T); }

				T& at(unsigned int i) { return indata.data[i]; }
				const T& at(unsigned int i) const { return indata.data[i]; }
				T& tail() { return at(size()); }
				const T& tail() const { return at(size()); }

				const void* serialized() const {
					return &indata;
				}

				void read_serialized(const void* s, unsigned int size) {
					memcpy(&indata, s, size);
				}

				T& operator [] (unsigned int i) {
					return at(i); }
				const T& operator [] (unsigned int i) const {
					return at(i); }

				bool append(const T& v) {
					if ( size() == _Size )
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
