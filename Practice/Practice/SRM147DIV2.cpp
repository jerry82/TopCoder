#include "lib.h"

class CCipher {
public:
	CCipher(){}

	string decode(string cipherText, int shift) {

		if (cipherText.empty()) return "";

		string ori;
		for (char c : cipherText) {
			int tmp = static_cast<int>(c) - shift;
			//or just can use: c - shift
			if (tmp < 65)
				tmp += 26;
			ori += char(tmp);
		}

		return ori;
	}
};

class PeopleCircle {
public:
	PeopleCircle(){}

	string order(int numMales, int numFemales, int K) {
		int sz = numMales + numFemales;

		string result(sz, 'M');
		int ptr = -1;

		for (int i = 0; i < numFemales; i++) {
			for (int j = 1; j <= K; j++) {
				ptr = nextPtr(result, ptr);

				if (j == K) {
					result[ptr] = 'F';
				}
			}
		}

		return result;
	}

	int nextPtr(string input, int ptr) {
		int size = input.size();
		string allF(size, 'F');

		if (ptr == -1) return 0;
		if (input == allF) return -1;

		do {
			ptr++;
			if (ptr >= size)
				ptr -= size;
		} while (input[ptr] == 'F');

		return ptr;
	}
};

