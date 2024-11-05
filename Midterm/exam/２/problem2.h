#pragma once
#include <new>
#include <iostream>


template <class ItemType> //template으로 구현할 경우
struct NodeType {
	ItemType info;
	NodeType* next;
};

class fulllist {};
class emptylist {};
template <class ItemType>
class SortedType {
public:
	SortedType();
	void RetrieveItem(ItemType& item, bool& found); //Unsorted와 다름
	void InsertItem(ItemType item);
	void Print();
private:
	NodeType<ItemType>* listptr;
};


template <class ItemType>
SortedType<ItemType>::SortedType() {
	listptr = NULL;
}

//########## 답변 코드 ###############
template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, bool& found) {
	bool moreToSearch;
	NodeType<ItemType>* location = listptr;
	if (listptr != NULL) { //!empty
		found = false;
		int length = 0; //get length
		while (location != NULL) {
			location = location->next;
			length++;
		}
		int mid;
		int first = 1;
		int last = length;
		int fmid = (first + last) / 2;
		location = listptr;
		moreToSearch = (first <= last);
		while (moreToSearch && (!found)) {
			location = listptr;
			mid = (first + last) / 2;
			if (fmid < mid) { //mid가 커질 경우 loca
				for (int i = 1; i < mid; i++) {
					location = location->next;
				}
			}
			else { //mid가 작아질 경우 loca
				for (int i = 1; i < mid - 1; i++) {
					location = location->next;
				}
			}
			if (item == location->info) {
				found = true;
				break;
			}
			else if (item > location->info) { //item이 더 크면 mid보다 큰 곳만 봄
				first = mid + 1;
				moreToSearch = (first <= last);
			}
			else if (item < location->info) { //item이 더 작으면 mid보다 작은 곳만 봄
				last = mid - 1;
				moreToSearch = (first <= last);
			}
		}
	}
	else { //empty
		found = false;
	}
}
//##############################################

template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item) {
	NodeType<ItemType>* locaptr = listptr;
	NodeType<ItemType>* predloca = NULL;
	bool found = false;
	NodeType<ItemType>* newptr = new NodeType<ItemType>;
	newptr->info = item;
	if (locaptr == NULL) { //텅 
		newptr->next = NULL;
		listptr = newptr;
	}
	else { //!텅
		while (locaptr != NULL && (!found)) {
			if (locaptr->info < item) {
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
}

template <class ItemType>
void SortedType<ItemType>::Print() {
	NodeType<ItemType>* locaptr = listptr;
	while (locaptr != NULL) {
		std::cout << locaptr->info << " ";
		locaptr = locaptr->next;
	}
	std::cout << std::endl;
}