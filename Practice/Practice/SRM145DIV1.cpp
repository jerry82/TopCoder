#include "lib.h"


class Bonuses {
public:
	vector<int> getDivision(vector<int> points) {
		vector<int> sortedIds;
		vector<int> out;
		int sz = points.size();
		int sum = 0;
		float r = 0;

		if (sz == 0) return out;

		for (int p : points) { sum += p; }

		for (int i = 0; i != points.size(); i++) {
			float tmp = points[i] * (float)100 / sum;
			out.push_back((int)(tmp));
			float t = tmp - (float)out[i];
			r += t;
		}

		int red = r > ((int)r + 0.5) ? (int)r + 1 : (int)r;
		vector<int> cp = points;

		for (int i = sz - 1; i != 0; i--) {
			for (int j = 0; j < i; j++) {
				if (cp[j] < cp[j + 1]) {
					int tmp = cp[j];
					cp[j] = cp[j + 1];
					cp[j + 1] = tmp;
				}
			}
		}

		vector<int> added;
		for (int i = 0; i < sz; i++) {
			if (red != 0) {
				for (int j = 0; j < sz; j++) {
					if (find(added.begin(), added.end(), j) != added.end()) {
						continue;
					}

					if (cp[i] == points[j]) {
						out[j]++;
						red--;
						added.push_back(j);
						break;
					}
				}
			}
		}

		return out;
	}
};

