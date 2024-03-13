#include <iostream>
#include "Math.h"
#include <cstdarg>
#include <cstring>
#include <cmath>

int Math::Add(int a, int b) {
	return a + b;
}

int Math::Add(int a, int b, int c) {
	return a + b + c;
}

int Math::Add(double a, double b) {
	return a + b;
}

int Math::Add(double a, double b, double c) {
	return a + b + c;
}

int Math::Mul(int a, int b) {
	return a * b;
}

int Math::Mul(int a, int b, int c) {
	return a * b * c;
}

int Math::Mul(double a, double b) {
	return a * b;
}

int Math::Mul(double a, double b, double c) {
	return a * b * c;
}

int Math::Add(int count, ...) {
	va_list args;
	va_start(args, count);
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += va_arg(args, int);
	}
	va_end(args);
	return sum;
}

char* Math::Add(const char* s1, const char* s2) {
	if (s1 == nullptr || s2 == nullptr) {
		return nullptr;
	}
	else {
		int lungime, lungime1;
		if (strlen(s1) > strlen(s2)) {
			lungime = strlen(s2);
			lungime1 = strlen(s1);
		}
		else {
			lungime = strlen(s1);
			lungime1 = strlen(s2);
		}
		//std::cout << lungime1;
		char* s = new char(sizeof(char));
		//std::cout << s << "\n";
		s[lungime1] = '\0';
		int reminder = 0, count = 0;


		while (lungime) {
			int calc = (s1[strlen(s1) - 1 - count] - '0') + (s2[strlen(s2) - 1 - count] - '0') + reminder;
			if (calc > 9) {
				reminder = 1;
				s[count] = (calc % 10) + '0';
				count++;
				//std::cout << s << "\n";
			}
			else {
				s[count] = (calc % 10) + '0';
				count++;
				reminder = 0;
				//std::cout << s << "\n";
			}
			lungime--;
		}

		//std::cout << count << "\n";

		if (count < strlen(s1)) {
			while (count < strlen(s1)) {
				s[count++] = s1[strlen(s1) - 1 - count];
			}
		}
		else if (count < strlen(s2)) {
			while (count < strlen(s2)) {
				s[count++] = s1[strlen(s2) - 1 - count];
			}
		}
		
		for (int i = 0; i < count / 2; i++) {
			std::swap(s[i], s[count - i - 1]);
		}
		

		return s;
		
	}
}

