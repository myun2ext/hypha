#ifndef __github_com_myun2__packdb__pack_HPP__
#define __github_com_myun2__packdb__pack_HPP__

namespace myun2
{
	namespace packdb
	{
		template <typename T>
		class pack
		{
		private:
			typedef T Impl;
			T impl;
		public:
			pack(){}
			pack(const Impl& i) : impl(i) {}
		};
	}
}

#endif//__github_com_myun2__packdb__pack_HPP__
