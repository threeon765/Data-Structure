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