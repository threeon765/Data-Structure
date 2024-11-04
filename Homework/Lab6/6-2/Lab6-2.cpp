#include "QueType.h"
#include <iostream>

int main() {
	QueType<int> a;
	for (int i = 0; i < 5; i++) {
		a.Enqueue(i);
		a.Enqueue(i);
	}

	ReplaceItem(a, 3, 11);
	a.ReplaceItem(11, 3);
	a.ReplaceItem(5, 99);

	int checker;
	for (int i = 0; i < 10; i++) {
		a.Dequeue(checker);
		std::cout << checker << " ";
	}
	std::cout << std::endl;
}
