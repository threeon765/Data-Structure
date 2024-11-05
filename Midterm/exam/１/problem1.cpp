#include <string>
#include <iostream>
using namespace std;

template<class itemtype> //queue 사용
class queue; //### class 프로토타입 안됨 ###

bool isright(string rawstr) {
	string str = "";
	queue<char> first; //( 저장용 queue
	queue<char> last; //) 저장용 queue
	char temp;
	int firstcount, lastcount; //(, ) 갯수 세기용 //### 0으로 초기화해야함 ###

	for (int i = 0; i < rawstr.length(); i++) { //rawstr->str (공백 제거)
		if (rawstr[i] != ' ') {
			str += rawstr[i];
		}
	}

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') { //(에 대해 잘못된 수식의 경우는
			if (i >= str.length() - 1) { //~~~~( 마지막에 놓였을 경우
				return false;
				break;
			}
			else {
				if (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/') {
					return false; //~~(+~~ 괄호 다음 연산자가 올 경우
					break;
				}
			}
			first.enqueue(str[i]); //수식이 정상이면 누적
		}
		else if (str[i] == ')') { //)에 대해 잘못된 수식의 경우는
			if (i <= 0) { //)~~~~ 처음에 놓였을 경우
				return false;
				break;
			}
			else { //~~+) 연산자 다음 괄호가 올 경우
				if (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/') {
					return false;
					break;
				}
			}
			last.enqueue(str[i]); //수식이 정상이면 누적
		}
	}

	while (!first.isempty()) { //괄호의 수 비교
		first.dequeue(temp);
		firstcount++;
	}
	while (!last.isempty()) {
		last.dequeue(temp);
		lastcount++;
	}
	if (firstcount == lastcount) { //같아야 비로소 참
		return true;
	}
	else { //다르면 거짓
		return false; 
	}
}

int main() {
	string rawstr;
	getline(cin, rawstr); //문자열 받기

	if (isright(rawstr) == true) { //문제가 없으면 정상
		std::cout << "정상\n";
	}
	else {
		std::cout << "비정상\n"; //문제가 있으면 비정상
	}
}

template<class itemtype>
struct nodetype {
	itemtype info;
	nodetype* next;
};
template<class itemtype> //queue 및 node 구현 부분
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
};