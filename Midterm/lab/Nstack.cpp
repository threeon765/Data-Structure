#include "Nstack.h"
int main() {
	NStack a;
	a.nmPush(0, 0, "sika");
	a.nmPush(1, 0, "noko1");
	a.nmPush(2, 1, "noko2");
	a.nmPush(3, 1, "noko3");
	a.nmPush(4, 0, "koshi");
	a.nmPush(5, 0, "tantan");
	a.print();
	string koshitan;
	a.nmPop(0, 0, koshitan);
	cout << koshitan << endl;
	a.nmPop(4, 2, koshitan);
	cout << koshitan << endl;
	a.nmPop(3, 0, koshitan);
	cout << koshitan << endl;
	NStack b = a;
	b.print();
}