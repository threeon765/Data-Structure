#include "LinkedQueue.h"
#include <new> //NULL을 \0로 사용하기 위한 전처리문
//### 기본 메서드 ### (수업 자료 순서로 작성)
template<class itemtype>
bool linkedqueue<itemtype>::isfull() const { //원리가 똑같죠 신병 넣다 빼기가 안되면 꽉
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
bool linkedqueue<itemtype>::isempty() const { //어찌보면 당연하죠 짬찌와 고참 둘 다 없어야 텅
	return (frontptr == NULL && rearptr == NULL);
}
template<class itemtype>
linkedqueue<itemtype>::linkedqueue() {
	frontptr = NULL;
	rearptr = NULL;
} 
template<class itemtype>
void linkedqueue<itemtype>::makeempty() { //고참 순으로 싹 다 전역시켜서 부대를 텅
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
linkedqueue<itemtype>::~linkedqueue() { //소멸자도 똑같지 죄다 전역
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
		newptr->next = NULL; //신병 노드 완성
		if (rearptr == NULL) { //짬찌마저도 없다면, 즉 텅이었으면
			front = newptr; //신병이 곧 최고참이자 짬찌
		}
		else { //짬찌가 있으면
			rearptr->next = newptr; //짬찌 뒤에 신병 연결
			//newptr->next = frontptr; //circular라면 신병과 고참도 연결
		}
		rearptr = newptr; //이제 신병이 짬찌 ㅋㅋ
	}
}
template<class itemtype>
void linkedqueue<itemtype>::dequeue(itemtype &item) {
	if (isempty()) {
		throw emptyqueue();
	}
	else {
		nodetype<itemtype>* tempptr = frontptr; //전역할 고참 노드 임시 보관
		item = frontptr->info; //item에 고참 노드 정보 좀 뽑고
		frontptr = frontptr->next; //이제 전역할 고참 노드 밑 노드가 고참 노드로
		if (frontptr == NULL) { //어라 이제 밑 노드가 없네
			rearptr = NULL; //텅으로 서비스 종료다...
		}
		else {
			//rearptr->next = frontptr; //circular라면 새로운 고참 노드와 짬찌 노드 연결
		}
		delete tempptr; //안전하게 전역
	}
}
/*
circular에 대해서 생각해보자
array와는 다르게 front를 위해 공간 하나를 낭비할 필요도 없다
단지 rear->next = front이면 되는거다
근데 이걸 왜 함? 버러지 짓거리...
*/
//### 실습 ###
template<class itemtype>
void linkedqueue<itemtype>::mindequeue(itemtype& item) { //최소값을 빼기
	if (isempty()) {
		throw emptyqueue();
	}
	else {		
		nodetype<itemtype>* locaptr = frontptr, temptr, minptr = frontprt;
		while (locaptr != NULL) { //최소값 위치 찾기
			if (locaptr->info < minptr->info) {
				minptr = locaptr;
				item = minptr->info; //최소값은 이새끼에요
			}
			locaptr = locaptr->next;
		}
		locaptr = frontptr;
		while (locaptr == minptr) { //최소값 위치 loca, 최소값 전 위치 temp
			temptr = locaptr;
			locaptr = locaptr->next;
		}
		temptr->next = locaptr->next;
		minptr = NULL; //댕글링 방지
		delete temptr; //죽여
	}
}
