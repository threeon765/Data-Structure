#include "file_convert.h" //함수의 프로토타입을 선언한 헤더파일을 포함

void windows_to_mac(std::ifstream &input_file, std::ofstream &output_file) {
	char ch;
	while (input_file.get(ch)) { //\r\n을 \r로 변환
		if (input_file.fail()) break;
		if (ch != '\n') {
			output_file << ch;
		}
	}
}

void windows_to_unix(std::ifstream &input_file, std::ofstream &output_file) {
	char ch;
	while (input_file.get(ch)) { //\r\n을 \n으로 변환
		if (input_file.fail()) break;
		if (ch != '\r') {
			output_file << ch;
		}
	}
}