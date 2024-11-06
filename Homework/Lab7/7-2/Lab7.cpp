#include "StackType.h"
#include <iostream>

int main() {
	StackType a, b;
	for (int i = 1; i < 11; i++) {
		a.Push(i);
	}
	b.Copy(a);
	while (!(a.IsEmpty())) {
		std::cout << a.Top() << ", ";
		a.Pop();
	}
	std::cout << std::endl;
	while (!(b.IsEmpty())) {
		std::cout << b.Top() << ", ";
		b.Pop();
	}
	std::cout << std::endl;
}