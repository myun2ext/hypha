#ifndef __github_com_myun2__packdb__file_HPP__
#define __github_com_myun2__packdb__file_HPP__

#include <io.h>
#include <stdio.h>

namespace myun2
{
	namespace packdb
	{
		class file
		{
		private:
			FILE* fp;
		public:
			file() : fp(NULL) {}
			file(const char* filename) { open(filename); }
			~file() { /*fclose(fp);*/ }

			bool open(const char* filename) {
				if ( _access(filename, F_OK) == 0 ){
					fp = fopen(filename, "r+b");
				}
				else {
					fp = fopen(filename, "w+b");
				}
			}

			////////////

			size_t read(void* buf, size_t length) {
				return fread(buf, length, 1, fp);
			}

			size_t write(const void* p, size_t length) {
				return fwrite(p, length, 1, fp);
			}

			void seek_to(long pos) {
				fseek(fp, pos, SEEK_SET);
			}
			long current() const {
				return ftell(fp);
			}
			long seek_to_tail() {
				fseek(fp, 0, SEEK_END);
				return current();
			}
			long seek_to_last(){ return seek_to_tail(); }
			long seek_to_end(){ return seek_to_tail(); }
		};
	}
}

#endif//__github_com_myun2__packdb__file_HPP__
