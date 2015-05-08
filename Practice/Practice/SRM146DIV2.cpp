#include "lib.h"

class YahtzeeScore {
public:
	YahtzeeScore() {}

	int maxPoints(vector<int> toss) {

		if (toss.empty()) return 0;

		int p = 0;
		for (int i = 0; i != toss.size(); i++) {
			int tmp = toss[i];

			for (int j = 0; j != toss.size(); j++) {
				if (i == j) continue;
				if (toss[j] == toss[i])
					tmp += toss[j];
			}

			p = max(p, tmp);
		}
		return p;
	}
};

class RectangularGrid {
public:
	long long countRectangles(int width, int height) {

		long long count = 0;
		if (width == 0 || height == 0) return 0;

		for (int h = 1; h <= height; h++) {
			for (int w = 1; w <= width; w++) {
				if (h == w) 
					continue;
				int horizontal = width - w + 1;
				int vertical = height - h + 1;
				count += horizontal * vertical;
			}
		}

		return count;
	}
};

class BridgeCrossing {

	struct Index {
		int id1;
		int id2;
	};
public:

	BridgeCrossing(){}

	int minTime(vector<int> time) {
		int mt = numeric_limits<int>::max();
		vector<int> from = time;
		vector<int> to;

		run(from, to, true, 0, mt);

		return mt;
	}

	void run(vector<int> from, vector<int> to, bool go, int time, int &minTime) {
		//if go then send 2 persons if possible
		if (go) {
			//send last 2 persons
			if (from.size() == 2) {
				int total = time + max(from.at(0), from.at(1));;
				minTime = min(minTime, total);
				return;
			}
			//send last 1 persons
			else if (from.size() == 1) {
				int total = time + from[0];
				minTime = min(minTime, total);
				return;
			}
			else {
				vector<Index> twoIds = getTwoIds(from.size());
				int tmpTime;


				for (Index index : twoIds) {
					vector<int> c_from = from;
					vector<int> c_to = to;
					c_to.push_back(from[index.id1]);
					c_to.push_back(from[index.id2]);

					tmpTime = time + max(c_from.at(index.id1), c_from.at(index.id2));
					c_from = remove(index.id1, index.id2, c_from);

					run(c_from, c_to, false, tmpTime, minTime);
				}
			}
		}
		//send back
		else {
			if (to.empty()) return;


			int tmpTime;

			for (int i = 0; i != to.size(); i++) {
				vector<int> c_from = from;
				vector<int> c_to = to;
				c_from.push_back(c_to[i]);
				tmpTime = time + c_to[i];
				c_to = remove(i, -1, c_to);

				run(c_from, c_to, true, tmpTime, minTime);


			}
		}
	}

	//get combination of 2 out of size
	//make sure size >= 2
	vector<Index> getTwoIds(int size) {
		vector<Index> result;

		if (size < 2) return result;

		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				Index idx;
				idx.id1 = i; idx.id2 = j;
				result.push_back(idx);
			}
		}

		return result;
	}

	vector<int> remove(int id1, int id2, vector<int> input) {
		vector<int> result;

		if (input.size() == 0) return result;

		for (int i = 0; i != input.size(); i++) {
			if (id2 == -1) {
				if (i != id1)
					result.push_back(input[i]);
			}
			else {
				if (i != id1 && i != id2)
					result.push_back(input[i]);
			}
		}

		return result;
	}
};