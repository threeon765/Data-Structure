#include "file_convert.h" //함수의 프로토타입을 선언한 헤더파일을 포함

void mac_to_windows(std::ifstream &input_file, std::ofstream &output_file) {
	char ch;
	while (input_file.get(ch)) { //\r을 \r\n으로 변환
		if (input_file.fail()) break;
		if (ch != '\r') {
			output_file << ch;
		}
		else {
			output_file << '\r' << '\n';
		}
	}
}

void mac_to_unix(std::ifstream &input_file, std::ofstream &output_file) {
	char ch;
	while (input_file.get(ch)) { //\r을 \n으로 변환
		if (input_file.fail()) break;
		if (ch != '\r') {
			output_file << ch;
		}
		else {
			output_file << '\n';
		}
	}
}