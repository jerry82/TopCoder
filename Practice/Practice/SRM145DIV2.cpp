#include "lib.h"

class ImageDithering {
public:
	int count(string dithered, vector<string> screen) {

		int count = 0;

		if (screen.empty()) return 0;
		if (dithered == "") return 0;

		for (string line : screen) {
			for (char c : line) {
				for (char d : dithered) {
					if (c == d) {
						count++;
						break;
					}
				}
			}
		}

		return count;
	}
};

class ExerciseMachine {
public:
	ExerciseMachine() {}

	int getPercentages(string time) {

		int h = atoi(time.substr(0, 2).c_str());
		int m = atoi(time.substr(3, 2).c_str());
		int s = atoi(time.substr(6, 2).c_str());
		int tS = h * 3600 + m * 60 + s;

		int count = 0;
		for (int i = 1; i != tS; i++) {
			int tmp = i * 100 / tS;

			if (i * 100 != tmp * tS) 
				continue;
			else
				count++;
		}

		return count;
	}
};

