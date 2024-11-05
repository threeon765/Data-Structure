//꽉 텅 퍼스트 라스트 낫띵 듀플 아웃 제너럴
//템플릿 사용 시 h에 그냥 몰아서 쓸 것
//코드 검증 시 print 제작 권장, 생성자는 반드시 만들어야함
//자료형이 안 써지면 해봐야할 것 1. std를 붙여본다 2. 라이브러리를 추가한다
//디버깅 가비지 파일 때문에 빌드가 안되면 빌드 - 솔루션 정리 사용

#pragma once
#include <string>
#include <iostream>
using namespace std;

struct ItemType {
	string item;
	ItemType* next;
	ItemType* back;
};

class NStack {
/*
doubly linked list
ItemType = Node
*/
	ItemType* data;
public:
	NStack(); 
	NStack(NStack&);
	//~NStack(); //소멸자 안 만들었는데 이렇게 넣어주면 오류 생김
	bool nmPush(int, int, string);
	bool nmPop(int, int, string&);
	void print();
};

NStack::NStack() { //코드 검증하려면 생성자는 만들어주는게 좋지
	data = NULL;
}

NStack::NStack(NStack& Copy) { //모든 복사 생성자는 이렇게 만들면 OK
	ItemType *pasteptr, *copyptr, *temptr;
	copyptr = Copy.data;
	if (copyptr == NULL) { //텅
		pasteptr = NULL;
	}
	else { //!텅
		pasteptr = new ItemType; //첫 노드 제작
		pasteptr->item = copyptr->item;
		pasteptr->back = NULL;
		pasteptr->next = NULL;
		data = pasteptr;
		copyptr = copyptr->next;
		while (copyptr != NULL) { //이후 노드 제작
			temptr = new ItemType;
			temptr->item = copyptr->item;
			temptr->back = pasteptr;
			pasteptr->next = temptr;
			pasteptr = pasteptr->next;
			copyptr = copyptr->next;
		}
		pasteptr->next = NULL;
	}
}

void NStack::print() { //모든 print는 이렇게 만들면 OK
	ItemType* locaptr = data;
	while (locaptr != NULL) {
		cout << locaptr->item << ", ";
		locaptr = locaptr->next;
	}
	cout << endl;
}

bool NStack::nmPush(int n, int m, string x) {
	ItemType* locaptr;
	ItemType* newptr;
	locaptr = data;
	if (locaptr == NULL) { //텅
		if (n == 0 && m == 0) { //부동
			newptr = new ItemType;
			newptr->item = x;
			newptr->back = NULL;
			newptr->next = NULL;
			data = newptr; //직접 data가 가리키도록 하는 것이 좋음
			return true;
		}
		else { //유동
			return false;
		}
	}
	else {
		int length = 0;
		while (locaptr != NULL) { //텅
			locaptr = locaptr->next;
			length++;
		}
		locaptr = data;
		if (n >= m && n <= length) { //!텅
			newptr = new ItemType;
			newptr->item = x;
			if (n - m == 0) { //퍼스트
				newptr->next = locaptr;
				newptr->back = NULL;
				locaptr->back = newptr;
				data = newptr;
			}
			else if (n - m == length) { //라스트
				while (locaptr->next != NULL) {
					locaptr = locaptr->next;
				}
				newptr->next = NULL;
				newptr->back = locaptr;
				locaptr->next = newptr;
			}
			else { //제너럴
				for (int i = 0; i < n - m; i++) {
					locaptr = locaptr->next;
				}
				newptr->next = locaptr;
				newptr->back = locaptr->back;
				(locaptr->back)->next = newptr;
				locaptr->back = newptr;
			}
			return true;
		}
		else {
			return false;
		}
	}
}

bool NStack::nmPop(int n, int m, string& x) {
	ItemType* locaptr;
	locaptr = data;
	if (locaptr == NULL) {
		return false;
	}
	else {
		int length = 0;
		while (locaptr != NULL) {
			locaptr = locaptr->next;
			length++;
		}
		locaptr = data;
		if (n >= m && n < length) { //!텅
			if (n - m == 0) { //퍼스트
				(locaptr->next)->back = NULL;
				data = locaptr->next;
			}
			else if (n - m == length - 1) { //라스트
				while (locaptr->next != NULL) {
					locaptr = locaptr->next;
				}
				(locaptr->back)->next = NULL;
			}
			else { //제너럴
				for (int i = 0; i < n - m; i++) {
					locaptr = locaptr->next;
				}
				(locaptr->back)->next = locaptr->next;
				(locaptr->next)->back = locaptr->back;
			}
			x = locaptr->item;
			delete locaptr;
			return true;
		}
		else {
			return false;
		}
	}
}
//###################################################
#pragma once
#include <new>
#include <iostream>

template <class itemtype>
struct nodetype {
	itemtype info;
	nodetype* next;
};

template <class itemtype>
class ReverseSortedType {
public:
	ReverseSortedType();
	void insertitem(itemtype item);
	void print();
	itemtype fRank(int index);
	itemtype bRank(int index);
private:
	nodetype<itemtype>* listptr;
	nodetype<itemtype>* currentptr;
	int length;
};

template <class itemtype>
ReverseSortedType<itemtype>::ReverseSortedType() {
	length = 0;
	listptr = NULL;
	currentptr = NULL;
}
template <class itemtype>
void ReverseSortedType<itemtype>::print() { //모든 print는 이렇게 만들면 OK
	nodetype<itemtype>* locaptr = listptr;
	while (locaptr != NULL) {
		std::cout << locaptr->info << ", ";
		locaptr = locaptr->next;
	}
	std::cout << std::endl;
}
template <class itemtype>
void ReverseSortedType<itemtype>::insertitem(itemtype item) {
	nodetype<itemtype>* locaptr = listptr;
	nodetype<itemtype>* predloca = NULL;
	bool found = false;
	nodetype<itemtype>* newptr = new nodetype<itemtype>;
	newptr->info = item;
	if (locaptr == NULL) { //텅 
		newptr->next = NULL;
		listptr = newptr;
	}
	else { //!텅
		while (locaptr != NULL && (!found)) {
			if (locaptr->info > item) {
				predloca = locaptr;
				locaptr = locaptr->next;
			}
			else {
				found = true; //그 값 또는 그것보다 작은데 가장 큰 값을 가리킴
			}
		} //못 찾으면 NULL
	}
	if (predloca == NULL) { //퍼스트
		newptr->next = locaptr;
		listptr = newptr;
	}
	else if (locaptr == NULL) { //라스트 (& 낫띵)
		newptr->next = NULL;
		predloca->next = newptr;
	}
	else { //제너럴 (& 듀플)
		predloca->next = newptr;
		newptr->next = locaptr;
	}
	length++;
}
template <class itemtype>
itemtype ReverseSortedType<itemtype>::fRank(int index) {
	nodetype<itemtype>* locaptr = listptr;
	if (locaptr == NULL) {
		return -1;
	}
	else {
		for (int i = 1; i < index; i++) {
			if (locaptr == NULL) { //범위 벗어남
				return -1;
			}
			locaptr = locaptr->next;
		}
		if (locaptr == NULL) { //재검증
			return -1;
		}
		else {
			return locaptr->info; //허가
		}
	}
}
template <class itemtype>
itemtype ReverseSortedType<itemtype>::bRank(int index) {
	nodetype<itemtype>* locaptr = listptr;
	if (locaptr == NULL) { //텅
		return -1;
	}
	else {
		int length = 0; //간이 length 만들기
		while (locaptr != NULL) {
			locaptr = locaptr->next;
			length++;
		}
		for (int i = index; i < length; i++) {
			if (locaptr == NULL) { //범위 벗어남
				return -1;
			}
			locaptr = locaptr->next;
		}
		if (locaptr == NULL) { //재검증
			return -1;
		}
		else {
			return locaptr->info; //허가
		}
	}
}
//###################################################
#pragma once
#include <new>
#include <iostream>

template <class itemtype>
struct nodetype {
	itemtype info;
	nodetype* next;
};

template <class itemtype>
class lusl {
public:
	lusl();
	void insertitem(itemtype item);
	void deleteitem(itemtype item);
	void survive(int n, int k);
	void print();
private:
	nodetype<itemtype>* listptr;
	int length;
};

template <class itemtype>
lusl<itemtype>::lusl() {
	length = 0;
	listptr = NULL;
}
template <class itemtype>
void lusl<itemtype>::insertitem(itemtype item) {
	nodetype<itemtype>* newptr = new nodetype<itemtype>;
	newptr->info = item;
	if (listptr == NULL) { //텅
		newptr->next = NULL;
		listptr = newptr;
	}
	else {
		newptr->next = listptr;
		listptr = newptr;
	}
	length++;
}
template <class itemtype>
void lusl<itemtype>::deleteitem(itemtype item) {
	nodetype<itemtype>* locaptr = listptr;
	nodetype<itemtype>* tempptr = listptr;
	if (locaptr != NULL) { //텅
		if (listptr->info == item) { //퍼스트, 퍼스트&라스트
			tempptr = locaptr->next;
			listptr = tempptr;
			item = locaptr->info; //넣어주는거 까먹지마
			delete locaptr;
			length--;
		}
		else {
			while (locaptr != NULL) { //낫띵 - NULL, 라스트&제너럴 - 대상위치
				if (item == locaptr->info) {
					break;
				}
				else {
					tempptr = locaptr;
					locaptr = locaptr->next;
				}
			}
			if (locaptr != NULL) { //!낫띵
				tempptr->next = locaptr->next;
				item = locaptr->info;
				delete locaptr;
				length--;
			}
		}
	}
}
template <class itemtype>
void lusl<itemtype>::print() {
	nodetype<itemtype>* locaptr = listptr;
	while (locaptr != NULL) {
		std::cout << locaptr->info << " ";
		locaptr = locaptr->next;
	}
	std::cout << std::endl;
}
template <class itemtype>
void lusl<itemtype>::survive(int n, int k) {
	for (int i = n; i >= 1; i--) {
		insertitem(i);
	}
	nodetype<itemtype>* locaptr = listptr;
	nodetype<itemtype>* tempptr = NULL;
	while (locaptr->next != NULL) {
		locaptr = locaptr->next;
	}
	locaptr->next = listptr; //circular화
	locaptr = locaptr->next;
	while (length > 1) {
		for (int i = 1; i < k; i++) {
			tempptr = locaptr;
			locaptr = locaptr->next;
		}
		std::cout << (locaptr->info) << " ";
		deleteitem(locaptr->info);
		locaptr = tempptr->next;
	}
	std::cout << (listptr->info) << " ";
	deleteitem(listptr->info);
	std::cout << std::endl;
}
//###################################################
#pragma once
#include <new>
template<class itemtype>
struct nodetype {
	itemtype info;
	nodetype* next;
};

template<class itemtype>
class SortedType {
	nodetype<itemtype>* listptr;
	int length;
public:
	void insertitem(itemtype item) {
		nodetype<itemtype>* locaptr = listptr, predloca = NULL;
		bool found = false;
		nodetype<itemtype>* newptr = new nodetype<itemtype>;
		newptr->info = item;
		if (locaptr == NULL) { //텅 
			newptr->next = NULL;
			listptr = newptr;
		}
		else { //!텅
			while (locaptr != NULL && (!found)) {
				if (locaptr->info < item) {
					predloca = locaptr;
					locaptr = locaptr->next;
				}
				else {
					found = true;
				}
			} //못 찾으면 NULL
		}
		if (predloca == NULL) { //퍼스트
			newptr->next = locaptr;
			listptr = newptr;
		}
		else if (locaptr == NULL) { //라스트 (& 낫띵)
			newptr->next = NULL;
			predloca->next = newptr;
		}
		else { //제너럴 (& 듀플)
			predloca->next = newptr;
			newptr->next = locaptr;
		}
		length++;
	}
	template <class itemtype>
	void deleteitem(itemtype item) {
		nodetype<itemtype>* locaptr = listptr;
		nodetype<itemtype>* tempptr = listptr;
		if (locaptr != NULL) { //텅
			if (listptr->info == item) { //퍼스트, 퍼스트&라스트
				tempptr = locaptr->next;
				listptr = tempptr;
				item = locaptr->info; //넣어주는거 까먹지마
				delete locaptr;
				length--;
			}
			else {
				while (locaptr != NULL) { //낫띵 - NULL, 라스트&제너럴 - 대상위치
					if (item == locaptr->info) {
						break;
					}
					else {
						tempptr = locaptr;
						locaptr = locaptr->next;
					}
				}
				if (locaptr != NULL) { //!낫띵
					tempptr->next = locaptr->next;
					item = locaptr->info;
					delete locaptr;
					length--;
				}
			}
		}
	}
};
//###################################################
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
#include "Palindrome.h"
#include <iostream>

int main() {
	char myStr[100];
	std::cin >> myStr;
	if (isPalindrome(myStr) == true) {
		std::cout << "It's a palindrome.\n";
	}
	else {
		std::cout << "It's NOT a palindrome.\n";
	}
	return 0;
}
//###################################################
#include <iostream>
#include <cstring>
#include <string>
template<class itemtype>
struct nodetype {
	itemtype info;
	nodetype* next;
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

int main() {
	std::string str;
	queue<char> digit;
	queue<char> opera;
	char check;
	bool needmore = true;
	//int length = strlen(str); //str이 array였으면 이거 쓰고
	std::getline(std::cin, str);
	str += ' ';
	for (int i = 0; i < str.length(); i++) {
		if (isdigit(str[i])) {
			digit.enqueue(str[i]);
			needmore = false;
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '%') {
			opera.enqueue(str[i]);
			needmore = true;
		}
		else if (str[i] == ' ') {
			while (!digit.isempty()) {
				digit.dequeue(check);
				std::cout << check;
			}
			if (needmore == false) {
				while (!opera.isempty()) {
					opera.dequeue(check);
					std::cout << check;
				}
			}
		}
	}
}
//###################################################
#include <string>
string str;
std::getline(std::cin, str); 
//그냥 cin은 공백을 못받지만 이건 받음
str.length()
str.empty() //bool
str.insert(n, str) //n index 앞에 삽입
str.clear()
str.erase(n, m) //n index부터 m개 지움
stoi() //string->int
to_string(n) //int->string
#include <cstring>
strcmp() - 문자열 비교
strlen() - 문자열의 길이
strcpy() - 문자열 복사
strcat() - 문자열의 연결
cin.getline(char a[n], n, '\n') 
//\0 미포함 \n 만날때까지 넣기 (배열 스트링도 가능)