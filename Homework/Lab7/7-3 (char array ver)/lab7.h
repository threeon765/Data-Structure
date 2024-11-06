#pragma once
#include <iostream>
//링커 부분에서 에러가 발생할 경우 빌드 - 솔루션 정리를 진행해주시고 실행하면 정상적으로 작동합니다.

struct nodetype { //3-a
	char info[80] = {};
	nodetype* back;
	nodetype* next;
};

class DLUL {
	nodetype* header;
	nodetype* trailer;
	nodetype* currentptr;
public:
	DLUL() { //3-b
		header = new nodetype;
		std::string top = "--- Top of file---";
		for (int i = 0; i < top.length(); i++) {
			(header->info)[i] = top[i];
		}
		trailer = new nodetype;
		std::string bottom = "--- Bottom of file ---";
		for (int i = 0; i < bottom.length(); i++) {
			(trailer->info)[i] = bottom[i];
		}
		header->back = NULL;
		header->next = trailer;
		trailer->back = header;
		trailer->next = NULL;
		currentptr = header;
	}

	void GoToTop() { //3-c
		if (header->next == trailer) { //empty
			currentptr = trailer;
		}
		else { //general
			currentptr = header;
		}
	}
	void GoToBottom() {
		if (header->next == trailer) { //empty
			currentptr = header;
		}
		else { //general
			currentptr = trailer;
		}
	}

	//3-d
	//GoToTop은 모든 경우에 대해서 O(1)이고,
	//GoToBottom은 만약 trailer 멤버가 없다면 
	//line이 하나도 없는 경우에 O(1), 그 외의 경우는 O(N)
	//trailer 멤버가 있다면 모든 경우에 대해서 O(1)

	void InsertItem(const char str[]) { //3-e
		int length = 0;
		while (str[length] != '\0') {
			length++;
		}
		if (length > 80) { //over str
			std::cout << "String is too long!" << std::endl;
		}
		else {
			nodetype* newptr = new nodetype;
			for (int i = 0; i < length; i++) {
				(newptr->info)[i] = str[i];
			}
			if (currentptr == trailer) { //last case
				newptr->back = trailer->back;
				newptr->next = trailer;
				trailer->back->next = newptr;
				trailer->back = newptr;
				currentptr = currentptr->back;
			}
			else {
				newptr->back = currentptr; //general
				newptr->next = currentptr->next;
				currentptr->next->back = newptr;
				currentptr->next = newptr;
				currentptr = currentptr->next;
			}
		}
	}

	void Print() {
		if (header->next != trailer) {
			nodetype* locaptr = header->next;
			while (locaptr != trailer) {
				int i = 0;
				while ((locaptr->info)[i] != '\0') {
					std::cout << locaptr->info[i];
					i++;
				}
				std::cout << std::endl;
				locaptr = locaptr->next;
			}
		}
	}
};