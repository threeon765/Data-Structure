#pragma once
#include <iostream>
#include <ctype.h>

template<class itemtype>
struct nodetype {
	itemtype info;
	nodetype* next;
};

template<class itemtype>
class stack {
	nodetype<itemtype>* topptr;
public:
	stack() { //생성자는 매우매우매우 중요합니다...
		topptr = NULL;
	}
	bool isempty() const {
		return (topptr == NULL);
	}
	void push(itemtype item) {
		nodetype<itemtype>* locaptr; 
		locaptr = new nodetype<itemtype>;
		locaptr->info = item;
		locaptr->next = topptr;
		topptr = locaptr;
	}
	void pop() {
		if (!isempty()) {
			nodetype<itemtype>* locaptr = topptr;
			topptr = topptr->next;
			delete locaptr;
		}
	}
	itemtype top() {
		if (!isempty()) {
			return topptr->info;
		}
	}
	void print() {
		nodetype<itemtype>* locaptr = topptr;
		while (locaptr != NULL) {
			std::cout << locaptr->info << " ";
			locaptr = locaptr->next;
		}
		std::cout << std::endl;
	}
};

template<class itemtype>
class queue {
	nodetype<itemtype>* front;
	nodetype<itemtype>* rear;
public:
	queue() {
		front = NULL;
		rear = NULL;
	}
	bool isempty() const {
		return (rear == NULL && front == NULL);
	}
	void enqueue(itemtype item) {
		nodetype<itemtype>* newptr = new nodetype<itemtype>;
		newptr->info = item;
		newptr->next = NULL;
		if (isempty()) {
			front = newptr;
			rear = newptr;
		}
		else {
			rear->next = newptr;
		}
		rear = newptr;
	}
	void dequeue(itemtype& item) {
		if (!isempty()) {
			nodetype<itemtype>* locaptr = front;
			item = front->info;
			front = front->next;
			if (front == NULL) { //텅
				rear = NULL;
			}
			delete locaptr;
		}
	}
	void print() {
		nodetype<itemtype>* locaptr = front;
		while (locaptr != NULL) {
			std::cout << locaptr->info << " ";
			locaptr = locaptr->next;
		}
		std::cout << std::endl;
	}
};


bool isPalindrome(char* myStr) {
	stack<char> s;
	queue<char> q;
	int index = 0;
	while (myStr[index] != '\0') { //강의에 써있는게 틀림 ㅋㅋ
		if (myStr[index] != '\n') {
			if (isalpha(myStr[index])) {
				s.push(toupper(myStr[index]));
				q.enqueue(toupper(myStr[index]));
			}
			else {
				s.push(myStr[index]);
				q.enqueue(myStr[index]);
			}
		}
		index++;
	}
	char sitem, qitem;
	int mismatch = 0;
	while ((!q.isempty()) && (!s.isempty())) {
		sitem = s.top();
		s.pop();
		q.dequeue(qitem);
		if (sitem != qitem) {
			mismatch++;
		}
	}
	if (mismatch == 0) {
		return true;
	}
	else {
		return false;
	}
	return false;
}