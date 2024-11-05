#include "ReverseSortedType.h"

int main() {
	ReverseSortedType<int> a;
	a.insertitem(2);
	a.insertitem(7);
	a.insertitem(10);
	a.insertitem(4);
	a.insertitem(8);
	a.print();
	std::cout << a.fRank(5) << std::endl;
	std::cout << a.bRank(5) << std::endl;
	ReverseSortedType<int> b;
	std::cout << b.fRank(5) << std::endl;
	std::cout << b.fRank(5) << std::endl;
	std::cout << a.bRank(-1) << std::endl;
	std::cout << a.fRank(6) << std::endl;
}