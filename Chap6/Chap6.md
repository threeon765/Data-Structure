### Doubly Linked
next 뿐만 아니라 back의 개념까지 추가하여 위치 파악을 더 안전하게 하도록 하는 기법. delete의 경우 tempptr을 사용하지 않고도 해결 가능해지는 것이 가장 큰 특징.

### Headers & Trailers
극단적인 상황(퍼스트 & 라스트)의 예외 처리를 방지하기 위해 처음부터 쓰지 않는 노드 두개를 미리 만들어두는 기법.

### Array of records
Array의 Element가 노드(info + next), next가 다음 자료의 인덱스를 가리키도록 list(full) & free 리스트를 따로 관리해주어야 빈집 찾기도 가능해진다.

### Copy Constructor
파라미터로 받는 경우, 배열은 첫번째 주소가 넘어가므로 pass by reference이지만, 객체의 경우 pass by value이므로 복사가 발생한다, 그래서 보통 const&으로 보내는 것이 그 이유이다.
<br>
Default Copy Constructor는 새로운 메모리 동적 할당이 일어나지 않은 채 기존 메모리를 가리키는 포인터만 하나 새로 생기는 꼴이라 shallow copy가 발생하는 것이 문제이다. 만약 두 객체 중 하나에서 delete를 실행하면 다른 하나에서는 댕글링 포인터가 발생하게 되는 것이다.
<br>
따라서 새로운 메모리 동적 할당까지 시켜주는 deep copy를 구현시켜주는 Copy Constructor를 만들어주어야 한다.
<br>
= 대입 연산자 역시 shallow copy다. 따라서 deep copy를 위해서는 overload를 해야한다.