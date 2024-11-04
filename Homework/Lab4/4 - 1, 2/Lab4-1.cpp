#include "StackTType.h"
#include "MaxItem.h"
#include <iostream>

int main() {
	StackType<int> stack;
	stack.Push(1);
	stack.Push(2);
	stack.Push(3);
	stack.Push(4);
	stack.Push(5);
	stack.Push(6);
	std::cout << stack.Top() << std::endl;
	stack.Pop();
	std::cout << stack.Top() << std::endl;
	stack.Pop();
	std::cout << stack.Top() << std::endl;
	stack.Pop();
	std::cout << stack.Top() << std::endl;
	stack.Pop();
	std::cout << stack.Top() << std::endl;
	stack.Pop();
	std::cout << stack.Top() << std::endl;
	stack.Pop();
}