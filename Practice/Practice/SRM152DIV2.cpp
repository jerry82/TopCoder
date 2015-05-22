#include "lib.h"

class FixedPointTheorem {
public:
	double cycleRange(double R) {
		double X = 0.25;

		for (int i = 1; i <= 200000; i++) {
			X = getF(R, X);
		}

		double max = X; 
		double min = X;

		for (int i = 1; i <= 1000; i++) {
			X = getF(R, X);
			if (max < X) {
				max = X;
			}
			if (min > X) {
				min = X;
			}
		}

		return (max - min);
	}

	double getF(double R, double X) {
		return R * X * (1 - X);
	}
};

class LeaguePicks {
public:
	vector <int> returnPicks(int position, int friends, int picks) {
		vector<int> result;
		int add = 1;
		int p = 0;

		for (int i = 1; i <= picks; i++) {
			p += add;
			if (p > friends) {
				add = -1;
				p += add;
			}
			else if (p < 1) {
				add = 1;
				p += add;
			}

			if (p == position) {
				result.push_back(i);
			}
		}

		return result;
	}
};

class ProblemWriting {
public:
	string myCheckData(string dotForm) {
		string result;

		int sz = dotForm.length();
		if (sz < 1 || sz > 25)
			return "dotForm must contain between 1 and 25 characters, inclusive.";

		//0: expect num
		//1: expect operator
		int expect = 0; 
		int noDigit = 0;

		for (int i = 0; i < sz; i++) {
			char c = dotForm[i];

			if ((i == 0 || i == sz - 1) && !isNum(c))  {
				return error(i);
			}

			if (c == '.') {
				continue;
			}

			if (isNum(c) && expect == 0) {
				noDigit++;
				expect = 1;
				continue;
			}
			else if (isOp(c) && expect == 1) {
				expect = 0;
				continue;
			}
			else {
				return error(i);
			}
		}

		if (expect == 0 || noDigit < 2)
			return error(sz);

		return "";
	}

	bool isNum(char n) {
		string ops = "0123456789";
		for (char c : ops) {
			if (n == c)
				return true;
		}

		return false;
	}

	bool isOp(char n) {
		string ops = "+-*/";
		for (char c : ops) {
			if (n == c)
				return true;
		}

		return false;
	}

	string error(int n) {
		return "dotForm is not in dot notation, check character " + to_string(n) + ".";
	}
};