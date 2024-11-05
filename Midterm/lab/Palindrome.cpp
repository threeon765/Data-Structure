#include "Palindrome.h"
#include <iostream>

int main() {
	char myStr[100];
	std::cin >> myStr;
	if (isPalindrome(myStr) == true) {
		std::cout << "It's a palindrome.\n";
	}
	else {
		std::cout << "It's NOT a palindrome.\n";
	}
	return 0;
}