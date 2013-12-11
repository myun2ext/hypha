#include <stdio.h>
#include "myun2/mycelium/hypha.hpp"
#include "myun2/mycelium/types/string.hpp"

using myun2::mycelium::hypha;
using myun2::mycelium::types::string;

void hypha_test()
{
	hypha<char, 3> a;

	printf("a.size(): %d\n", a.size());
	a.append(0x11);
	printf("a[0]: %d\n", a[0]);
	printf("a.size(): %d\n", a.size());
	a.append(0x22);
	printf("a[1]: %d\n", a[1]);
	printf("a.size(): %d\n", a.size());

	const unsigned int* serialized_ui = (const unsigned int*)a.serialize();
	printf("%08X\n", serialized_ui[0]);
	printf("%08X\n", serialized_ui[1]);
	printf("%08X\n", serialized_ui[2]);
}

void string_test()
{

}

int main()
{
	hypha_test();
	string_test();

	return 0;
}
