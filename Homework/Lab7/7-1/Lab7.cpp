#include "SortedType.h"

int main() {
	SortedType<int> a;
	for (int i = 1; i < 11; i++) {
		a.InsertItem(i);
	}
	a.PrintReverse();
}