#include "myun2/packdb/packdb.hpp"

using myun2::packdb::types::array;

void array_test_of_bytes()
{
	array<char> a;

	a.append(1);
	printf("a[0]: %d\n", a[0]);
	printf("a.size(): %d\n", a.size());
	a.append(3);
	printf("a[1]: %d\n", a[1]);
	printf("a.size(): %d\n", a.size());

//	const void* serialized = a.serialize();
	
	::std::vector<int> aaa;
	aaa.push_back(3);
	printf("%d\n", *aaa.begin());
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
