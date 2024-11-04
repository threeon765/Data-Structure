#include "unsorted.h"
#include "ItemType.h"
#include <iostream>
//샘플 코드들의 개행 문자 변환 필요 (코드 영역 우측 아래)
//재정의 문제 예방을 위한 헤더 파일의 전처리문 작업 필요

int main() {
    UnsortedType list;

    ItemType item0;
    item0.Initialize(0);
    ItemType item1;
    item1.Initialize(1);
    ItemType item2;
    item2.Initialize(2);
    ItemType item3;
    item3.Initialize(3);
    ItemType item4;
    item4.Initialize(4);

    list.InsertItem(item0);
    list.InsertItem(item1);
    list.InsertItem(item3);
    list.InsertItem(item2);
    list.InsertItem(item3);

    list.DeleteItem_a(item4); // item4는 리스트에 없으므로 변화 없음
    for (int i = 0; i < list.LengthIs(); i++) {
        std::cout << list.info[i].GetValue() << ", ";
    }
    std::cout << std::endl;

    list.DeleteItem_a(item2); // item2를 리스트에서 제거
    for (int i = 0; i < list.LengthIs(); i++) {
        std::cout << list.info[i].GetValue() << ", ";
    }
    std::cout << std::endl;

    list.DeleteItem_c(item3); // item3를 리스트에서 전부 제거
    for (int i = 0; i < list.LengthIs(); i++) {
        std::cout << list.info[i].GetValue() << ", ";
    }
    std::cout << std::endl;

    return 0; // 프로그램 정상 종료
}
