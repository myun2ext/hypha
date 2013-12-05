#ifndef __github_com_myun2__packdb__writer_HPP__
#define __github_com_myun2__packdb__writer_HPP__

namespace myun2
{
	namespace packdb
	{
		template <typename T>
		class writer
		{
		private:
			T& impl;
		public:
			writer(impl& i) : impl(i) {}
		};
	}
}

#endif//__github_com_myun2__packdb__writer_HPP__
