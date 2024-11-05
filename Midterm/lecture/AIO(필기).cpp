#include <iostream>
const int MAX_ITEMS = 200;
class Double_Stack {
private:
	int top_small = -1;
	int top_big = MAX_ITEMS;
	int items[MAX_ITEMS];
public:
	bool IsFull() {
		return ((top_small + 1 == top_big)||(top_small > top_big));
	}
	void Push(int item) {
		if (!(IsFull())) {
			if (item < 1000) {
				top_small++;
				items[top_small] = item;
			}
			else {
				top_big--;
				items[top_big] = item;
			}
		}
		else {
			std::cout << "This stack is Full" << std::endl;
		}
	}
	void Print() {
		for (int i = top_small; i > -1; i--) {
			std::cout << items[i] << ", ";
		}
		std::cout << std::endl;
		for (int i = top_big; i < MAX_ITEMS; i++) {
			std::cout << items[i] << ", ";
		}
		std::cout << std::endl;
	}
};
//###################################################
#include "SortedList.h"
#include <new>
template <class itemtype>
bool sl<itemtype>::isfull() const {
	return (length == max);
}
template <class itemtype>
int sl<itemtype>::lengthis() const {
	return length;
}
template <class itemtype>
sl<itemtype>::sl() {
	length = 0;
}
template <class itemtype>
void sl<itemtype>::retrieveitem(itemtype& item, bool& found) {
	bool moreToSearch, found = false;
	int loca = 0;
	moreToSearch = (loca < length);
	while (moreToSearch && !found) { //위치 찾기
		if (item > info[loca]) {
			loca++;
			moreToSearch; = (loca < length);
		}
		else if (item == info[loca]) { //찾음
			moreToSearch = false;
			found = true;
		}
		else { //없음
			moreToSearch = false;
		}
	}
}
template <class itemtype>
void sl<itemtype>::insertitem(itemtype item) {
	bool moreToSearch;
	int loca = 0;
	moreToSearch = (loca < length);
	while (moreToSearch) { //위치 찾기
		if (item >= info[loca]) {
			loca++;
			moreToSearch; = (loca < length);
		}
		else {
			moreToSearch = false;
		}
	}
	for (int i = length; i > loca; i--) { //자자 옆으로 한 칸씩 가세요
		info[i] = info[i - 1];
	}
	info[loca] = item; //넣을게~
	length++;
}
template <class itemtype>
void sl<itemtype>::deleteitem(itemtype item) {
	bool moreToSearch;
	int loca = 0;
	moreToSearch = (loca < length);
	while (moreToSearch) { //위치 찾기
		if (item >= info[loca]) {
			loca++;
			moreToSearch; = (loca < length);
		}
		else {
			moreToSearch = false;
		}
	}
	if (loca < length) { //낫띵 케이스 쳐내고
		for (int i = loca; i < length - 1; i++) { //자자 옆으로 한 칸씩 오세요
			info[i] = info[i + 1];
		}
		length--;
	}
	if (info[loca + 1] == item) { //오버랩 케이스
		deleteitem(item); //시간 복잡도 O(N^2)
	}
}
template<class itemtype>
void sl<itemtype>::getnextitem(itemtype& item) {
	currentpos++;
	item = info[currentpos];
}
template <class itemtype>
void sl<itemtype>::resetlist() {
	currentptr = -1;
}
template <class itemtype> //binary search
void sl<itemtype>::binretrieveitem(itemtype& item, bool& found) {
	bool moreToSearch;
	found = false;
	int mid;
	int first = 0;
	int last = length - 1;
	moreToSearch = (first <= last);
	while (moreToSearch && !found) { //위치 찾기
		mid = (first + last) / 2;
		if (item == info[mid]) {
			found = true;
		}
		else if (item > info[mid]) {
			first = mid;
			moreToSearch = (first <= last);
		}
		else if (item < info[mid]) {
			last = mid;
			moreToSearch = (first <= last);
		}
	}
}
//###################################################
#include "LinkedUnsortedList.h"
#include <new>
template <class itemtype>
bool lusl<itemtype>::isfull() const { //넌 지겹다 이젠
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
template <class itemtype>
int lusl<itemtype>::lengthis() const {
	return length;
}
template <class itemtype>
lusl<itemtype>::lusl() {
	length = 0;
	listptr = NULL;
	currentptr = NULL;
}
template <class itemtype>
void lusl<itemtype>::retrieveitem(itemtype& item, bool& found) { //아이템을 찾아요~
	nodetype<itemtype>* locaptr = listptr; //맨 앞 노드를 시작으로
	found = false; //아직 못 찾았죠
	bool more2search = (locaptr != NULL); //리스트 다 돌았나?
	while (more2search && !found) { //찾은데다가 다 돌때까지 (이건 없으면 무한 루프네)
		if (locaptr->info == item) {
			found = true; //찾았다!!
		}
		else { //뭐야 아니야?
			locaptr = locaptr->next; //다음꺼보자
			more2search = (locaptr != NULL); //근데 다음꺼있냐?
		}
	}
}
template <class itemtype>
void lusl<itemtype>::insertitem(itemtype item) { //맨 앞 노드를 새로운 노드로!
	nodetype<itemtype>* newptr = new nodetype<itemtype>;
	newptr->info = item;
	newptr->next = listptr;
	listptr = newptr;
	length++;
}
template <class itemtype>
void lusl<itemtype>::deleteitem(itemtype item) { //찾아 죽이기!
	nodetype<itemtype>* locaptr = listptr;
	nodetype<itemtype>* tempptr;
	if (listptr->info == item) { //야 처음부터 찾았는데?
		tempptr = locaptr;
		listptr = listptr->next; //죽일 노드 임시 보관하고 끊어버려
	}
	else { //없어?
		while (!(item == (locaptr->next)->info)) { //죽일 노드 직전 노드까지만 이동해 (없으면 무한 루프)
			locaptr = locaptr->next;
		}
		tempptr = locaptr->next; //죽일 노드 임시 보관해
		locaptr->next = (locaptr->next)->next; //죽일 노드 직전 노드랑 죽일 노드 직후 노드랑 연결해
	}
	delete tempptr; //죽여!
	length--;
}

template <class itemtype>
void lusl<itemtype>::makeempty() {
	nodetype<itemtype>* tempptr = listptr;
	while (length != 0) {
		listptr = listptr->next;
		delete tempptr;
		length--;
	}
}
template <class itemtype>
lusl<itemtype>::~lusl() {
	makeempty();
}

template<class itemtype>
void lusl<itemtype>::getnextitem(itemtype& item) { //리스트 안 부수고 아이템 먹기
	if (currentptr == NULL) {
		currentptr = listptr;
	}
	else {
		currentptr = currentptr->next;
	}
	item = currentptr->info;
}
template <class itemtype>
void lusl<itemtype>::resetlist() { //아이템을 먹기 위한 위치 리셋
	currentptr = NULL;
}
//###################################################
#include "LinkedSortedList.h"
#include <new>
template <class itemtype>
bool lsl<itemtype>::isfull() const { //넌 지겹다 이젠
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
template <class itemtype>
int lsl<itemtype>::lengthis() const {
	return length;
}
template <class itemtype>
lsl<itemtype>::lsl() {
	length = 0;
	listptr = NULL;
	currentptr = NULL;
}
template <class itemtype>
void lsl<itemtype>::retrieveitem(itemtype& item, bool& found) { //아이템을 찾아요~
	nodetype<itemtype>* locaptr = listptr; //맨 앞 노드를 시작으로
	found = false; //아직 못 찾았죠
	bool more2search = (locaptr != NULL); //리스트 다 돌았나?
	while (more2search && !found) {
		if (locaptr->info < item) { //sorted니까 좀 효율적으로 가자
			locaptr = locaptr->next;
			more2search = (locaptr != NULL);
		}
		else if (locaptr->info == item) { //찾음 ㅇㅇ
			found = true;
		}
		else { //얘 없는데요?
			locaptr = NULL; //그럼 끝내 ㅇㅇ
		}
	}
}
template <class itemtype>
void lsl<itemtype>::insertitem(itemtype item) {
	nodetype<itemtype>* locaptr = listptr, predloca = NULL; //먼저 어디다 넣어야 하는지 찾자고
	bool found = false;
	while (locaptr != NULL && (!found)) { //못 찾았는데 아직 갈 길이 있는가?
		if (locaptr->info < item) { //아직 작다!
			predloca = locaptr; //따라갑니다!
			locaptr = locaptr->next; //더 간다!
		}
		else if { //어! 더 크다!
			found = true; //찾았다!
		}
	}
	nodetype<itemtype>* newptr = new nodetype<itemtype>;
	newptr->info = item; //새로 만들고!
	if (predloca == NULL) { //근데 처음부터 찾으셨는데요?
		newptr->next = locaptr; //그럼 Unsorted처럼 하면 되지!
		listptr = newptr;
	}
	else {
		predloca->next = newptr; //연결하겠습니다!
		newptr->next = locaptr;
	}
	length++;
}
template <class itemtype>
void lsl<itemtype>::deleteitem(itemtype item) { //찾아 죽이기! 비정렬이랑 똑같다!
	nodetype<itemtype>* locaptr = listptr;
	nodetype<itemtype>* tempptr;
	if (listptr->info == item) { //야 처음부터 찾았는데?
		tempptr = locaptr;
		listptr = listptr->next; //죽일 노드 임시 보관하고 끊어버려
	}
	else { //없어?
		while (!(item == (locaptr->next)->info)) { //죽일 노드 직전 노드까지만 이동해 (없으면 무한 루프)
			locaptr = locaptr->next;
		}
		tempptr = locaptr->next; //죽일 노드 임시 보관해
		locaptr->next = (locaptr->next)->next; //죽일 노드 직전 노드랑 죽일 노드 직후 노드랑 연결해
	}
	delete tempptr; //죽여!
	length--;
}

template <class itemtype>
void lsl<itemtype>::makeempty() {
	nodetype<itemtype>* tempptr = listptr;
	while (length != 0) {
		listptr = listptr->next;
		delete tempptr;
		length--;
	}
}
template <class itemtype>
lsl<itemtype>::~lsl() {
	makeempty();
}

template<class itemtype>
void lsl<itemtype>::getnextitem(itemtype& item) { //리스트 안 부수고 아이템 먹기
	if (currentptr == NULL) {
		currentptr = listptr;
	}
	else {
		currentptr = currentptr->next;
	}
	item = currentptr->info;
}
template <class itemtype>
void lsl<itemtype>::resetlist() { //아이템을 먹기 위한 위치 리셋
	currentptr = NULL;
}
//### 실습 ###
template <class itemtype> //복사 생성자
lsl<itemtype>::lsl(const lsl<itemtype>& another) {
	makeempty();
	if (another.listptr == NULL) {
		listptr = NULL;
	}
	else {
		listptr = new nodetype<itemtype>;
		listptr->info = another.listptr->info;
		nodetype<itemtype>* oldptr = another.listptr->next;
		nodetype<itemtype>* newptr = listptr;
		while (oldptr != NULL) {
			newptr->next = new nodetype<itemtype>;
			newptr = newptr->next;
			newptr->info = oldptr->info;
			oldptr = oldptr->next;
		}
		newptr->next = NULL;
	}	
}
template <class itemtype> //length로 위치 접근 + 복사한 요소로 복사
void lsl<itemtype>::reverse() {
	nodetype<itemtype>* locaptr = listptr;
	lsl<itemtype> templsl(*this);
	nodetype<itemtype>* tempptr = templsl.listptr;
	for (int i = length - 1; i > -1; i--) {
		locaptr = listptr;
		for (int j = 0; j < i; j++) {
			locaptr = locaptr->next;
		}
		locaptr->info = tempptr->info;
		tempptr = tempptr->next;
	}
	templsl.makeempty();
}
//또는 스택을 사용 가능하면 차례대로 스택에 넣고 
//스택을 폭발시키면서 다시 원본에 넣기
template <class itemtype>
void lsl<itemtype>::merge(lsl<itemtype> other, lsl<itemtype>& result) { //대소 비교 후 작은 놈만 넣음
	nodetype<itemtype>* thisptr = listptr;
	nodetype<itemtype>* otherptr = other.listptr;
	nodetype<itemtype>* resultptr = result.listptr;
	if (resultptr == NULL) {
		resultptr = new nodetype<itemtype>;
	}
	while (thisptr != NULL && otherptr != NULL) {
		if (resultptr->next = NULL) {
			resultptr->next = new nodetype<itemtype>;
		}
		if (thisptr > otherptr) {
			otherptr->info = resultptr->info;
			resultptr = resultptr->next;
			otherptr = otherptr->next;
		}
		else if (thisptr < otherptr) {
			thisptr->info = resultptr->info;
			resultptr = resultptr->next;
			thisptr = thisptr->next;
		}
		else {
			thisptr->info = resultptr->info;
			resultptr = resultptr->next;
			thisptr = thisptr->next;
			otherptr = otherptr->next;
		}
	}
	while (thisptr != NULL) { //잔반 처리
		if (resultptr->next = NULL) {
			resultptr->next = new nodetype<itemtype>;
		}
		thisptr->info = resultptr->info;
		resultptr = resultptr->next;
		thisptr = thisptr->next;
	}
	while (otherptr != NULL) {
		if (resultptr->next = NULL) {
			resultptr->next = new nodetype<itemtype>;
		}
		otherptr->info = otherptr->info;
		resultptr = resultptr->next;
		otherptr = otherptr->next;
	}
}
//또는 currentptr 관련 함수를 통해 아이템을 뽑고 그냥 insert로 정렬하면 됨
template <class itemtype>
void lsl<itemtype>::deleteitem_ver2(itemtype item) {
	nodetype<itemtype>* locaptr = listptr;
	nodetype<itemtype>* tempptr;
	if (locaptr != NULL) {
		if (item == locaptr->info) { //퍼스트 케이스
			listptr = locaptr->next;
		}
		else {
			while (item != locaptr->info && locaptr != NULL) { //타겟 위치 - loca, 타겟 전 위치 - temp
				//낫띵 케이스의 무한 루프 위험 방지, 라스트 케이스도 만족
				temptr = locaptr;
				locaptr = locaptr->next;
			}
			if (locaptr != NULL) { //낫띵 케이스 배제
				tempptr->next = locaptr->next;
			}
		}
		delete locaptr;
		length--;
		if (tempptr->next->info == item) { //오버랩 케이스
			deleteitem_ver2(item); //똑같은 아이템으로 한 번 더 함수 돌려
		}
	}
}
//###################################################
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
//###################################################
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
//###################################################
#include "DoublyLinkedSortedList.h"
#include <new>
template <class itemtype>
bool dlsl<itemtype>::isfull() const { //넌 지겹다 이젠
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
template <class itemtype>
int dlsl<itemtype>::lengthis() const {
	return length;
}
template <class itemtype>
dlsl<itemtype>::dlsl() {
	length = 0;
	listptr = NULL;
	currentptr = NULL;
}
template <class itemtype>
void dlsl<itemtype>::finditem(itemtype& item, nodetype<itemtype>* locaptr, bool& found) { //아이템을 찾아요~
	locaptr = listptr;
	found = false;
	bool more2search = (locaptr != NULL);
	while (more2search && !found) {
		if (locaptr->info < item) {
			//locaptr = locaptr->next;
			//more2search = (locaptr != NULL);
			//라스트에서 locaptr이 NULL되어버리기 때문에 아이템 추가와 같은 추가 활동이 불가
			if (locaptr->next == NULL) {
				more2search = false;
			}
			else {
				locaptr = locaptr->next;
			}
			//locaptr이 NULL의 강을 건너는 것을 방지하는 코드
		}
		else if (locaptr->info == item) {
			found = true;
		}
		else {
			more2search = false;
		}
	}
}

template <class itemtype>
void dlsl<itemtype>::insertitem(itemtype item) {
	nodetype<itemtype>* locaptr; //back 개념까지 생겨서 tempptr이 필요가 없다
	nodetype<itemtype>* newptr = new nodetype<itemtype>;
	newptr->info = item;
	bool found;
	finditem(item, locaptr, found); //item과 같거나 바로 큰 놈 위치, 또는 라스트 반환
	//new 다음 loca를 건드려야 안전하게 변화 가능
	if (locaptr != NULL) {
		if (location->info >= item) {
			newptr->next = locaptr;
			newptr->back = locaptr->back;
			if (locaptr != listptr) { //제너럴 케이스
				locaptr->back->next = newptr;
			}
			else { //퍼스트 케이스
				listptr = newptr;
			}
			locaptr->back = newptr;
		}
		else { //라스트 케이스
			newptr->back = locaptr;
			newptr->next = NULL;
			locaptr->next = newptr;
		}
		/* //만약 모든 케이스를 찢어본다면
		if (locaptr == listptr) { //퍼스트 케이스
			newptr->next = locaptr;
			newptr->back = NULL;
			locaptr->back = newptr;
			listptr = newptr;
		}
		else if (locaptr->next == NULL) { //라스트 케이스
			newptr->back = locaptr;
			newptr->next = NULL;
			locaptr->next = newptr;
		}
		else { //제너럴 케이스
			newptr->back = locaptr->back; //반드시 순서를 지켜서 끊고 연결할 것
			newptr->next = locaptr;
			locaptr->back->next = newptr;
			locaptr->back = newptr;
		}
		*/
	}
	else { //텅 케이스
		newptr->back = NULL;
		newptr->next = NULL;
		listptr = newptr;
	}
	length++;
}
template <class itemtype>
void dlsl<itemtype>::deleteitem(itemtype item) { //찾아 죽이기! 비정렬이랑 똑같다!
	nodetype<itemtype>* locaptr; //back 개념까지 생겨서 tempptr이 필요가 없다
	bool found;
	finditem(item, locaptr, found); //found의 경우 item의 순수 위치 반환
	//new 다음 loca를 건드려야 안전하게 변화 가능
	if (found) {
		if (locaptr->next != NULL) {
			(locaptr->next)->back = locaptr->back;
			if (locaptr != listptr) { //제너럴 케이스
				(locaptr->back)->next = locaptr->next;
			}
			else { //퍼스트 케이스
				listptr = locaptr->next;
			}
		}
		else { 
			if (locaptr->back != NULL) { //라스트 케이스
				(locaptr->back)->next = NULL;
			}
			else { //퍼스트 & 라스트 케이스
				listptr = NULL;
			}
		}
		delete locaptr;
		length--;
	}
	//텅 케이스는 아무 일도 없었다
}

template <class itemtype>
void dlsl<itemtype>::makeempty() {
	nodetype<itemtype>* tempptr = listptr;
	while (length != 0) {
		listptr = listptr->next;
		delete tempptr;
		length--;
	}
}
template <class itemtype>
dlsl<itemtype>::~dlsl() {
	makeempty();
}

template<class itemtype>
void dlsl<itemtype>::getnextitem(itemtype& item) { //리스트 안 부수고 아이템 먹기
	if (currentptr == NULL) {
		currentptr = listptr;
	}
	else {
		currentptr = currentptr->next;
	}
	item = currentptr->info;
}
template <class itemtype>
void dlsl<itemtype>::resetlist() { //아이템을 먹기 위한 위치 리셋
	currentptr = NULL;
}