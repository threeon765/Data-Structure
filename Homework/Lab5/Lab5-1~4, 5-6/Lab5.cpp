#include "QueType.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
	std::srand(static_cast<unsigned int>(std::time(0))); //실습 5-1
	auto a = QueType(10);
	auto b = QueType(10);
	auto c = QueType(11);
	for (int i = 0; i < 10; i++) {
		int random = std::rand() % 10;
		std::cout << random << " ";
		a.Enqueue(random);
		b.Enqueue(random);
		c.Enqueue(random);
	}
	c.Enqueue(std::rand() % 10);
	std::cout << std::endl;

	
	ReplaceItem(a, 5, 7); //실습 5-2 검증
	b.ReplaceItem(5, 7); //아이템 중 5가 있을 경우에만 코드 검증이 가능합니다
	c.ReplaceItem(5, 7);

	
	if (Identical(a, b) == 0) { //실습 5-3 검증
		std::cout << "a & b not identical" << std::endl;
	}
	else {
		std::cout << "a & b indentical" << std::endl;
	}
	if (a.Identical(c) == 0) { 
		std::cout << "a & c not identical" << std::endl;
	}
	else {
		std::cout << "a & c indentical" << std::endl;
	}
	
	
	std::cout << Length(a) << std::endl; //실습 5-4 검증

	int print; //실습 5-1
	for (int i = 0; i < 10; i++) {
		a.Dequeue(print);
		std::cout << print << " ";
	}
	std::cout << std::endl;
	b.MinDequeue(print); //실습 5-6 검증
	b.Enqueue(8);
	for (int i = 0; i < 10; i++) {
		b.Dequeue(print);
		std::cout << print << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < 11; i++) {
		c.Dequeue(print);
		std::cout << print << " ";
	}
}