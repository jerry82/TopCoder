#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;
struct aDate {
	int month;
	int day;
};
class Birthday {
public:
	string getNext(string date, vector<string> birthdays) {
		string s;

		if (birthdays.size() == 1) {
			return getDateStr(birthdays[0]);
		}
		 
		int minDis = numeric_limits<int>::max();
		int idx = 0;
		aDate curD = getDate(date);
		for (int i = 0; i != birthdays.size(); i++) {
			string str = birthdays[i];
			aDate d = getDate(str);
			int tmp = dis(d, curD);
			//cout << tmp << endl;
			if (tmp < minDis) {
				minDis = tmp;
				idx = i;
			}
		}

		return getDateStr(birthdays[idx]);
	}

	vector<int> getMonths() {
		vector<int> months = { 31, 28, 31, 30, 30, 30, 31, 31, 30, 31, 30, 31 };
		for (int i = 1; i < 12; i++) { 
			months[i] += months[i - 1];
		}
		return months;
	}

	int dis(aDate d1, aDate cur) {
		int dis = 0;
		vector<int> months = getMonths();
		int dayD1 = months[d1.month - 1] + d1.day;
		int dayCur = months[cur.month - 1] + cur.day;

		dis = dayD1 - dayCur;
		if (dis < 0)
			dis += 365;

		return dis;
	}

	string getDateStr(string s) {
		if (s.size() < 5) 
			return "";
		return s.substr(0, 5);
	}

	aDate getDate(string s) {
		aDate d;
		d.month = atoi(s.substr(0, 2).c_str());
		d.day = atoi(s.substr(3, 2).c_str());

		return d;
	}

};
class UnrelatedPaths {
public:
	int maxUnrelatedPaths(vector <int> parent) {
		
		int max = 0;

		if (parent.size() == 0) return 1;
		for (int i = 1; i <= parent.size(); i++) {
			if (find(parent.begin(), parent.end(), i) == parent.end())
				max++;
		}
		return max;
	}
};

class DevuAndPlantingTrees {
public:
	int maximumTreesDevuCanGrow(vector <string> garden) {
		int max = 0;
		if (garden.empty())
			return 0;

		string s1 = "." + garden[0] + ".";
		string s2 = "." + garden[1] + ".";
		int sz = s1.length();
		max = count(garden[0], garden[1]);
		for (int i = 1; i < sz - 1; i++) {
			if ((s1[i - 1] != '*' && s2[i - 1] != '*') && (s1[i + 1] != '*' && s2[i + 1] != '*') && s1[i] != '*' && s2[i] != '*') {
				max++;
				s1[i] = '*';
			}
		}

		return max;
	}


	int count(string s1, string s2) {
		int count = 0;
		for (int i = 0; i != s1.length(); i++) {
			if (s1[i] == '*')
				count++;
			if (s2[i] == '*')
				count++;
		}

		return count;
	}
};
