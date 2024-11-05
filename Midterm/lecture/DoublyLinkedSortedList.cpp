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
void dlsl<itemtype>::finditem(itemtype& item, nodetype<itemtype>* &locaptr, bool& found) { //아이템을 찾아요~
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