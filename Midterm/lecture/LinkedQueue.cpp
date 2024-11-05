#include "LinkedQueue.h"
#include <new> //NULL�� \0�� ����ϱ� ���� ��ó����
//### �⺻ �޼��� ### (���� �ڷ� ������ �ۼ�)
template<class itemtype>
bool linkedqueue<itemtype>::isfull() const { //������ �Ȱ��� �ź� �ִ� ���Ⱑ �ȵǸ� ��
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
template<class itemtype>
bool linkedqueue<itemtype>::isempty() const { //����� �翬���� «��� ���� �� �� ����� ��
	return (frontptr == NULL && rearptr == NULL);
}
template<class itemtype>
linkedqueue<itemtype>::linkedqueue() {
	frontptr = NULL;
	rearptr = NULL;
} 
template<class itemtype>
void linkedqueue<itemtype>::makeempty() { //���� ������ �� �� �������Ѽ� �δ븦 ��
	nodetype<itemtype>* tempptr;
	while (frontptr != NULL) {
		tempptr = frontptr;
		frontptr = frontptr->next;
		delete tempptr;
		//rearptr->next = frontptr; //circular
	}
	rearptr = NULL;
}
template<class itemtype>
linkedqueue<itemtype>::~linkedqueue() { //�Ҹ��ڵ� �Ȱ��� �˴� ����
	makeempty();
}
template<class itemtype>
void linkedqueue<itemtype>::enqueue(itemtype newitem) {
	if (isfull()) {
		throw fullqueue();
	}
	else {
		nodetype<itemtype>* newptr = new nodetype<itemtype>;
		newptr->info = newitem;
		newptr->next = NULL; //�ź� ��� �ϼ�
		if (rearptr == NULL) { //«����� ���ٸ�, �� ���̾�����
			front = newptr; //�ź��� �� �ְ������� «��
		}
		else { //«� ������
			rearptr->next = newptr; //«�� �ڿ� �ź� ����
			//newptr->next = frontptr; //circular��� �ź��� ������ ����
		}
		rearptr = newptr; //���� �ź��� «�� ����
	}
}
template<class itemtype>
void linkedqueue<itemtype>::dequeue(itemtype &item) {
	if (isempty()) {
		throw emptyqueue();
	}
	else {
		nodetype<itemtype>* tempptr = frontptr; //������ ���� ��� �ӽ� ����
		item = frontptr->info; //item�� ���� ��� ���� �� �̰�
		frontptr = frontptr->next; //���� ������ ���� ��� �� ��尡 ���� ����
		if (frontptr == NULL) { //��� ���� �� ��尡 ����
			rearptr = NULL; //������ ���� �����...
		}
		else {
			//rearptr->next = frontptr; //circular��� ���ο� ���� ���� «�� ��� ����
		}
		delete tempptr; //�����ϰ� ����
	}
}
/*
circular�� ���ؼ� �����غ���
array�ʹ� �ٸ��� front�� ���� ���� �ϳ��� ������ �ʿ䵵 ����
���� rear->next = front�̸� �Ǵ°Ŵ�
�ٵ� �̰� �� ��? ������ ���Ÿ�...
*/
//### �ǽ� ###
template<class itemtype>
void linkedqueue<itemtype>::mindequeue(itemtype& item) { //�ּҰ��� ����
	if (isempty()) {
		throw emptyqueue();
	}
	else {		
		nodetype<itemtype>* locaptr = frontptr, temptr, minptr = frontprt;
		while (locaptr != NULL) { //�ּҰ� ��ġ ã��
			if (locaptr->info < minptr->info) {
				minptr = locaptr;
				item = minptr->info; //�ּҰ��� �̻�������
			}
			locaptr = locaptr->next;
		}
		locaptr = frontptr;
		while (locaptr == minptr) { //�ּҰ� ��ġ loca, �ּҰ� �� ��ġ temp
			temptr = locaptr;
			locaptr = locaptr->next;
		}
		temptr->next = locaptr->next;
		minptr = NULL; //��۸� ����
		delete temptr; //�׿�
	}
}
