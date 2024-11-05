int main() {}
/*
# Linked Implementation
Array와는 다르게 새로운 자료가 생길 때마다 메모리를 동적 할당하는 방식을 기용하여, 
처음부터 메모리를 잔뜩 확보하지 않고 자료의 개수에 비례해 메모리를 할당해나간다
그러나 메모리 누수와 댕글린 포인터가 발생하지 않도록 주의해야 한다

코드 작성법
연산을 구현할 경우, 일반적인 상황 -> 극단적인 상황 순서로 생각한다
-> 꽉, 텅, 퍼스트, 라스트, 낫띵, 듀플

Destructor
텅이 아닌 자료구조의 사용하고 남은 노드들이 살아있기 때문에
자료구조가 소멸할 경우의 연산을 통해 메모리 누수를 방지한다

Array vs Linked
Linked는 텅일 때 메모리가 0이고, 메모리가 받쳐주는 한 계속 자료 추가가 가능하다
그러나 next의 존재 때문에 자료 하나당 메모리 크기가 크다
Array-Based: arraysize * itemsize + memvarsize (const)
Linked-Based: nodesize * nodenum + memvarsize (ax + b)
이 둘을 맞다이 까서 유리한 방식을 선택하자

Linked의 시간 복잡도
모든 Linked에 대해서 텅과 소멸자는 모든 노드를 전부 파괴해야하기 때문에 O(N)이 된다
그 외의 것은 동일하다 (binary search는 linked에서 똑같이 O(N)이다)
'찾기'가 알고리즘에 포함되면 O(N)은 기본이다 ex) deleteItem

# Doubly Linked
next의 개념 뿐만 아니라 back의 개념도 추가된 리스트
back 덕분에 tempptr을 사용하지 않아도 된다
시간 복잡도도 그대로이다

# Copy Constructor
linked가 평범한 복사 연산자를 사용할 경우 새로운 힙 메모리가 할당되지 않아
댕글링 포인터가 잔뜩 생긴다
따라서 new를 사용한 deep copy를 내용으로 하는 copy constructor가 필요하다
StackType(const StackType<ItemType> &anotherStack) {}
호출은 StackType A(B); 또는 StackType A = B;
*/