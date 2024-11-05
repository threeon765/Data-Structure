//�� �� �۽�Ʈ ��Ʈ ���� ���� �ƿ� ���ʷ�

#pragma once
#include <new>
#include <iostream>

template <class itemtype>
struct nodetype {
	itemtype info;
	nodetype* next;
};

template <class itemtype>
class ReverseSortedType {
public:
	ReverseSortedType();
	void insertitem(itemtype item);
	void print();
	itemtype fRank(int index);
	itemtype bRank(int index);
private:
	nodetype<itemtype>* listptr;
	nodetype<itemtype>* currentptr;
	int length;
};

template <class itemtype>
ReverseSortedType<itemtype>::ReverseSortedType() {
	length = 0;
	listptr = NULL;
	currentptr = NULL;
}
template <class itemtype>
void ReverseSortedType<itemtype>::print() { //��� print�� �̷��� ����� OK
	nodetype<itemtype>* locaptr = listptr;
	while (locaptr != NULL) {
		std::cout << locaptr->info << ", ";
		locaptr = locaptr->next;
	}
	std::cout << std::endl;
}
template <class itemtype>
void ReverseSortedType<itemtype>::insertitem(itemtype item) {
	nodetype<itemtype>* locaptr = listptr;
	nodetype<itemtype>* predloca = NULL;
	bool found = false;
	nodetype<itemtype>* newptr = new nodetype<itemtype>;
	newptr->info = item;
	if (locaptr == NULL) { //�� 
		newptr->next = NULL;
		listptr = newptr;
	}
	else { //!��
		while (locaptr != NULL && (!found)) {
			if (locaptr->info > item) {
				predloca = locaptr;
				locaptr = locaptr->next;
			}
			else {
				found = true; //�� �� �Ǵ� �װͺ��� ������ ���� ū ���� ����Ŵ
			}
		} //�� ã���� NULL
	}
	if (predloca == NULL) { //�۽�Ʈ
		newptr->next = locaptr;
		listptr = newptr;
	}
	else if (locaptr == NULL) { //��Ʈ (& ����)
		newptr->next = NULL;
		predloca->next = newptr;
	}
	else { //���ʷ� (& ����)
		predloca->next = newptr;
		newptr->next = locaptr;
	}
	length++;
}
template <class itemtype>
itemtype ReverseSortedType<itemtype>::fRank(int index) {
	nodetype<itemtype>* locaptr = listptr;
	if (locaptr == NULL) {
		return -1;
	}
	else {
		for (int i = 1; i < index; i++) {
			if (locaptr == NULL) { //���� ���
				return -1;
			}
			locaptr = locaptr->next;
		}
		if (locaptr == NULL) { //�����
			return -1;
		}
		else {
			return locaptr->info; //�㰡
		}
	}
}
template <class itemtype>
itemtype ReverseSortedType<itemtype>::bRank(int index) {
	nodetype<itemtype>* locaptr = listptr;
	if (locaptr == NULL) { //��
		return -1;
	}
	else {
		int length = 0; //���� length �����
		while (locaptr != NULL) {
			locaptr = locaptr->next;
			length++;
		}
		for (int i = index; i < length; i++) {
			if (locaptr == NULL) { //���� ���
				return -1;
			}
			locaptr = locaptr->next;
		}
		if (locaptr == NULL) { //�����
			return -1;
		}
		else {
			return locaptr->info; //�㰡
		}
	}
}