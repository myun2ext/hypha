#ifndef __github_com_myun2__mycelium__hypha_HPP__
#define __github_com_myun2__mycelium__hypha_HPP__

namespace myun2
{
	namespace mycelium
	{
		template <typename T, unsigned char _TypeCode, unsigned int _Size=31>
		class hypha
		{
		private:
			typedef struct indata_type {
				unsigned char code;
				unsigned char subcode;
				unsigned char _reserv1;
				unsigned char used;
				T data[_Size];

				indata_type() {
					code = _TypeCode;
					subcode = 0;
					_reserv1 = 0;
					used = 0;
				}
			} indata_t;
			indata_t indata;

			void used_countup() { indata.used++; }
		public:
			hypha(){}
			virtual ~hypha(){}

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

			const void* serialize() const {
				return &indata;
			}
			void read_serialized(const void* s, unsigned int size) {
				memcpy(&indata, s, size);
			}
			void set_datas(const void* s, unsigned int size) {
				memcpy(data(), s, size);
				indata.used = size / sizeof(T);
			}

			T& operator [] (unsigned int i) {
				return at(i); }
			const T& operator [] (unsigned int i) const {
				return at(i); }

			bool append(const T& v) {
				if ( size() == _Size )
					return false;
				tail() = v;
				used_countup();
				return true;
			}
		};
	}
}

#endif//__github_com_myun2__mycelium__hypha_HPP__
