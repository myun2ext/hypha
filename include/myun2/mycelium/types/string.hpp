#ifndef __github_com_myun2__mycelium__types__string_HPP__
#define __github_com_myun2__mycelium__types__string_HPP__

#include "myun2/mycelium/hypha.hpp"
#include <string>
#include <string.h>

namespace myun2
{
	namespace mycelium
	{
		namespace types
		{
			class string : public hypha<char, 0x02, 128 - 4>
			{
			private:
				typedef hypha<char, 0x02, 128 - 4> _Base;
			public:
				string(){}
				string(const ::std::string& s) { set(s); }
				string(const char* s) { set(s); }

				void set(const ::std::string& s) {
					write_bulk(s.c_str(), s.size() + 1);
				}
				void set(const char* s, unsigned int length) {
					write_bulk(s, length + 1);
				}
				void set(const char* s) {
					write_bulk(s, strlen(s) + 1);
				}

				const char* c_str() const { return data(); }

				unsigned int size() const { return (_Base::size() == 0 ? 0 : _Base::size() - 1); }
				unsigned int length() const { return size(); }
			};
		}
	}
}

#endif//__github_com_myun2__mycelium__types__string_HPP__
