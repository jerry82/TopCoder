#include "lib.h"

class FormatAmt {
public:
	string amount(int dollars, int cents) {
		string out;

		if (cents >= 10)
			out += "." + to_string(cents);
		else
			out += ".0" + to_string(cents);

		if (dollars == 0) {
			out = "0" + out;
		}
		else {
			string d = to_string(dollars);
			string dig = "";
			int c = 0;
			for (int i = d.length() - 1; i >= 0; i--) {
				dig = d[i] + dig;
				c++;
				if (c % 3 == 0)
					dig = "," + dig;
			}
			if (dig.at(0) == ',') {
				dig = dig.substr(1, dig.size() - 1);
			}
			out = dig + out;
		}

		out = "$" + out;

		return out;
	}
};

class BigBurger {
public: 
	int maxWait(vector<int> arrival, vector<int> service) {

		int sz = arrival.size();
		if (sz <= 1) return 0;
		int max = 0;
		vector<int> done(sz);

		for (int i = 0; i != sz; i++) {
			if (i == 0) {
				done[i] = arrival[i] + service[i];
				continue;
			}
			int wait = 0;
			int tmp = done[i - 1];
			if (tmp > arrival[i]) {
				max = std::max(max, tmp - arrival[i]);
				done[i] = done[i - 1] + service[i];
			}
			else {
				done[i] = arrival[i] + service[i];
			}
		}
		
		
		return max;
	}
};