#ifndef __github_com_myun2__packdb__entries_HPP__
#define __github_com_myun2__packdb__entries_HPP__

namespace myun2
{
	namespace packdb
	{
		template <typename T>
		class entries
		{
		private:
			typedef T Impl;
			T& impl;
		public:
			entries(Impl& i) : impl(i) {}
		};
	}
}

#endif//__github_com_myun2__packdb__entries_HPP__
