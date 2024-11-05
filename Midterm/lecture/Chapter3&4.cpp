int main() {}

/*
# Array 기반 Unsorted LIst, Sorted LIst, Stack, Queue를 다룬다

선형 관계 - 모든 item은 전임자와 후계자가 존재한다

length - item의 수

Default Constructor - 파라미터가 없는 기본 생성자
만약 다른 생성자를 하나라도 작성하였다면, 기본 생성자는 없어지므로
필요하다면 반드시 같이 작성하자

시간 복잡도
알고리즘의 효율성을 계산하기 위한 수치
각각의 연산은 특정한 시간 복잡도를 가짐


# List
key - 정렬 기준

Binary Search
Sorted List에서 특정 자료를 찾는 방법 중 하나
일반적인 탐색법이 O(N)인 반면, 해당 방법은 O(logN)이기 때문에 효율적
일단 Array의 가운데 index를 찍어서 비교한 뒤 
결과에 따라 앞 또는 뒤쪽을 전멸시키는 방식으로 추려나간다


# Stack
ADT level - LIFO (Last In First Out) (마지막에 들어온 놈이 처음으로 나간다)

Pointer for Iterator
포인터 역시 변수이기 때문에 4bytes를 차지하며, 주소를 값으로 저장한다
유의) int* p, g; -> p는 포인터지만, g는 int이다

Allocation & Lifetime
Lifetime - 프로그램 실행(Runtime) 동안 변수의 메모리 할당 유지 시간
Static - Runtime 내내
Automatic - 선언 ~ 자동 파괴
Dynamic - 선언 ~ 직접 파괴 (Heap 메모리 사용)
유의) Scope vs Lifetime -> Scope는 동명의 변수 구분
ex) {static int a = 7;} int a = 7; 
-> 스태틱 a는 실행부터 할당되지만 사용은 블록내에서만 가능
반면 그냥 a는 문장을 접하면 할당이 되고 전역에서 사용


# Queue
ADT level - FIFO (First IN First Out)

Front & Rear 
Front는 말년 아이템을, Rear는 신병 아이템을 가리키는 Iterator
Default(텅)는 Front가 index 0, Rear가 index -1(순환 아님)에 위치
추가시 Rear가 움직이고, 삭제시 Front가 움직이는 원리
해석이 어렵다면 Front에서 index가 큰쪽 방향으로 Rear를 향해 따라가면 된다

Circular Queue
Array 기반 Queue는 사용하다 보면 Array의 앞 공간을 낭비하는 한계가 존재
'배열의 끝 + 1 = 배열의 앞'의 원리를 Front와 Rear에 적용
-> rear = (rear + 1) % maxQue (Front와 Rear의 움직임을 이렇게 구현)

Full & Empty Problem
Front가 Rear의 앞에 있는 조건이 사라지며 꽉과 텅의 조건 동일해진 문제 발생
(rear + 1) % maxQue == front
i. front가 말년을 가리키는게 아니라 말년 앞을 가리키게 하여 해결 (한 칸 예약)
full -> (rear + 1) % maxQue == front
empty -> full == rear
BUT! 배열의 공간 하나를 낭비해야 하는 한계가 존재
ii. length 개념을 새로 추가하여 해결 
((rear + 1) % maxQue == front) && (length == 0)
iii. FullFlag 개념을 새로 추가하여 해결
default는 false
enqueue의 경우 (rear+1)%maxque == front라면 FullFlag는 true가 되도록 함
dequeue의 경우 FullFlag는 !isfull() -> false가 되도록 함 (꽉인데 낫띵이면 full은 유지되어야 하니까)
empty → (rear+1)%maxque == front && FullFlag == false
full → (rear+1)%maxque == front && FullFlag == true
*/