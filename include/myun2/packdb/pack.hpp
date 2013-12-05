#ifndef __github_com_myun2__packdb__pack_HPP__
#define __github_com_myun2__packdb__pack_HPP__

#include "myun2/packdb/reader.hpp"
#include "myun2/packdb/writer.hpp"

namespace myun2
{
	namespace packdb
	{
		template <typename T>
		class pack : public writer<T>
		{
		private:
			typedef T Impl;
			T impl;
		public:
			pack() : writer<T>(impl) {}
			pack(const Impl& i) : impl(i), writer<T>(impl) {}
		};
	}
}

#endif//__github_com_myun2__packdb__pack_HPP__
