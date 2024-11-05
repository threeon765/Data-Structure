//### LInked Queue ADT 명세서 ###
#pragma once
template <class itemtype> //template으로 구현할 경우
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
	nodetype<itemtype>* frontptr; //고참 노드를 가리킴
	nodetype<itemtype>* rearptr; //짬찌 노드를 가리킴
	//이것만 명심하면 된다: 텅이면 둘 다 널, 아니면 둘 다 널 아님
};
