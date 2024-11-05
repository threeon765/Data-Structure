#include <string>
#include <iostream>
using namespace std;

template<class itemtype> //queue ���
class queue; //### class ������Ÿ�� �ȵ� ###

bool isright(string rawstr) {
	string str = "";
	queue<char> first; //( ����� queue
	queue<char> last; //) ����� queue
	char temp;
	int firstcount, lastcount; //(, ) ���� ����� //### 0���� �ʱ�ȭ�ؾ��� ###

	for (int i = 0; i < rawstr.length(); i++) { //rawstr->str (���� ����)
		if (rawstr[i] != ' ') {
			str += rawstr[i];
		}
	}

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') { //(�� ���� �߸��� ������ ����
			if (i >= str.length() - 1) { //~~~~( �������� ������ ���
				return false;
				break;
			}
			else {
				if (str[i + 1] == '+' || str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/') {
					return false; //~~(+~~ ��ȣ ���� �����ڰ� �� ���
					break;
				}
			}
			first.enqueue(str[i]); //������ �����̸� ����
		}
		else if (str[i] == ')') { //)�� ���� �߸��� ������ ����
			if (i <= 0) { //)~~~~ ó���� ������ ���
				return false;
				break;
			}
			else { //~~+) ������ ���� ��ȣ�� �� ���
				if (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/') {
					return false;
					break;
				}
			}
			last.enqueue(str[i]); //������ �����̸� ����
		}
	}

	while (!first.isempty()) { //��ȣ�� �� ��
		first.dequeue(temp);
		firstcount++;
	}
	while (!last.isempty()) {
		last.dequeue(temp);
		lastcount++;
	}
	if (firstcount == lastcount) { //���ƾ� ��μ� ��
		return true;
	}
	else { //�ٸ��� ����
		return false; 
	}
}

int main() {
	string rawstr;
	getline(cin, rawstr); //���ڿ� �ޱ�

	if (isright(rawstr) == true) { //������ ������ ����
		std::cout << "����\n";
	}
	else {
		std::cout << "������\n"; //������ ������ ������
	}
}

template<class itemtype>
struct nodetype {
	itemtype info;
	nodetype* next;
};
template<class itemtype> //queue �� node ���� �κ�
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
			if (front == NULL) { //��
				rear = NULL;
			}
			delete locaptr;
		}
	}
};