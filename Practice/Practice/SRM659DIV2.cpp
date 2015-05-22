#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

#define rep(i, m, n)  for(int i = (m); i <= (n); i++)

using namespace std;


class PublicTransit {

public:
	int minimumLongestDistance(int R, int C) {
		int cnt = R * C;

		rep (px, 1, R) {
			rep(py, 1, C) {
				rep(qx, px, R) {
					rep(qy, 1, C) {
						if (qx < px) continue;

						int d = getMaxD(px, py, qx, qy, R, C);
						if (cnt > d) {
							cnt = d;
						}
					}
				}
			}
		}
		return cnt;
	}

	int getMaxD(int px, int py, int qx, int qy, int R, int C) {
		int d = 0;

		rep(x1, 1, R) {
			rep(y1, 1, C) {
				rep(x2, x1, R) {
					rep(y2, 1, C) {
						if (x1 == x2 && y1 == y2) continue;
						if (x2 < x1) continue;
						if (x2 == x1 && y2 < y1) continue;

						//cout << x1 << "," << y1 << " - " << x2 << "," << y2 << endl;

						//x->y
						int d1 = abs(x2 - x1) + abs(y2 - y1);
						//x->p y->q
						int d2 = abs(x1 - px) + abs(y1 - py) + abs(x2 - qx) + abs(y2 - qy);
						//x->q y->p
						int d3 = abs(x1 - qx) + abs(y1 - qy) + abs(x2 - px) + abs(y2 - py);

						int tmp = min({ d1, d2, d3 });
						
						
						if (d < tmp) {
							d = tmp;
						}
					}
				}
			}
		}

		return d;
	}
};



class FilipTheFrog {
public:
	int countReachableIslands(vector <int> positions, int L) {
		int cnt = 1; 
		if (positions.size() == 1) return 1;

		vector<int> v = positions;

		int tmp = v[0];
		int tmp2 = v[0];

		int sz = v.size();

		sort(v.begin(), v.end(), mySort);
		int idx = find(v.begin(), v.end(), tmp) - v.begin();


		for (int i = idx - 1; i >= 0; i--) {
			if (abs(v[i] - tmp) <= L) {
				tmp = v[i];
				cnt++;
			}
		}

		for (int i = idx + 1; i < sz; i++) {
			if (abs(v[i] - tmp2) <= L) {
				tmp2 = v[i];
				cnt++;
			}
		}
				

		return cnt;
	}

private:
	struct {
		bool operator() (int a, int b) { return a < b; }
	} 
	mySort;
};