#include "DoublyLinkedSortedList.h"
#include <new>
template <class itemtype>
bool dlsl<itemtype>::isfull() const { //�� ����� ����
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
int dlsl<itemtype>::lengthis() const {
	return length;
}
template <class itemtype>
dlsl<itemtype>::dlsl() {
	length = 0;
	listptr = NULL;
	currentptr = NULL;
}

template <class itemtype>
void dlsl<itemtype>::finditem(itemtype& item, nodetype<itemtype>* &locaptr, bool& found) { //�������� ã�ƿ�~
	locaptr = listptr;
	found = false;
	bool more2search = (locaptr != NULL);
	while (more2search && !found) {
		if (locaptr->info < item) {
			//locaptr = locaptr->next;
			//more2search = (locaptr != NULL);
			//��Ʈ���� locaptr�� NULL�Ǿ������ ������ ������ �߰��� ���� �߰� Ȱ���� �Ұ�
			if (locaptr->next == NULL) {
				more2search = false;
			}
			else {
				locaptr = locaptr->next;
			}
			//locaptr�� NULL�� ���� �ǳʴ� ���� �����ϴ� �ڵ�
		}
		else if (locaptr->info == item) {
			found = true;
		}
		else {
			more2search = false;
		}
	}
}

template <class itemtype>
void dlsl<itemtype>::insertitem(itemtype item) {
	nodetype<itemtype>* locaptr; //back ������� ���ܼ� tempptr�� �ʿ䰡 ����
	nodetype<itemtype>* newptr = new nodetype<itemtype>;
	newptr->info = item;
	bool found;
	finditem(item, locaptr, found); //item�� ���ų� �ٷ� ū �� ��ġ, �Ǵ� ��Ʈ ��ȯ
	//new ���� loca�� �ǵ���� �����ϰ� ��ȭ ����
	if (locaptr != NULL) {
		if (location->info >= item) {
			newptr->next = locaptr;
			newptr->back = locaptr->back;
			if (locaptr != listptr) { //���ʷ� ���̽�
				locaptr->back->next = newptr;
			}
			else { //�۽�Ʈ ���̽�
				listptr = newptr;
			}
			locaptr->back = newptr;
		}
		else { //��Ʈ ���̽�
			newptr->back = locaptr;
			newptr->next = NULL;
			locaptr->next = newptr;
		}
		/* //���� ��� ���̽��� ����ٸ�
		if (locaptr == listptr) { //�۽�Ʈ ���̽�
			newptr->next = locaptr;
			newptr->back = NULL;
			locaptr->back = newptr;
			listptr = newptr;
		}
		else if (locaptr->next == NULL) { //��Ʈ ���̽�
			newptr->back = locaptr;
			newptr->next = NULL;
			locaptr->next = newptr;
		}
		else { //���ʷ� ���̽�
			newptr->back = locaptr->back; //�ݵ�� ������ ���Ѽ� ���� ������ ��
			newptr->next = locaptr;
			locaptr->back->next = newptr;
			locaptr->back = newptr;
		}
		*/
	}
	else { //�� ���̽�
		newptr->back = NULL;
		newptr->next = NULL;
		listptr = newptr;
	}
	length++;
}
template <class itemtype>
void dlsl<itemtype>::deleteitem(itemtype item) { //ã�� ���̱�! �������̶� �Ȱ���!
	nodetype<itemtype>* locaptr; //back ������� ���ܼ� tempptr�� �ʿ䰡 ����
	bool found;
	finditem(item, locaptr, found); //found�� ��� item�� ���� ��ġ ��ȯ
	//new ���� loca�� �ǵ���� �����ϰ� ��ȭ ����
	if (found) {
		if (locaptr->next != NULL) {
			(locaptr->next)->back = locaptr->back;
			if (locaptr != listptr) { //���ʷ� ���̽�
				(locaptr->back)->next = locaptr->next;
			}
			else { //�۽�Ʈ ���̽�
				listptr = locaptr->next;
			}
		}
		else { 
			if (locaptr->back != NULL) { //��Ʈ ���̽�
				(locaptr->back)->next = NULL;
			}
			else { //�۽�Ʈ & ��Ʈ ���̽�
				listptr = NULL;
			}
		}
		delete locaptr;
		length--;
	}
	//�� ���̽��� �ƹ� �ϵ� ������
}

template <class itemtype>
void dlsl<itemtype>::makeempty() {
	nodetype<itemtype>* tempptr = listptr;
	while (length != 0) {
		listptr = listptr->next;
		delete tempptr;
		length--;
	}
}
template <class itemtype>
dlsl<itemtype>::~dlsl() {
	makeempty();
}

template<class itemtype>
void dlsl<itemtype>::getnextitem(itemtype& item) { //����Ʈ �� �μ��� ������ �Ա�
	if (currentptr == NULL) {
		currentptr = listptr;
	}
	else {
		currentptr = currentptr->next;
	}
	item = currentptr->info;
}
template <class itemtype>
void dlsl<itemtype>::resetlist() { //�������� �Ա� ���� ��ġ ����
	currentptr = NULL;
}