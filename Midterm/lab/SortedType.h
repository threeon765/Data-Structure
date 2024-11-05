#pragma once
#include <new>
template<class itemtype>
struct nodetype {
	itemtype info;
	nodetype* next;
};

template<class itemtype>
class SortedType {
	nodetype<itemtype>* listptr;
	int length;
public:
	void insertitem(itemtype item) {
		nodetype<itemtype>* locaptr = listptr, predloca = NULL;
		bool found = false;
		nodetype<itemtype>* newptr = new nodetype<itemtype>;
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
					found = true;
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
	void deleteitem(itemtype item) {
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
};