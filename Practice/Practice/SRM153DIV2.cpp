#include "lib.h"

class MostProfitable {
public:
	string bestItem(vector <int> costs, vector <int> prices, vector <int> sales, vector <string> items) {

		long max = 0;
		int maxId = 0;

		int sz = costs.size();

		for (int i = 0; i < sz; i++) {
			if (i == 0) {
				max = (prices[i] - costs[i]) * sales[i];
				maxId = 0;
			}
			else {
				long tmp = (prices[i] - costs[i]) * sales[i];
				if (max < tmp) {
					max = tmp;
					maxId = i;
				}
			}
		}
		//cout << max << endl;
		
		if (max > 0)
			return items[maxId];
		else
			return "";
	}
};

class Inventory {
public:
	int monthlyOrder(vector <int> sales, vector <int> daysAvailable) {
		int result = 0;

		int noZero = 0;
		int sz = sales.size();
		double sum = 0;

		for (int i = 0; i < sz; i++) {
			int ts = sales[i];
			int td = daysAvailable[i];
			if (td == 0) {
				noZero++;
				continue;
			}

			sum += ts * 30.0 / td;
		}

		if (sz - noZero == 0) {
			return 0;
		}
		sum /= (sz - noZero);

		result = ceil(sum - pow(10, -9));
		

		return result;
	}
};