#include "problem2.h" //���� �ڵ�
int main() {
	SortedType<int> a;
	for (int i = 1; i < 6; i++) {
		a.InsertItem(i);
	}
	a.Print();
	bool found;
	int i = 1; //�̰��� int�� �����ϸ� ����
	a.RetrieveItem(i, found);
	std::cout << found << " ";
}