#include "LinkedStack.h"
#include <new> //NULL을 \0로 사용하기 위한 전처리문
//### 기본 메서드 ### (수업 자료 순서로 작성)
void linkedstack::push(itemtype newitem) {
	if (isfull()) {
		throw fullstack();
	}
	nodetype* locaptr = new nodetype; //새로운 노드의 주소를 임시로 가리킬 포인터 선언 및 동적 할당
	locaptr->info = newitem; //새로운 노드에 info로 newitem을 넣음
	locaptr->next = topptr; //맨 위 노드(였던 것)을 새로운 노드의 next가 가리킴
	topptr = locaptr; //이제 새로운 노드가 맨 위 노드임
}
void linkedstack::pop() {
	if (isempty()) {
		throw emptystack();
	}
	nodetype* tempptr = topptr; //버릴 맨 위 노드의 주소를 임시 보관할 포인터 선언
	topptr = topptr->next; //이제 버릴 노드의 다음 노드가 맨 위 노드로
	delete tempptr; //임시 보관한 버릴 노드를 안전하게 지워줌
}
itemtype linkedstack::top() {
	if (isempty()) {
		throw emptystack();
	}
	return topptr->info; //맨 위 노드의 info를 반환해주면 끝
}
bool linkedstack::isfull() const {
	nodetype* locaptr;
	try {
		locaptr = new nodetype;
		delete locaptr;
		return false; //정상적으로 새로운 노드가 할당되고 제거되면 아직 메모리 널널하쥬?
	}
	catch (std::bad_alloc exception) { 
		return true; //메모리가 없어서 오류나면 꽉 찬거지
	}
}
bool linkedstack::isempty() const {
	return (topptr == NULL); //topptr이 널이면 빈거지
}
linkedstack::linkedstack() {
	topptr = NULL; //처음엔 아무 노드도 없으니 topptr이 널임
}
linkedstack::~linkedstack() {
	//스택이 뒤질 때 topptr이 가리키던 노드가 안 죽어서 메모리 누수 발생
	nodetype* tempptr; //텅까지 pop을 계속한다고 생각하면 좋음 (예외 없이 죄다 죽여야 하니 직접 pop을 쓰는건 별로)
	while (topptr != NULL) {
		tempptr = topptr;
		topptr = topptr->next;
		delete tempptr;
	}
}
//### 실습 ###
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
//또는 임시 스택 하나를 더 생성해서 넣을때 아이템 변화시키고 터뜨리면서 다시 저장하는 방식
//Queue도 이것과 똑같다

