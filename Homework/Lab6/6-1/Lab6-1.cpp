#include "StackType.h"
#include <iostream>

int main() {
	StackType a;
	for (int i = 0; i < 10; i++) {
		a.Push(i);
	}
	
	ReplaceItem(a, 5, 10); //Lab 6-1 °ËÁõ
	a.ReplaceItem(10, 11);

	for (int i = 0; i < 10; i++) {
		std::cout << a.Top() << " ";
		a.Pop();
	}
	std::cout << std::endl;
}