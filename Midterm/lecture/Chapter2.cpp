int main() {}

/*
Data
분석에 부합하는 정보의 표현

Data Abstraction
데이터의 타입을 특성 및 구현에 따라 분리한 것

Data Encapsulation
데이터 및 데이터 처리를 하나의 객체로 묶어 객체 내부의 세부 구현을 숨기는 것
정보 숨기기에 해당하는 기능

Data level
Application - 현실 수준에서 모델링 (하나의 큰 덩이)
Logical(ADT) - 연산 수준으로 추상화 (what)
Implementation - 추상화한 내용을 코딩 등으로 구현 (how)

ADT (Abstract Data Type)
독립적인 데이터 및 관련 연산을 정의한 것 (추상화)
int부터 class까지 다양

Operation
Transformer - 객체의 데이터를 바꾸는 연산
Observer - 객체의 데이터를 바꾸지 않는 연산
Constructor - 객체를 생성하는 연산
Iterator - 구성 요소를 순차적으로 처리하기 위한 연산

Built-In
기계 수준의 연산으로 구현되어 있는 간단한 추상화

Composite
데이터 뭉탱이

Structure
연산을 통해 데이터 요소의 추가 및 삭제가 가능한 Composite
ex) class가 멤버를 빼버릴 수는 없잖아? 반면 array는 요소를 뺄 수 있지

Record
데이터 타입이 일정하지 않은 Composite

GDT (General Data Type)
다룰 데이터 타입을 따로 특정해두지 않은 Composite ex) template

Class
선언부는 client, 변수부는 object, 메소드 호출은 sending a message

Inheritance
이미 존재하는 클래스의 세분화 버전인 클래스 생성

Polymorphism
상속 관계에서 동명의 메소드 중 적합한 메소드를 사용할 수 있는 기능
override & ::
*/