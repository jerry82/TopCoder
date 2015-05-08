#include "lib.h"

class DivisorDigits {
public:
	int howMany(int number) {
		int cnt = 0;
		int tmp = number;
		int idx = 1;

		if (number < 0) return 0;

		while (tmp != 0) {

			if (tmp / idx == 0) break;
			int r = (tmp / idx) % 10;
			if (r != 0 && number % r == 0) cnt++;

			idx *= 10;
		}

		return cnt;
	}
};

class CeyKaps {
public:
	string decipher(string typed, vector<string> switches) {
		string output;

		string oldKey;
		string key;

		for (int i = 'A'; i <= 'Z'; i++) {
			oldKey += char(i);
			key += (char(i));
		}
		//swap
		for (string sw : switches) {
			int idx1 = oldKey.find(sw[0]);
			int idx2 = oldKey.find(sw[2]);
			//swap key
			char tmp = key[idx1];
			key[idx1] = key[idx2];
			key[idx2] = tmp;
		}
		
		for (char c : typed) {
			output += oldKey[key.find(c)];
		}

		return output;
	}
};