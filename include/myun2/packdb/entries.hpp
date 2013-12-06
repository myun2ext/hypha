#ifndef __github_com_myun2__packdb__entries_HPP__
#define __github_com_myun2__packdb__entries_HPP__

#include <vector>

namespace myun2
{
	namespace packdb
	{
		template <typename T, typename EntryIdType=unsigned int>
		class entries
		{
		private:
			typedef T Impl;
			typedef EntryIdType eid_type;
			T& impl;

			::std::vector<eid_type> eids;
		public:
			entries(Impl& i) : impl(i) {}
		};
	}
}

#endif//__github_com_myun2__packdb__entries_HPP__
