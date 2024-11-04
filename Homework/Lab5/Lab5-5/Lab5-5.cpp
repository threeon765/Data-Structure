#include "QueType.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
	std::cout << "i f r l" << std::endl;
	
	QueType a(10);

	a.MakeEmpty();
	std::cout << "  " << a.GetFront() << " " << a.GetRear() << " " << a.GetLength() << std::endl;;
	if (a.IsEmpty() != 0) {
		std::cout << "EMPTY" << std::endl;
	}
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		std::cout << i << " ";
		a.Enqueue(i);
		std::cout << a.GetFront() << " " << a.GetRear() << " " << a.GetLength() << std::endl;
		if (a.IsFull() != 0) {
			std::cout << "FULL" << std::endl;
		}
	}
	std::cout << std::endl;
	
	int print;
	for (int i = 0; i < 10; i++) {
		a.Dequeue(print);
		std::cout << print << " ";
		std::cout << a.GetFront() << " " << a.GetRear() << " " << a.GetLength() << std::endl;
		if (a.IsEmpty() != 0) {
			std::cout << "EMPTY" << std::endl;
		}
	}
	std::cout << std::endl;
}