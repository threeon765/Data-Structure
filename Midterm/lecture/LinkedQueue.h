//### LInked Queue ADT ���� ###
#pragma once
template <class itemtype> //template���� ������ ���
struct nodetype {
	itemtype info;
	nodetype* next;
};

class fullqueue {};
class emptyqueue {};
template <class itemtype>
class linkedqueue {
public:
	linkedqueue();
	~linkedqueue();
	bool isfull() const;
	bool isempty() const;
	void makeempty();
	void enqueue(itemtype item);
	void dequeue(itemtype &item);
	void mindequeue(itemtype& item);
private:
	nodetype<itemtype>* frontptr; //���� ��带 ����Ŵ
	nodetype<itemtype>* rearptr; //«�� ��带 ����Ŵ
	//�̰͸� ����ϸ� �ȴ�: ���̸� �� �� ��, �ƴϸ� �� �� �� �ƴ�
};
