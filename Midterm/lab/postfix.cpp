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