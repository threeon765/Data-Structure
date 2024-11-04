#include <iostream>
#include "StackType.h"

void ReplaceItem(StackType &stack, int olditem, int newitem) {
	StackType copy;
	while (!(stack.IsEmpty())) {
		if (stack.Top() == olditem) {
			copy.Push(newitem);
			stack.Pop();
		}
		else {
			copy.Push(stack.Top());
			stack.Pop();
		}
	}
	while (!(copy.IsEmpty())) {
		stack.Push(copy.Top());
		copy.Pop();
	}
}

void StackType::ReplaceItem(int olditem, int newitem) {
	for (int i = 0; i < (sizeof(items)/sizeof(int)); i++) {
		if (items[i] == olditem) {
			items[i] = newitem;
		}
	}
}

void Print(StackType stack) {
	while (!(stack.IsEmpty())) {
		std::cout << stack.Top() << std::endl;
		stack.Pop();
	}
}



int main() {
	StackType stack;
	stack.Push(8);
	stack.Push(3);
	stack.Push(9);
	stack.Push(8);
	stack.Push(3);
	stack.Push(7);
	stack.Push(5);
	stack.Push(3);
	//검증 코드 - ReplaceItem를 하나씩 활성화시키고 Print 함수도 활성화시켜 결과를 확인해주세요.
	//ReplaceItem(stack, 3, 5);
	//stack.StackType::ReplaceItem(3, 5);
	//Print(stack);
}