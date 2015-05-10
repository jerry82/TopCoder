#include "lib.h"

class WidgetRepairs {
public:
	int days(vector<int> arrivals, int numPerDay) {
		
		if (arrivals.size() == 0) return 0;

		int day = 0;
		int sz = arrivals.size();
		int tmp = 0;

		for (int i = 0; i != sz; ++i) {
			int cur = arrivals[i] + tmp;
			tmp = cur - numPerDay;
			if (tmp < 0) {
				tmp = 0;
			}

			if (cur != 0) {
				day++;
			}
		}

		cout << day;

		if (tmp != 0)
			day += (int) ceil(1.0 * tmp / numPerDay) ;
		
		
		return day;
	}
};

class InterestingDigits {
public:
	vector<int> digits(int base) {
		vector<int> nums;

		if (base < 3 || base > 30) return nums;
		
		for (int i = 2; i != base; i++) {
			bool interesting = true;

			int lim = (int)(999 / base);
			for (int k = 2; k <= lim; k++) {
				int mul = k * i;

				if (!check(mul, i, base)) {
					interesting = false;
					break;
				}
			}

			if (interesting) {
				nums.push_back(i);
			}
		}

		return nums;
	}

	bool check(int mul, int nu, int base) {
		int count = 0;
		int id = 0;
		do {
			while (pow(base, id) < mul) {
				id++;
			}
			id--;
			int tmp = (int)(mul / pow(base, id));
			count += (int)(mul / pow(base, id));
			mul -= tmp * (int)pow(base, id);

		} while (id != 0);

		return count % nu == 0;
	}

};