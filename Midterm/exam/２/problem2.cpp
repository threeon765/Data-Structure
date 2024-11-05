#include "problem2.h" //검증 코드
int main() {
	SortedType<int> a;
	for (int i = 1; i < 6; i++) {
		a.InsertItem(i);
	}
	a.Print();
	bool found;
	int i = 1; //이곳의 int를 변형하며 검증
	a.RetrieveItem(i, found);
	std::cout << found << " ";
}