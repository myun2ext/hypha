#include "myun2/packdb/packdb.hpp"

using namespace myun2::packdb;

int main()
{
	file f("test.db");
	pack<file> p(f);

	p.write("aaa",3);

	return 0;
}
