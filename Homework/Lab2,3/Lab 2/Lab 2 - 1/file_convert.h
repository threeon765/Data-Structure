#ifndef FILE_CONVERT_H //FILE_CONVERT_H가 define되지 않았다면 endif가 나오기 전까지의 부분을 포함시킬 것
#define FILE_CONVERT_H //헤더파일의 대문자 형태로 작성
#include <fstream>

void windows_to_mac(std::ifstream& input_file, std::ofstream& output_file); //함수 프로토타입 선언
void windows_to_unix(std::ifstream& input_file, std::ofstream& output_file);
void mac_to_windows(std::ifstream& input_file, std::ofstream& output_file);
void mac_to_unix(std::ifstream& input_file, std::ofstream& output_file);
void unix_to_windows(std::ifstream& input_file, std::ofstream& output_file);
void unix_to_mac(std::ifstream& input_file, std::ofstream& output_file);

#endif
//이렇게 작성한다면 헤더파일이 ~~_convert와 Lab2-1 총 4개의 소스 파일에서 include 된다하더라도 
//하나의 파일에서만 ifndef ~ endif 사이의 내용이 작동하므로 함수 선언이 중복으로 들어가 재정의되는 문제를 예방할 수 있음

//#pragma once
//처음 한번만 컴파일한다는 효력으로, ifndef가 전처리기 지시자인 반면 pragma는 컴파일러 지시자이고, 특정 컴파일러에서만 동작함
