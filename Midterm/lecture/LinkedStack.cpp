#include "LinkedStack.h"
#include <new> //NULL�� \0�� ����ϱ� ���� ��ó����
//### �⺻ �޼��� ### (���� �ڷ� ������ �ۼ�)
void linkedstack::push(itemtype newitem) {
	if (isfull()) {
		throw fullstack();
	}
	nodetype* locaptr = new nodetype; //���ο� ����� �ּҸ� �ӽ÷� ����ų ������ ���� �� ���� �Ҵ�
	locaptr->info = newitem; //���ο� ��忡 info�� newitem�� ����
	locaptr->next = topptr; //�� �� ���(���� ��)�� ���ο� ����� next�� ����Ŵ
	topptr = locaptr; //���� ���ο� ��尡 �� �� �����
}
void linkedstack::pop() {
	if (isempty()) {
		throw emptystack();
	}
	nodetype* tempptr = topptr; //���� �� �� ����� �ּҸ� �ӽ� ������ ������ ����
	topptr = topptr->next; //���� ���� ����� ���� ��尡 �� �� ����
	delete tempptr; //�ӽ� ������ ���� ��带 �����ϰ� ������
}
itemtype linkedstack::top() {
	if (isempty()) {
		throw emptystack();
	}
	return topptr->info; //�� �� ����� info�� ��ȯ���ָ� ��
}
bool linkedstack::isfull() const {
	nodetype* locaptr;
	try {
		locaptr = new nodetype;
		delete locaptr;
		return false; //���������� ���ο� ��尡 �Ҵ�ǰ� ���ŵǸ� ���� �޸� �γ�����?
	}
	catch (std::bad_alloc exception) { 
		return true; //�޸𸮰� ��� �������� �� ������
	}
}
bool linkedstack::isempty() const {
	return (topptr == NULL); //topptr�� ���̸� �����
}
linkedstack::linkedstack() {
	topptr = NULL; //ó���� �ƹ� ��嵵 ������ topptr�� ����
}
linkedstack::~linkedstack() {
	//������ ���� �� topptr�� ����Ű�� ��尡 �� �׾ �޸� ���� �߻�
	nodetype* tempptr; //�ֱ��� pop�� ����Ѵٰ� �����ϸ� ���� (���� ���� �˴� �׿��� �ϴ� ���� pop�� ���°� ����)
	while (topptr != NULL) {
		tempptr = topptr;
		topptr = topptr->next;
		delete tempptr;
	}
}
//### �ǽ� ###
void linkedstack::replaceitem(itemtype olditem, itemtype newitem) {
	nodetype* location = topptr;
	while (location != NULL) {
		if (location->info == olditem) {
			location->info = newitem;
			location = location->next;
		}
		else {
			location = location->next;
		}
	}
}
//�Ǵ� �ӽ� ���� �ϳ��� �� �����ؼ� ������ ������ ��ȭ��Ű�� �Ͷ߸��鼭 �ٽ� �����ϴ� ���
//Queue�� �̰Ͱ� �Ȱ���

