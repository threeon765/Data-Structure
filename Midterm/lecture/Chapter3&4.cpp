int main() {}

/*
# Array ��� Unsorted LIst, Sorted LIst, Stack, Queue�� �ٷ��

���� ���� - ��� item�� �����ڿ� �İ��ڰ� �����Ѵ�

length - item�� ��

Default Constructor - �Ķ���Ͱ� ���� �⺻ ������
���� �ٸ� �����ڸ� �ϳ��� �ۼ��Ͽ��ٸ�, �⺻ �����ڴ� �������Ƿ�
�ʿ��ϴٸ� �ݵ�� ���� �ۼ�����

�ð� ���⵵
�˰����� ȿ������ ����ϱ� ���� ��ġ
������ ������ Ư���� �ð� ���⵵�� ����


# List
key - ���� ����

Binary Search
Sorted List���� Ư�� �ڷḦ ã�� ��� �� �ϳ�
�Ϲ����� Ž������ O(N)�� �ݸ�, �ش� ����� O(logN)�̱� ������ ȿ����
�ϴ� Array�� ��� index�� �� ���� �� 
����� ���� �� �Ǵ� ������ �����Ű�� ������� �߷�������


# Stack
ADT level - LIFO (Last In First Out) (�������� ���� ���� ó������ ������)

Pointer for Iterator
������ ���� �����̱� ������ 4bytes�� �����ϸ�, �ּҸ� ������ �����Ѵ�
����) int* p, g; -> p�� ����������, g�� int�̴�

Allocation & Lifetime
Lifetime - ���α׷� ����(Runtime) ���� ������ �޸� �Ҵ� ���� �ð�
Static - Runtime ����
Automatic - ���� ~ �ڵ� �ı�
Dynamic - ���� ~ ���� �ı� (Heap �޸� ���)
����) Scope vs Lifetime -> Scope�� ������ ���� ����
ex) {static int a = 7;} int a = 7; 
-> ����ƽ a�� ������� �Ҵ������ ����� ��ϳ������� ����
�ݸ� �׳� a�� ������ ���ϸ� �Ҵ��� �ǰ� �������� ���


# Queue
ADT level - FIFO (First IN First Out)

Front & Rear 
Front�� ���� ��������, Rear�� �ź� �������� ����Ű�� Iterator
Default(��)�� Front�� index 0, Rear�� index -1(��ȯ �ƴ�)�� ��ġ
�߰��� Rear�� �����̰�, ������ Front�� �����̴� ����
�ؼ��� ��ƴٸ� Front���� index�� ū�� �������� Rear�� ���� ���󰡸� �ȴ�

Circular Queue
Array ��� Queue�� ����ϴ� ���� Array�� �� ������ �����ϴ� �Ѱ谡 ����
'�迭�� �� + 1 = �迭�� ��'�� ������ Front�� Rear�� ����
-> rear = (rear + 1) % maxQue (Front�� Rear�� �������� �̷��� ����)

Full & Empty Problem
Front�� Rear�� �տ� �ִ� ������ ������� �˰� ���� ���� �������� ���� �߻�
(rear + 1) % maxQue == front
i. front�� ������ ����Ű�°� �ƴ϶� ���� ���� ����Ű�� �Ͽ� �ذ� (�� ĭ ����)
full -> (rear + 1) % maxQue == front
empty -> full == rear
BUT! �迭�� ���� �ϳ��� �����ؾ� �ϴ� �Ѱ谡 ����
ii. length ������ ���� �߰��Ͽ� �ذ� 
((rear + 1) % maxQue == front) && (length == 0)
iii. FullFlag ������ ���� �߰��Ͽ� �ذ�
default�� false
enqueue�� ��� (rear+1)%maxque == front��� FullFlag�� true�� �ǵ��� ��
dequeue�� ��� FullFlag�� !isfull() -> false�� �ǵ��� �� (���ε� �����̸� full�� �����Ǿ�� �ϴϱ�)
empty �� (rear+1)%maxque == front && FullFlag == false
full �� (rear+1)%maxque == front && FullFlag == true
*/