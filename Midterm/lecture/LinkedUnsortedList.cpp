#include "LinkedUnsortedList.h"
#include <new>
template <class itemtype>
bool lusl<itemtype>::isfull() const { //�� ����� ����
	nodetype<itemtype>* newptr;
	try {
		newptr = new nodetype<itemtype>;
		delete newptr;
		return false;
	}
	catch (std::bad_alloc exception) {
		return true;
	}
}
template <class itemtype>
int lusl<itemtype>::lengthis() const {
	return length;
}
template <class itemtype>
lusl<itemtype>::lusl() {
	length = 0;
	listptr = NULL;
	currentptr = NULL;
}
template <class itemtype>
void lusl<itemtype>::retrieveitem(itemtype& item, bool& found) { //�������� ã�ƿ�~
	nodetype<itemtype>* locaptr = listptr; //�� �� ��带 ��������
	found = false; //���� �� ã����
	bool more2search = (locaptr != NULL); //����Ʈ �� ���ҳ�?
	while (more2search && !found) { //ã�����ٰ� �� �������� (�̰� ������ ���� ������)
		if (locaptr->info == item) {
			found = true; //ã�Ҵ�!!
		}
		else { //���� �ƴϾ�?
			locaptr = locaptr->next; //����������
			more2search = (locaptr != NULL); //�ٵ� �������ֳ�?
		}
	}
}
template <class itemtype>
void lusl<itemtype>::insertitem(itemtype item) { //�� �� ��带 ���ο� ����!
	nodetype<itemtype>* newptr = new nodetype<itemtype>;
	newptr->info = item;
	newptr->next = listptr;
	listptr = newptr;
	length++;
}
template <class itemtype>
void lusl<itemtype>::deleteitem(itemtype item) { //ã�� ���̱�!
	nodetype<itemtype>* locaptr = listptr;
	nodetype<itemtype>* tempptr;
	if (listptr->info == item) { //�� ó������ ã�Ҵµ�?
		tempptr = locaptr;
		listptr = listptr->next; //���� ��� �ӽ� �����ϰ� �������
	}
	else { //����?
		while (!(item == (locaptr->next)->info)) { //���� ��� ���� �������� �̵��� (������ ���� ����)
			locaptr = locaptr->next;
		}
		tempptr = locaptr->next; //���� ��� �ӽ� ������
		locaptr->next = (locaptr->next)->next; //���� ��� ���� ���� ���� ��� ���� ���� ������
	}
	delete tempptr; //�׿�!
	length--;
}

template <class itemtype>
void lusl<itemtype>::makeempty() {
	nodetype<itemtype>* tempptr = listptr;
	while (length != 0) {
		listptr = listptr->next;
		delete tempptr;
		length--;
	}
}
template <class itemtype>
lusl<itemtype>::~lusl() {
	makeempty();
}

template<class itemtype>
void lusl<itemtype>::getnextitem(itemtype& item) { //����Ʈ �� �μ��� ������ �Ա�
	if (currentptr == NULL) {
		currentptr = listptr;
	}
	else {
		currentptr = currentptr->next;
	}
	item = currentptr->info;
}
template <class itemtype>
void lusl<itemtype>::resetlist() { //�������� �Ա� ���� ��ġ ����
	currentptr = NULL;
}
