//꽉 텅 퍼스트 라스트 낫띵 듀플 아웃 제너럴

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
void ReverseSortedType<itemtype>::print() { //모든 print는 이렇게 만들면 OK
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
	if (locaptr == NULL) { //텅 
		newptr->next = NULL;
		listptr = newptr;
	}
	else { //!텅
		while (locaptr != NULL && (!found)) {
			if (locaptr->info > item) {
				predloca = locaptr;
				locaptr = locaptr->next;
			}
			else {
				found = true; //그 값 또는 그것보다 작은데 가장 큰 값을 가리킴
			}
		} //못 찾으면 NULL
	}
	if (predloca == NULL) { //퍼스트
		newptr->next = locaptr;
		listptr = newptr;
	}
	else if (locaptr == NULL) { //라스트 (& 낫띵)
		newptr->next = NULL;
		predloca->next = newptr;
	}
	else { //제너럴 (& 듀플)
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
			if (locaptr == NULL) { //범위 벗어남
				return -1;
			}
			locaptr = locaptr->next;
		}
		if (locaptr == NULL) { //재검증
			return -1;
		}
		else {
			return locaptr->info; //허가
		}
	}
}
template <class itemtype>
itemtype ReverseSortedType<itemtype>::bRank(int index) {
	nodetype<itemtype>* locaptr = listptr;
	if (locaptr == NULL) { //텅
		return -1;
	}
	else {
		int length = 0; //간이 length 만들기
		while (locaptr != NULL) {
			locaptr = locaptr->next;
			length++;
		}
		for (int i = index; i < length; i++) {
			if (locaptr == NULL) { //범위 벗어남
				return -1;
			}
			locaptr = locaptr->next;
		}
		if (locaptr == NULL) { //재검증
			return -1;
		}
		else {
			return locaptr->info; //허가
		}
	}
}