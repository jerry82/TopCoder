#include "lib.h"

class GreatFairyWar {
public: 
	GreatFairyWar() {}

	int minHP(vector <int> dps, vector <int> hp) {
		int sum = 0, min = 0, tmp = 0;
		if (dps.empty() || hp.empty()) return 0;

		for (int i : dps) { sum += i; }		
		for (int j = 0; j != dps.size(); j++) {
			sum -= tmp;
			min += hp[j] * sum;
			tmp = dps[j];
		}
		return min;
	}
};

//this version uses "backtrack" technique
class IncubatorEasy {
public:
	IncubatorEasy() {}

	int maxMagicalGirls(vector<string> love) {
		//n between 0 and 10 inclusive
		int maxTime = 0;

		int size = love.size();
		int count = 0;
		vector<int> magics(size);
		vector<int> protects(size);

		for (int i = 0; i != size; i++) {
			int count = 0;
	
			vector<int> c_magics = magics;
			vector<int> c_protects = protects;
			getMaxGirls(i, love, c_magics, c_protects, count);

			maxTime = max(maxTime, count);
		}

		return maxTime;
	}

	void getMaxGirls(int curGirl, vector<string> love, vector<int>& magics, vector<int> &protects, int &count) {

		//set magic 
		magics[curGirl] = 1;
		setProtected(curGirl, love, protects);

		count = max(countMagics(magics, protects), count);

		vector<int> nextGirl = getGirl(magics, protects);
		if (!nextGirl.empty()) {
			
			for (int girl : nextGirl) {
				vector<int> copy_m = magics;
				vector<int> copy_p = protects;
				getMaxGirls(girl, love, copy_m, copy_p, count);
			}
		}
	}

	//this method will set all the related girls' protected -> 1
	void setProtected(int curGirl, vector<string> love, vector<int> &protects) {
		string s = love[curGirl];
		for (int j = 0; j != s.length(); j++) {
			if (s[j] == 'Y' && protects[j] == 0) {
				
				protects[j] = 1;
				setProtected(j, love, protects);
			}
		}
	}

	//get 1 girl with isMagics = 0 && isProtected = 0
	vector<int> getGirl(vector<int> magics, vector<int> protects) {
		vector<int> girls;
		for (int i = 0; i != magics.size(); i++) {
			if (magics[i] == 0 && protects[i] == 0)
				girls.push_back(i);
		}

		return girls;
	}

	int countMagics(vector<int> magics, vector<int> protects) {
		int count = 0;

		for (int i = 0; i != magics.size(); i++) {
			if (magics[i] == 1 && protects[i] == 0)
				count++;
		}

		return count;
	}
};