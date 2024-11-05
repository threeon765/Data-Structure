#pragma once
#include <string>
#include <iostream>
using namespace std;

struct ItemType {
	string item;
	//�ڷ����� �� ������ �غ����� ��
	//1. std�� �ٿ�����
	//2. ���̺귯���� �߰��Ѵ�
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
	//~NStack(); //�Ҹ��� �� ������µ� �̷��� �־��ָ� ���� ����
	bool nmPush(int, int, string);
	bool nmPop(int, int, string&);
	void print();
};


NStack::NStack() { //�ڵ� �����Ϸ��� �����ڴ� ������ִ°� ����
	data = NULL;
}

NStack::NStack(NStack& Copy) { //��� ���� �����ڴ� �̷��� ����� OK
	ItemType *pasteptr, *copyptr, *temptr;
	copyptr = Copy.data;
	if (copyptr == NULL) { //��
		pasteptr = NULL;
	}
	else { //!��
		pasteptr = new ItemType; //ù ��� ����
		pasteptr->item = copyptr->item;
		pasteptr->back = NULL;
		pasteptr->next = NULL;
		data = pasteptr;
		copyptr = copyptr->next;
		while (copyptr != NULL) { //���� ��� ����
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

void NStack::print() { //��� print�� �̷��� ����� OK
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
	if (locaptr == NULL) { //��
		if (n == 0 && m == 0) { //�ε�
			newptr = new ItemType;
			newptr->item = x;
			newptr->back = NULL;
			newptr->next = NULL;
			data = newptr; //���� data�� ����Ű���� �ϴ� ���� ����
			return true;
		}
		else { //����
			return false;
		}
	}
	else {
		int length = 0;
		while (locaptr != NULL) { //��
			locaptr = locaptr->next;
			length++;
		}
		locaptr = data;
		if (n >= m && n <= length) { //!��
			newptr = new ItemType;
			newptr->item = x;
			if (n - m == 0) { //�۽�Ʈ
				newptr->next = locaptr;
				newptr->back = NULL;
				locaptr->back = newptr;
				data = newptr;
			}
			else if (n - m == length) { //��Ʈ
				while (locaptr->next != NULL) {
					locaptr = locaptr->next;
				}
				newptr->next = NULL;
				newptr->back = locaptr;
				locaptr->next = newptr;
			}
			else { //���ʷ�
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
		if (n >= m && n < length) { //!��
			if (n - m == 0) { //�۽�Ʈ
				(locaptr->next)->back = NULL;
				data = locaptr->next;
			}
			else if (n - m == length - 1) { //��Ʈ
				while (locaptr->next != NULL) {
					locaptr = locaptr->next;
				}
				(locaptr->back)->next = NULL;
			}
			else { //���ʷ�
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
