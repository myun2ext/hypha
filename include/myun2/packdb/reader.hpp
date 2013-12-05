#ifndef __github_com_myun2__packdb__reader_HPP__
#define __github_com_myun2__packdb__reader_HPP__

namespace myun2
{
	namespace packdb
	{
		template <typename T>
		class reader
		{
		private:
			T& impl;
		public:
			reader(impl& i) : impl(i) {}
		};
	}
}

#endif//__github_com_myun2__packdb__reader_HPP__
