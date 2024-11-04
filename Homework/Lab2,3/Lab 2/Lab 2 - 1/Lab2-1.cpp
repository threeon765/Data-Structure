#include "file_convert.h" //함수의 프로토타입을 선언한 헤더파일을 포함
#include <iostream>

int main(int argc, char* argv[]) { //Command-line 인수를 받아서 처리

	char* input = argv[1]; //첫번째 문자열 인수가 input
	char* output = argv[2]; //두번째 문자열 인수가 output
	std::ifstream input_file(input); //input과 동일한 이름의 파일 열기
	std::ofstream output_file(output); //output과 동일한 이름의 파일 생성

	if (strcmp(input, "windows_file.txt") == 0) { //input이 windows_file.txt일 경우, 즉 윈도우 파일을 여는 것으로 설정한 경우
		if (strcmp(output, "mac_file.txt") == 0) { //output이 mac_file.txt일 경우, 즉 맥 파일로 변환하는 것으로 설정한 경우
			windows_to_mac(input_file, output_file); //windows_to_mac 함수 호출
		}
		else if (strcmp(output, "unix_file.txt") == 0) {
			windows_to_unix(input_file, output_file);
		}
	}

	if (strcmp(input, "mac_file.txt") == 0) {
		if (strcmp(output, "windows_file.txt") == 0) {
			mac_to_windows(input_file, output_file);
		}
		else if (strcmp(output, "unix_file.txt") == 0) {
			mac_to_unix(input_file, output_file);
		}
	}

	if (strcmp(input, "unix_file.txt") == 0) {
		if (strcmp(output, "windows_file.txt") == 0) {
			unix_to_windows(input_file, output_file);
		}
		else if (strcmp(output, "mac_file.txt") == 0) {
			unix_to_mac(input_file, output_file);
		}
	}

	input_file.close(); //파일 닫기
	output_file.close();

	return 0;
}