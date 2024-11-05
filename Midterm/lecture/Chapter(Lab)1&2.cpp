int main() {}

/*
# Offset Table
Length - 자료의 크기
Offset - 자료들의 주소 변위
맨 처음 자료의 Offset을 0으로 하여, 이전 자료들의 length를 누적시켜 구하면 된다
Padding
실제 컴퓨터는 4바이트 정렬 규칙에 따라 주소를 결정한다
ex) 9바이트 -> 12바이트 누적
배열 등의 Composite 자료들은 구성 요소의 모든 length를 더한 다음
4바이트 정렬 규칙을 적용하도록 한다
ex) 7바이트 10개 배열 -> 80이 아닌 72가 최종 크기

# Array Memory Calculate
Address of X[a] = BaseAddress + a * SizeOfItem
int X[a][b]; -> 열 행
row major -> 행 단위로 저장
-> X00 X10 X20 ~ Xa-10 | X01 X11 X21 ~ Xa-11 | X02 ~
Address of X[c][d] = BaseAddress + (a * d + c) * SizeOfItem

# ADT 규격 명세서
현재 사용하고 있는 헤더 파일처럼 작성하면 됨
각 연산마다 기능, 조건(precondi.), 결과(postcondi.)를 작성

# int strcmp(const char *s1, const char *s2);
문자열 두개를 비교
s1 < s2 -> -1, s1 == s2 -> 0, s1 > s2 -> 1

# int strlen(char* str);
문자열 길이 반환 (NULL 미포함)

# 개행문자
CRLF \r\n LF \n CR \r

# command-line argument
int main(int argc, char* argv[])
바로가기 파일의 경로 맨 뒤쪽에 띄어쓰기로 하나씩 입력
argv에 프로그램 이름과 입력한 문자열들이 들어가고, argc는 그 개수를 의미

# Redefinition problem
#inndef ITEMTYPE_H (전처리기)
#define ITEMTYPE_H
~~~
#endif
or
#pragma once (컴파일러)
*/