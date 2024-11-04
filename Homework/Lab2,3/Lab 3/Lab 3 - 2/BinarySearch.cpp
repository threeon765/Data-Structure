#include <iostream>

int BinarySearch_a(int array[], int sizeOfArray, int value) 
//Function : 배열에서 원하는 값의 위치를 찾는다.
//     Pre : array는 이미 원소의 초기화는 물론, 오름차순으로 정렬된 배열이라고 가정한다. sizeOfArray는 array의 원소의 개수와 같아야 한다.
//    Post : 찾은 대상의 인덱스를 정수형으로 반환한다. 만약 찾는 대상이 없다면 -1을 반환한다.
{
	int first = 0;
	int last = sizeOfArray - 1;
	bool moreToSearch = (first <= last);
	bool found = false;
	while ((moreToSearch == true) && (found == false)) {
		int midPoint = (first + last) / 2;
		if (array[midPoint] == value) {
			found = true;
			return midPoint;
		}
		else if (array[midPoint] > value) {
			last = midPoint - 1;
			moreToSearch = (first <= last);
		}
		else if (array[midPoint] < value) {
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
	}
	if ((moreToSearch == false) && (found == false)) {
		return -1;
	}
}

int BinarySearch_b(int array[], int sizeOfArray, int value)
//Function : 배열에서 원하는 값의 위치를 찾는다.
//     Pre : array는 이미 원소의 초기화는 물론, 오름차순으로 정렬된 배열이라고 가정한다. sizeOfArray는 array의 원소의 개수와 같아야 한다.
//    Post : 찾은 대상의 인덱스를 정수형으로 반환한다. 만약 찾는 대상이 없다면 그 대상보다 작은 값 중 가장 가까운 대상의 인덱스를 반환한다.
{
	int first = 0;
	int last = sizeOfArray - 1;
	bool moreToSearch = (first <= last);
	bool found = false;
	while ((moreToSearch == true) && (found == false)) {
		int midPoint = (first + last) / 2;
		if (array[midPoint] == value) {
			found = true;
			return midPoint;
		}
		else if (array[midPoint] > value) {
			last = midPoint - 1;
			moreToSearch = (first <= last);
		}
		else if (array[midPoint] < value) {
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
	}
	if ((moreToSearch == false) && (found == false)) {
		if (array[sizeOfArray - 1] < value) {
			return sizeOfArray - 1;
		}
		else if ((array[sizeOfArray - 1] > value) && (array[0] < value)) {
			for (int i = 0; i < sizeOfArray - 2; i++) {
				if ((array[i] < value) && (array[i + 1] > value)) {
					return i;
				}
			}
		}
		else if (array[0] > value) {
			return -1;
		}
	}
}

int BinarySearch_c(int array[], int sizeOfArray, int value)
//Function : 배열에서 원하는 값의 위치를 찾는다.
//     Pre : array는 이미 원소의 초기화는 물론, 오름차순으로 정렬된 배열이라고 가정한다. sizeOfArray는 array의 원소의 개수와 같아야 한다.
//    Post : 찾은 대상의 인덱스를 정수형으로 반환한다. 만약 찾는 대상이 없다면 그 대상보다 큰 값 중 가장 가까운 대상의 인덱스를 반환한다.
{
	int first = 0;
	int last = sizeOfArray - 1;
	bool moreToSearch = (first <= last);
	bool found = false;
	while ((moreToSearch == true) && (found == false)) {
		int midPoint = (first + last) / 2;
		if (array[midPoint] == value) {
			found = true;
			return midPoint;
		}
		else if (array[midPoint] > value) {
			last = midPoint - 1;
			moreToSearch = (first <= last);
		}
		else if (array[midPoint] < value) {
			first = midPoint + 1;
			moreToSearch = (first <= last);
		}
	}
	if ((moreToSearch == false) && (found == false)) {
		if (array[0] > value) {
			return 0;
		}
		else if ((array[sizeOfArray - 1] > value) && (array[0] < value)) {
			for (int i = 0; i < sizeOfArray - 2; i++) {
				if ((array[i] < value) && (array[i + 1] > value)) {
					return i+1;
				}
			}
		}
		else if (array[sizeOfArray - 1] < value) {
			return -1;
		}
	}
}

int main() { //검증 과정
	int arr[] = { 2,4,6,8,10,12 };
	int result = BinarySearch_a(arr, 6, 2); //0
	std::cout << "해당 값이 있는 인덱스는 " << result << std::endl;
	result = BinarySearch_a(arr, 6, 7); //없으니까 -1
	std::cout << "해당 값이 있는 인덱스는 " << result << std::endl;

	result = BinarySearch_b(arr, 6, 7); //7 대신 6의 인덱스인 2 반환
	std::cout << "해당 값이 있는 인덱스는 " << result << std::endl;
	result = BinarySearch_b(arr, 6, 13); //13 대신 12의 인덱스인 5 반환
	std::cout << "해당 값이 있는 인덱스는 " << result << std::endl;
	result = BinarySearch_b(arr, 6, 0); //0보다 작은 원소는 없으니 -1 반환
	std::cout << "해당 값이 있는 인덱스는 " << result << std::endl;

	result = BinarySearch_c(arr, 6, 7); //7 대신 8의 인덱스인 3 반환
	std::cout << "해당 값이 있는 인덱스는 " << result << std::endl;
	result = BinarySearch_c(arr, 6, 13); //13보다 큰 원소는 없으니 -1 반환
	std::cout << "해당 값이 있는 인덱스는 " << result << std::endl;
	result = BinarySearch_c(arr, 6, 0); //0 대신 2의 인덱스인 0 반환
	std::cout << "해당 값이 있는 인덱스는 " << result << std::endl;
}