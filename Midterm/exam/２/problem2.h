#pragma once
#include <new>
#include <iostream>


template <class ItemType> //template���� ������ ���
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
	void RetrieveItem(ItemType& item, bool& found); //Unsorted�� �ٸ�
	void InsertItem(ItemType item);
	void Print();
private:
	NodeType<ItemType>* listptr;
};


template <class ItemType>
SortedType<ItemType>::SortedType() {
	listptr = NULL;
}

//########## �亯 �ڵ� ###############
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
			if (fmid < mid) { //mid�� Ŀ�� ��� loca
				for (int i = 1; i < mid; i++) {
					location = location->next;
				}
			}
			else { //mid�� �۾��� ��� loca
				for (int i = 1; i < mid - 1; i++) {
					location = location->next;
				}
			}
			if (item == location->info) {
				found = true;
				break;
			}
			else if (item > location->info) { //item�� �� ũ�� mid���� ū ���� ��
				first = mid + 1;
				moreToSearch = (first <= last);
			}
			else if (item < location->info) { //item�� �� ������ mid���� ���� ���� ��
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
	if (locaptr == NULL) { //�� 
		newptr->next = NULL;
		listptr = newptr;
	}
	else { //!��
		while (locaptr != NULL && (!found)) {
			if (locaptr->info < item) {
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