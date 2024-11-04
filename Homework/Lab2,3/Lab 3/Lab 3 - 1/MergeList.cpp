#include "ItemType.h"
#include "sorted.h"
#include <iostream>

void MergeList(SortedType list1, SortedType list2, SortedType& result);
//Function : 2개의 Sorted List를 병합하여 다른 하나의 Sorted List에 저장한다.
//     Pre : 병합되는 list1과 list2는 초기화되어있고, ComparedTo 함수를 통해 키에 의해 정렬되어있다.
//    Post : result는 list1과 list2의 모든 요소를 가진 Sorted List이다.

void MergeList(SortedType list1, SortedType list2, SortedType& result) {
	ItemType CheckItem;
	result.ResetList(); //단순 숫자 대입이므로 O(1)
	list1.ResetList(); //O(1)
	list2.ResetList(); //0(1)
	//LengthIs는 리스트의 길이 접근이므로 O(1)
	for (int i = 0; i < list1.LengthIs(); i++) { //최악의 경우 리스트의 길이 만큼 반복이므로 O(n), n는 list1의 길이.
		list1.GetNextItem(CheckItem); //단순 접근 및 대입이므로 O(1)
		result.InsertItem(CheckItem); 
		//InsertItem 함수는 최악의 경우 while문과 for문이 리스트의 길이 만큼 반복하고, 리스트의 길이는 list1의 길이, 즉 n만큼이므로 O(n).
	} //결국 이중 반복문의 구조를 띄고 있으므로 O(n^2)
	for (int i = 0; i < list2.LengthIs(); i++) { //동일한 이유로 O(m), m은 list2의 길이.
		list2.GetNextItem(CheckItem); //O(1)
		result.InsertItem(CheckItem); //여기서는 최악의 경우 리스트의 길이가 list1과 list2의 길이의 총합이므로 O(n+m).
	} //O(m*(n+m)
} //결론적으로 MergeList의 시간 복잡도는 list1의 길이 n, list2의 길이 m에 대해 O(n^2+m*(n+m))이다.

int main() {
	SortedType s_list1, s_list2, s_list3;
	ItemType CheckItem;
	ItemType item1, item2, item3, item4, item5, item6, item7, item8;
	
	item1.Initialize(1);  //단순 숫자 대입이므로 O(1)
	item2.Initialize(2);
	item3.Initialize(3);
	item4.Initialize(4);
	item5.Initialize(5);
	item6.Initialize(6);
	item7.Initialize(7);
	item8.Initialize(8);

	s_list1.InsertItem(item3); //O(n)
	s_list1.InsertItem(item6);
	s_list1.InsertItem(item7);
	s_list1.InsertItem(item1);

	s_list1.ResetList(); //O(1)
	for (int i = 0; i < s_list1.LengthIs(); i++) { //O(n)
		s_list1.GetNextItem(CheckItem); //O(1)
		std::cout << CheckItem.GetValue() << ", "; //O(1)
	} //결국 O(n)
	std::cout << std::endl; //O(1)

	s_list2.InsertItem(item2); //O(m)
	s_list2.InsertItem(item8);
	s_list2.InsertItem(item5);
	s_list2.InsertItem(item4);
	
	s_list2.ResetList(); //O(1)
	for (int i = 0; i < s_list2.LengthIs(); i++) { //O(m)
		s_list2.GetNextItem(CheckItem); //O(1)
		std::cout << CheckItem.GetValue() << ", "; //O(1)
	} //결국 O(m)
	std::cout << std::endl; //O(1)
	
	MergeList(s_list1, s_list2, s_list3); //O(n^2+m*(n+m))

	s_list3.ResetList(); //O(1)
	for (int i = 0; i < s_list3.LengthIs(); i++) { //O(m+n)
		s_list3.GetNextItem(CheckItem); //O(1)
		std::cout << CheckItem.GetValue() << ", "; //O(1)
	} //결국 O(m+n)
	std::cout << std::endl; //O(1)
} //결론적으로 main의 시간 복잡도는 MergeList와 같은 O(n^2+m*(n+m))이다.
