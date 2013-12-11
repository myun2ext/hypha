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
				string(const ::std::string& s) {
					assign(s.c_str(), s.size());
				}
				string(const char* s) {
					assign(s);
				}

				void assign(const char* s, unsigned int length) {
					write_bulk(s, length);
				}
				void assign(const char* s) {
					write_bulk(s, strlen(s));
				}
			};
		}
	}
}

#endif//__github_com_myun2__mycelium__types__string_HPP__
