#pragma once
#include <new>
#include <iostream>

template <class itemtype>
struct nodetype {
	itemtype info;
	nodetype* next;
};

template <class itemtype>
class lusl {
public:
	lusl();
	void insertitem(itemtype item);
	void deleteitem(itemtype item);
	void survive(int n, int k);
	void print();
private:
	nodetype<itemtype>* listptr;
	int length;
};

template <class itemtype>
lusl<itemtype>::lusl() {
	length = 0;
	listptr = NULL;
}
template <class itemtype>
void lusl<itemtype>::insertitem(itemtype item) {
	nodetype<itemtype>* newptr = new nodetype<itemtype>;
	newptr->info = item;
	if (listptr == NULL) { //��
		newptr->next = NULL;
		listptr = newptr;
	}
	else {
		newptr->next = listptr;
		listptr = newptr;
	}
	length++;
}
template <class itemtype>
void lusl<itemtype>::deleteitem(itemtype item) {
	nodetype<itemtype>* locaptr = listptr;
	nodetype<itemtype>* tempptr = listptr;
	if (locaptr != NULL) { //��
		if (listptr->info == item) { //�۽�Ʈ, �۽�Ʈ&��Ʈ
			tempptr = locaptr->next;
			listptr = tempptr;
			item = locaptr->info; //�־��ִ°� �������
			delete locaptr;
			length--;
		}
		else {
			while (locaptr != NULL) { //���� - NULL, ��Ʈ&���ʷ� - �����ġ
				if (item == locaptr->info) {
					break;
				}
				else {
					tempptr = locaptr;
					locaptr = locaptr->next;
				}
			}
			if (locaptr != NULL) { //!����
				tempptr->next = locaptr->next;
				item = locaptr->info;
				delete locaptr;
				length--;
			}
		}
	}
}
template <class itemtype>
void lusl<itemtype>::print() {
	nodetype<itemtype>* locaptr = listptr;
	while (locaptr != NULL) {
		std::cout << locaptr->info << " ";
		locaptr = locaptr->next;
	}
	std::cout << std::endl;
}
template <class itemtype>
void lusl<itemtype>::survive(int n, int k) {
	for (int i = n; i >= 1; i--) {
		insertitem(i);
	}
	nodetype<itemtype>* locaptr = listptr;
	nodetype<itemtype>* tempptr = NULL;
	while (locaptr->next != NULL) {
		locaptr = locaptr->next;
	}
	locaptr->next = listptr; //circularȭ
	locaptr = locaptr->next;
	while (length > 1) {
		for (int i = 1; i < k; i++) {
			tempptr = locaptr;
			locaptr = locaptr->next;
		}
		std::cout << (locaptr->info) << " ";
		deleteitem(locaptr->info);
		locaptr = tempptr->next;
	}
	std::cout << (listptr->info) << " ";
	deleteitem(listptr->info);
	std::cout << std::endl;
}
