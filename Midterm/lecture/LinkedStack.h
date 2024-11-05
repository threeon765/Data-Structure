//### LInked Stack ADT ���� ###
#pragma once

typedef int itemtype; //itemtype�� int�� ��Ī���� ���
struct nodetype {
	itemtype info;
	nodetype* next;
};

/* //���ø� Ŭ������ �ۼ��� ���
template <class itemtype>
class nodetype {
	itemtype info;
	nodetype* next;
};
*/

class fullstack {}; //�߰�ȣ ����� ������Ÿ������ �ν� �ȵ�
class emptystack {};
class linkedstack {
public:
	linkedstack();
	~linkedstack();
	bool isfull() const;
	bool isempty() const;
	void push(itemtype item);
	void pop();
	itemtype top();
	void replaceitem(itemtype olditem, itemtype newitem);
private:
	nodetype* topptr; //�� �� ��带 ����Ŵ
};
