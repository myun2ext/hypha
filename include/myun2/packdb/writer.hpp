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
			typedef T Impl;
			T& impl;
		public:
			writer(Impl& i) : impl(i) {}

			long write(const void* p, unsigned int length) {
				impl.seek_to_last();
				return impl.write(p, length);
			}
		};
	}
}

#endif//__github_com_myun2__packdb__writer_HPP__
