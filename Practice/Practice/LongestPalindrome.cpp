/*
	Problem: 
	Given a string S, find the longest palindromic substring in S

	Ans 1: time O (N^2) space O (N^2)
	P(i, j) is a substring of S from i -> j 
	If P(i, j) == true if P(i + 1, j - 1) == true && S[i] == S[j]
	P(i, i) = true;
	P(i, i+1) = true if S[i] == S[i + 1];


	Ans 2: expand around center (time o (N^2) space O (1))
	each string has N centers (1 char center) and N - 1 (2 char center) -> total of 2*N - 1 center

*/
#include "lib.h"

#define SIZE 10

class LongestPalindrome {
private:
	void show(bool table[SIZE][SIZE]) {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				cout << table[i][j] << "  ";
			}
			cout << endl;
		}
	}

public:
	//Ans 1: dynamic programming
	string getSubstring(string line) {
		string result;

		int sz = line.length();
		int max = 0;
		int maxIdx = -1;
	
		bool table[SIZE][SIZE] = { false };

		//P(i, i) = true;
		for (int i = 0; i < sz; i++) {
			table[i][i] = true;
		}

		//P(i, i + 1) = true;
		for (int i = 0; i < sz - 1; i++) {
			if (line[i] == line[i + 1]) {
				table[i][i + 1] = true;
				max = 2;
				maxIdx = i;
			}
		}
		
		for (int len = 3; len <= sz; len++) {
			for (int i = 0; i <= sz - len; i++) {
				int j = i + len - 1;
				if (table[i + 1][j - 1] == true && line[i] == line[j]) {
					table[i][j] = true;
					max = len; 
					maxIdx = i;
				}
			}
		}

		result = line.substr(maxIdx, max);

		return result;
	}

	//Ans 2: expand the center
	string getExpandStr(string line, int i, int j) {
		string result;

		int left = i; 
		int right = j;

		while (left >= 0 && right < line.length() && line[left] == line[right]) {
			left--;
			right++;
		}
		left++; right--;

		result = line.substr(left, right - left + 1);

		return result;
	}

	string expand(string line) {
		string result;
		int max = 0;
		int sz = line.length();

		for (int i = 0; i < sz; i++) {
			string tmp = getExpandStr(line, i, i);
			if (tmp.length() > max) {
				max = tmp.length();
				result = tmp;
			}
		}

		for (int i = 0; i < sz - 1; i++) {
			string tmp = getExpandStr(line, i, i + 1);
			if (tmp.length() > max) {
				max = tmp.length();
				result = tmp;
			}
		}

		return result;
	}
};