//### LInked Stack ADT 명세서 ###
#pragma once

typedef int itemtype; //itemtype을 int의 별칭으로 사용
struct nodetype {
	itemtype info;
	nodetype* next;
};

/* //템플릿 클래스로 작성할 경우
template <class itemtype>
class nodetype {
	itemtype info;
	nodetype* next;
};
*/

class fullstack {}; //중괄호 써줘야 프로토타입으로 인식 안됨
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
	nodetype* topptr; //맨 위 노드를 가리킴
};
