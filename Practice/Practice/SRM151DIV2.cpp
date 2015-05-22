#include "lib.h"

class PrefixCode {
public:
	string isOne(vector<string> words) {

		if (words.size() < 1 && words.size() > 50) return "No";
		if (words.size() == 1) return "Yes";

		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words.size(); j++) {
				if (i != j && (words[i].length() < words[j].length())) {
					if (words[j].find(words[i]) == 0)
						return "No, " + to_string(i);
				}
			}
		}

		return "Yes";
	}
};

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