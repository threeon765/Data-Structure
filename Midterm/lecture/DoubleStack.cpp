#include <iostream>

const int MAX_ITEMS = 200;

class Double_Stack {
private:
	int top_small = -1;
	int top_big = MAX_ITEMS;
	int items[MAX_ITEMS];
public:
	bool IsFull() {
		return ((top_small + 1 == top_big)||(top_small > top_big));
	}
	void Push(int item) {
		if (!(IsFull())) {
			if (item < 1000) {
				top_small++;
				items[top_small] = item;
			}
			else {
				top_big--;
				items[top_big] = item;
			}
		}
		else {
			std::cout << "This stack is Full" << std::endl;
		}
	}
	void Print() {
		for (int i = top_small; i > -1; i--) {
			std::cout << items[i] << ", ";
		}
		std::cout << std::endl;
		for (int i = top_big; i < MAX_ITEMS; i++) {
			std::cout << items[i] << ", ";
		}
		std::cout << std::endl;
	}
};

int main() {
	Double_Stack DS;
	for (int i = 900; i < 1100; i++) {
		DS.Push(i);
	} 
	DS.Push(1); //스택이 가득찼을때 추가를 거부하는지 확인
	DS.Print(); //출력
}