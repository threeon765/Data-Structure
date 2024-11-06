#pragma once
#include <string>
#include <iostream>

struct nodetype { //3-a
	std::string info;
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
		header->info = "--- Top of file---";
		trailer = new nodetype;
		trailer->info = "--- Bottom of file ---";
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
	//GoToTop�� ��� ��쿡 ���ؼ� O(1)�̰�,
	//GoToBottom�� ���� trailer ����� ���ٸ� 
	//line�� �ϳ��� ���� ��쿡 O(1), �� ���� ���� O(N)
	//trailer ����� �ִٸ� ��� ��쿡 ���ؼ� O(1)

	void InsertItem(std::string str) { //3-e
		if (str.length() > 80) { //over str
			std::cout << "String is too long!" << std::endl;
		}
		else {
			nodetype* newptr = new nodetype;
			newptr->info = str;
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
				std::cout << locaptr->info << std::endl;
				locaptr = locaptr->next;
			}
		}
	}
};