#include "myun2/packdb/types/array2.hpp"
#include "myun2/packdb/packdb.hpp"

using myun2::packdb::types::array2;

void array_test_of_bytes()
{
	array2<char, 3> a;

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

void array_test_of_integers()
{

}

int main()
{
	array_test_of_bytes();
	array_test_of_integers();

	return 0;
}
