#include "LinkedSortedList.h"
#include <new>
template <class itemtype>
bool lsl<itemtype>::isfull() const { //�� ����� ����
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
int lsl<itemtype>::lengthis() const {
	return length;
}
template <class itemtype>
lsl<itemtype>::lsl() {
	length = 0;
	listptr = NULL;
	currentptr = NULL;
}
template <class itemtype>
void lsl<itemtype>::retrieveitem(itemtype& item, bool& found) { //�������� ã�ƿ�~
	nodetype<itemtype>* locaptr = listptr; //�� �� ��带 ��������
	found = false; //���� �� ã����
	bool more2search = (locaptr != NULL); //����Ʈ �� ���ҳ�?
	while (more2search && !found) {
		if (locaptr->info < item) { //sorted�ϱ� �� ȿ�������� ����
			locaptr = locaptr->next;
			more2search = (locaptr != NULL);
		}
		else if (locaptr->info == item) { //ã�� ����
			found = true;
		}
		else { //�� ���µ���?
			locaptr = NULL; //�׷� ���� ����
		}
	}
}
template <class itemtype>
void lsl<itemtype>::insertitem(itemtype item) {
	nodetype<itemtype>* locaptr = listptr, predloca = NULL; //���� ���� �־�� �ϴ��� ã�ڰ�
	bool found = false;
	while (locaptr != NULL && (!found)) { //�� ã�Ҵµ� ���� �� ���� �ִ°�?
		if (locaptr->info < item) { //���� �۴�!
			predloca = locaptr; //���󰩴ϴ�!
			locaptr = locaptr->next; //�� ����!
		}
		else if { //��! �� ũ��!
			found = true; //ã�Ҵ�!
		}
	}
	nodetype<itemtype>* newptr = new nodetype<itemtype>;
	newptr->info = item; //���� �����!
	if (predloca == NULL) { //�ٵ� ó������ ã���̴µ���?
		newptr->next = locaptr; //�׷� Unsortedó�� �ϸ� ����!
		listptr = newptr;
	}
	else {
		predloca->next = newptr; //�����ϰڽ��ϴ�!
		newptr->next = locaptr;
	}
	length++;
}
template <class itemtype>
void lsl<itemtype>::deleteitem(itemtype item) { //ã�� ���̱�! �������̶� �Ȱ���!
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
void lsl<itemtype>::makeempty() {
	nodetype<itemtype>* tempptr = listptr;
	while (length != 0) {
		listptr = listptr->next;
		delete tempptr;
		length--;
	}
}
template <class itemtype>
lsl<itemtype>::~lsl() {
	makeempty();
}

template<class itemtype>
void lsl<itemtype>::getnextitem(itemtype& item) { //����Ʈ �� �μ��� ������ �Ա�
	if (currentptr == NULL) {
		currentptr = listptr;
	}
	else {
		currentptr = currentptr->next;
	}
	item = currentptr->info;
}
template <class itemtype>
void lsl<itemtype>::resetlist() { //�������� �Ա� ���� ��ġ ����
	currentptr = NULL;
}
//### �ǽ� ###
template <class itemtype> //���� ������
lsl<itemtype>::lsl(const lsl<itemtype>& another) {
	makeempty();
	if (another.listptr == NULL) {
		listptr = NULL;
	}
	else {
		listptr = new nodetype<itemtype>;
		listptr->info = another.listptr->info;
		nodetype<itemtype>* oldptr = another.listptr->next;
		nodetype<itemtype>* newptr = listptr;
		while (oldptr != NULL) {
			newptr->next = new nodetype<itemtype>;
			newptr = newptr->next;
			newptr->info = oldptr->info;
			oldptr = oldptr->next;
		}
		newptr->next = NULL;
	}	
}
template <class itemtype> //length�� ��ġ ���� + ������ ��ҷ� ����
void lsl<itemtype>::reverse() {
	nodetype<itemtype>* locaptr = listptr;
	lsl<itemtype> templsl(*this);
	nodetype<itemtype>* tempptr = templsl.listptr;
	for (int i = length - 1; i > -1; i--) {
		locaptr = listptr;
		for (int j = 0; j < i; j++) {
			locaptr = locaptr->next;
		}
		locaptr->info = tempptr->info;
		tempptr = tempptr->next;
	}
	templsl.makeempty();
}
//�Ǵ� ������ ��� �����ϸ� ���ʴ�� ���ÿ� �ְ� 
//������ ���߽�Ű�鼭 �ٽ� ������ �ֱ�
template <class itemtype>
void lsl<itemtype>::merge(lsl<itemtype> other, lsl<itemtype>& result) { //��� �� �� ���� �� ����
	nodetype<itemtype>* thisptr = listptr;
	nodetype<itemtype>* otherptr = other.listptr;
	nodetype<itemtype>* resultptr = result.listptr;
	if (resultptr == NULL) {
		resultptr = new nodetype<itemtype>;
	}
	while (thisptr != NULL && otherptr != NULL) {
		if (resultptr->next = NULL) {
			resultptr->next = new nodetype<itemtype>;
		}
		if (thisptr > otherptr) {
			otherptr->info = resultptr->info;
			resultptr = resultptr->next;
			otherptr = otherptr->next;
		}
		else if (thisptr < otherptr) {
			thisptr->info = resultptr->info;
			resultptr = resultptr->next;
			thisptr = thisptr->next;
		}
		else {
			thisptr->info = resultptr->info;
			resultptr = resultptr->next;
			thisptr = thisptr->next;
			otherptr = otherptr->next;
		}
	}
	while (thisptr != NULL) { //�ܹ� ó��
		if (resultptr->next = NULL) {
			resultptr->next = new nodetype<itemtype>;
		}
		thisptr->info = resultptr->info;
		resultptr = resultptr->next;
		thisptr = thisptr->next;
	}
	while (otherptr != NULL) {
		if (resultptr->next = NULL) {
			resultptr->next = new nodetype<itemtype>;
		}
		otherptr->info = otherptr->info;
		resultptr = resultptr->next;
		otherptr = otherptr->next;
	}
}
//�Ǵ� currentptr ���� �Լ��� ���� �������� �̰� �׳� insert�� �����ϸ� ��
template <class itemtype>
void lsl<itemtype>::deleteitem_ver2(itemtype item) {
	nodetype<itemtype>* locaptr = listptr;
	nodetype<itemtype>* tempptr;
	if (locaptr != NULL) {
		if (item == locaptr->info) { //�۽�Ʈ ���̽�
			listptr = locaptr->next;
		}
		else {
			while (item != locaptr->info && locaptr != NULL) { //Ÿ�� ��ġ - loca, Ÿ�� �� ��ġ - temp
				//���� ���̽��� ���� ���� ���� ����, ��Ʈ ���̽��� ����
				temptr = locaptr;
				locaptr = locaptr->next;
			}
			if (locaptr != NULL) { //���� ���̽� ����
				tempptr->next = locaptr->next;
			}
		}
		delete locaptr;
		length--;
		if (tempptr->next->info == item) { //������ ���̽�
			deleteitem_ver2(item); //�Ȱ��� ���������� �� �� �� �Լ� ����
		}
	}
}