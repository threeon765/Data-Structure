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
