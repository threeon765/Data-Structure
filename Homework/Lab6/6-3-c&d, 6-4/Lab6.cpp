#include "UnsortedType.h"
#include <iostream>
int main() {
	UnsortedType<int> a;
	UnsortedType<int> b;
	UnsortedType<int> c;
	UnsortedType<int> d;
	UnsortedType<int> e;

	for (int i = 0; i < 10; i += 2) {
		a.InsertItem(i);
	}
	for (int i = 1; i < 10; i += 2) {
		b.InsertItem(i);
	}
	a.PrintList();
	b.PrintList();

	a.MergeLists(b, c); //Lab 6-3-d
	MergeLists(a, b, d); //Lab 6-3-c
	
	a.PrintList();
	b.PrintList();
	c.PrintList();
	d.PrintList();
	
	for (int i = 0; i < 5; i += 2) {
		e.InsertItem(i);
		e.InsertItem(i);
	}

	e.PrintList();
	e.DeleteItem(4); //Lab 6-4
	e.PrintList();
	e.DeleteItem(5);
	e.PrintList();
}