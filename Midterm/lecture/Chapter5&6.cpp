int main() {}
/*
# Linked Implementation
Array�ʹ� �ٸ��� ���ο� �ڷᰡ ���� ������ �޸𸮸� ���� �Ҵ��ϴ� ����� ����Ͽ�, 
ó������ �޸𸮸� �ܶ� Ȯ������ �ʰ� �ڷ��� ������ ����� �޸𸮸� �Ҵ��س�����
�׷��� �޸� ������ ��۸� �����Ͱ� �߻����� �ʵ��� �����ؾ� �Ѵ�

�ڵ� �ۼ���
������ ������ ���, �Ϲ����� ��Ȳ -> �ش����� ��Ȳ ������ �����Ѵ�
-> ��, ��, �۽�Ʈ, ��Ʈ, ����, ����

Destructor
���� �ƴ� �ڷᱸ���� ����ϰ� ���� ������ ����ֱ� ������
�ڷᱸ���� �Ҹ��� ����� ������ ���� �޸� ������ �����Ѵ�

Array vs Linked
Linked�� ���� �� �޸𸮰� 0�̰�, �޸𸮰� �����ִ� �� ��� �ڷ� �߰��� �����ϴ�
�׷��� next�� ���� ������ �ڷ� �ϳ��� �޸� ũ�Ⱑ ũ��
Array-Based: arraysize * itemsize + memvarsize (const)
Linked-Based: nodesize * nodenum + memvarsize (ax + b)
�� ���� �´��� � ������ ����� ��������

Linked�� �ð� ���⵵
��� Linked�� ���ؼ� �ְ� �Ҹ��ڴ� ��� ��带 ���� �ı��ؾ��ϱ� ������ O(N)�� �ȴ�
�� ���� ���� �����ϴ� (binary search�� linked���� �Ȱ��� O(N)�̴�)
'ã��'�� �˰��� ���ԵǸ� O(N)�� �⺻�̴� ex) deleteItem

# Doubly Linked
next�� ���� �Ӹ� �ƴ϶� back�� ���䵵 �߰��� ����Ʈ
back ���п� tempptr�� ������� �ʾƵ� �ȴ�
�ð� ���⵵�� �״���̴�

# Copy Constructor
linked�� ����� ���� �����ڸ� ����� ��� ���ο� �� �޸𸮰� �Ҵ���� �ʾ�
��۸� �����Ͱ� �ܶ� �����
���� new�� ����� deep copy�� �������� �ϴ� copy constructor�� �ʿ��ϴ�
StackType(const StackType<ItemType> &anotherStack) {}
ȣ���� StackType A(B); �Ǵ� StackType A = B;
*/