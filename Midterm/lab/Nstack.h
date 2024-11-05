#pragma once
#include <string>
#include <iostream>
using namespace std;

struct ItemType {
	string item;
	//자료형이 안 써지면 해봐야할 것
	//1. std를 붙여본다
	//2. 라이브러리를 추가한다
	ItemType* next;
	ItemType* back;
};

class NStack {
/*
doubly linked list
ItemType = Node
*/
	ItemType* data;
public:
	NStack(); 
	NStack(NStack&);
	//~NStack(); //소멸자 안 만들었는데 이렇게 넣어주면 오류 생김
	bool nmPush(int, int, string);
	bool nmPop(int, int, string&);
	void print();
};


NStack::NStack() { //코드 검증하려면 생성자는 만들어주는게 좋지
	data = NULL;
}

NStack::NStack(NStack& Copy) { //모든 복사 생성자는 이렇게 만들면 OK
	ItemType *pasteptr, *copyptr, *temptr;
	copyptr = Copy.data;
	if (copyptr == NULL) { //텅
		pasteptr = NULL;
	}
	else { //!텅
		pasteptr = new ItemType; //첫 노드 제작
		pasteptr->item = copyptr->item;
		pasteptr->back = NULL;
		pasteptr->next = NULL;
		data = pasteptr;
		copyptr = copyptr->next;
		while (copyptr != NULL) { //이후 노드 제작
			temptr = new ItemType;
			temptr->item = copyptr->item;
			temptr->back = pasteptr;
			pasteptr->next = temptr;
			pasteptr = pasteptr->next;
			copyptr = copyptr->next;
		}
		pasteptr->next = NULL;
	}
}

void NStack::print() { //모든 print는 이렇게 만들면 OK
	ItemType* locaptr = data;
	while (locaptr != NULL) {
		cout << locaptr->item << ", ";
		locaptr = locaptr->next;
	}
	cout << endl;
}

bool NStack::nmPush(int n, int m, string x) {
	ItemType* locaptr;
	ItemType* newptr;
	locaptr = data;
	if (locaptr == NULL) { //텅
		if (n == 0 && m == 0) { //부동
			newptr = new ItemType;
			newptr->item = x;
			newptr->back = NULL;
			newptr->next = NULL;
			data = newptr; //직접 data가 가리키도록 하는 것이 좋음
			return true;
		}
		else { //유동
			return false;
		}
	}
	else {
		int length = 0;
		while (locaptr != NULL) { //텅
			locaptr = locaptr->next;
			length++;
		}
		locaptr = data;
		if (n >= m && n <= length) { //!텅
			newptr = new ItemType;
			newptr->item = x;
			if (n - m == 0) { //퍼스트
				newptr->next = locaptr;
				newptr->back = NULL;
				locaptr->back = newptr;
				data = newptr;
			}
			else if (n - m == length) { //라스트
				while (locaptr->next != NULL) {
					locaptr = locaptr->next;
				}
				newptr->next = NULL;
				newptr->back = locaptr;
				locaptr->next = newptr;
			}
			else { //제너럴
				for (int i = 0; i < n - m; i++) {
					locaptr = locaptr->next;
				}
				newptr->next = locaptr;
				newptr->back = locaptr->back;
				(locaptr->back)->next = newptr;
				locaptr->back = newptr;
			}
			return true;
		}
		else {
			return false;
		}
	}
}

bool NStack::nmPop(int n, int m, string& x) {
	ItemType* locaptr;
	locaptr = data;
	if (locaptr == NULL) {
		return false;
	}
	else {
		int length = 0;
		while (locaptr != NULL) {
			locaptr = locaptr->next;
			length++;
		}
		locaptr = data;
		if (n >= m && n < length) { //!텅
			if (n - m == 0) { //퍼스트
				(locaptr->next)->back = NULL;
				data = locaptr->next;
			}
			else if (n - m == length - 1) { //라스트
				while (locaptr->next != NULL) {
					locaptr = locaptr->next;
				}
				(locaptr->back)->next = NULL;
			}
			else { //제너럴
				for (int i = 0; i < n - m; i++) {
					locaptr = locaptr->next;
				}
				(locaptr->back)->next = locaptr->next;
				(locaptr->next)->back = locaptr->back;
			}
			x = locaptr->item;
			delete locaptr;
			return true;
		}
		else {
			return false;
		}
	}
}
