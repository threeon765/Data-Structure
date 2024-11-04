/*
SquareMatrix ADT 규격 명세

데이터 타입)
int형 자료 50개를 포함한 배열 50개를 포함한 이차원 정적 배열

메소드 & 연산자)
MakeEmpty(n)
기능: n x n의 모든 요소를 0으로 하여 초기화
조건: n의 최대 크기 50
결과: 기능과 동일
StoreValue(i, j, value)
기능: value를 i행 j열 위치에 저장
조건: value는 int형 자료여야함
결과: 기능과 동일
Add (+)
기능: 두 행렬에 대한 덧셈
조건: 두 행렬의 규격이 일치해야함
결과: 연산의 결과 반환
Subtract (-)
기능: 두 행렬에 대한 뺄셈
조건: 두 행렬의 규격이 일치해야함
결과: 연산의 결과 반환
Copy (=)
기능: 한 행렬을 다른 행렬에 복사
조건: 두 행렬의 규격이 일치해야함
결과: 기능과 동일

시험 계획)
클래스 생성 및 각 클래스로 메소드를 호출하여 실행하고, 
행렬의 요소 하나를 출력하는 메소드 CheckElement를 통해 
작성한 코드가 정상적으로 작동하는지 확인. 
*/

#include <iostream>
const int Max_Num = 50;
class SquareMatrix {
	int matrix[Max_Num][Max_Num];
public:
	void MakeEmpty(int n) {
		if(n <= 50) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = 0;
				}
			}
		}
		else {
			std::cout << "최대 크기 초과" << std::endl;
		}
	}
	void StoreValue(int i, int j, int value) {
		if ((i <= 50) && (j <= 50)) {
			matrix[i][j] = value;
		}
		else {
			std::cout << "범위 외 지정" << std::endl;
		}
	}
	SquareMatrix operator+(const SquareMatrix& sm1) const {
		SquareMatrix sm2;
		sm2.MakeEmpty(num);
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				sm2.matrix[i][j] = this->matrix[i][j] + sm1.matrix[i][j];
			}
		}
		return sm2;
		}
	}
	SquareMatrix operator-(const SquareMatrix& sm1) const {
		SquareMatrix sm2;
		sm2.MakeEmpty(num);
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				sm2.matrix[i][j] = this->matrix[i][j] - sm1.matrix[i][j];
			}
		}
		return sm2;
		}
	}
	SquareMatrix& operator=(const SquareMatrix& sm1) {
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				this->matrix[i][j] = sm1.matrix[i][j];
			}
		}
		return (*this);
		}
	}
	void CheckElement(int i, int j) {
		std::cout << matrix[i][j] << std::endl;
	}
};
int main() {
	SquareMatrix sm0;
	SquareMatrix sm1;
	sm0.MakeEmpty(5);
	sm1.MakeEmpty(5);
	sm0.StoreValue(0, 0, 99);
	sm1.StoreValue(0, 0, 1);
	SquareMatrix sm2 = sm0 + sm1;
	sm2.CheckElement(0, 0);
	SquareMatrix sm3 = sm0 - sm1;
	sm3.CheckElement(0, 0);
	sm0 = sm1;
	sm0.CheckElement(0, 0);
	return 0;
}