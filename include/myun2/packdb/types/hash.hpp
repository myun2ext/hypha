#ifndef __github_com_myun2__packdb__types__hash_HPP__
#define __github_com_myun2__packdb__types__hash_HPP__

#include <map>

namespace myun2
{
	namespace packdb
	{
		namespace types
		{
			template <typename _KeyT, typename _ValueT>
			class hash
			{
			private:
				::std::map<_KeyT, _ValueT> value;
			};
		}
	}
}

#endif//__github_com_myun2__packdb__types__hash_HPP__
