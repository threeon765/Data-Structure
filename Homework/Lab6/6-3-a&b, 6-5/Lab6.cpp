#include "SortedType.h"
#include <iostream>

int main() {
	SortedType<int> a;
	SortedType<int> b;
	SortedType<int> c;
	SortedType<int> d;
	SortedType<int> e;
	for (int i = 0; i < 5; i++) {
		a.InsertItem(i);
		b.InsertItem(i + 5);
	}
	MergeLists(a, b, c); //Lab6-3-a
	PrintList(c);
	a.MergeLists(c, d); //Lab6-3-b
	PrintList(d);

	for (int i = 0; i < 5; i++) {
		e.InsertItem(i);
		e.InsertItem(i);
	}
	PrintList(e);
	e.DeleteItem(0); //Lab6-5
	PrintList(e);
}




