#ifndef __github_com_myun2__mycelium__conidium_HPP__
#define __github_com_myun2__mycelium__conidium_HPP__

namespace myun2
{
	namespace mycelium
	{
		template <typename T, unsigned char _TypeCode>
		class conidium
		{
		private:
			typedef struct indata_type {
				unsigned char code;
				unsigned char subcode;
				unsigned char _reserv1;
				unsigned char _reserv2;
				T data;

				indata_type() {
					code = _TypeCode;
					subcode = 0;
					_reserv1 = 0;
					_reserv2 = 0;
				}
			} indata_t;
			indata_t indata;
		public:
			conidium(){}
			virtual ~conidium(){}

			indata_type* internal() { return &indata; }
			const indata_type* internal() const { return &indata; }

			T& data() { return indata.data; }
			const T& data() const { return indata.data; }
			const void* serialize_value() const { return &data(); }
			unsigned int size() const { return 1; }
			unsigned int data_size() const { return sizeof(T); }

			const void* serialize() const {
				return &indata;
			}
			void read_serialized(const void* s, unsigned int size) {
				memcpy(&indata, s, size);
			}
			void write(const void* s, unsigned int size) {
				memcpy(data(), s, size);
			}

			operator T& () { return data(); }
			operator const T& () const { return data(); }
		};
	}
}

#endif//__github_com_myun2__mycelium__conidium_HPP__
