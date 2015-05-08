#include<iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

//define
#define all(v) v.begin(), v.end()
#define rep(i, n, m) for (int i = (int)(n); i < (int)(m); ++i) 

//count number of 1 bit
int countBits(int mask) {
	int res = 0;
	while (mask) 
		mask &= (mask - 1), ++res;
	return res;
}

void cheat() {
	vector<int> myVector;
	//if (find(added.begin(), added.end(), j) != added.end()) -> element found in vector

	//myVector.push_back(value) -> adds element to END
	//myVector.at(index) -> return element at index
	//myVector.size() -> return unsigned size
	//myVector.begin() -> read from first element (idx=0)
	//myVector.insert(myVector.begin() + integer, new value) -> add element BEFORE idx
	//myVector.erase(myVector.begin() + integer) -> remove at idx
	//myVector.clear() -> remove all 
	//myVector.empty() -> check empty

	string myString = "0123456";
	//.size() -> same as length()
	//.at(int) -> return character at idx
	//.append(string) -> concatenate at the end
	//.insert(index, string, start, length) -> insert string BEFORE index...string is subst (start->length)-> ORIGINAL is overwritten
	//.substr(start, length) -> NOT OverWritten  original string

	string insertA = "ABCDE";
	cout << myString.insert(4, insertA, 1, 3) << endl;

	cout << myString.substr(0, 3) << endl;

	cout << myString.find("0");
}

int main() {
	string line;

	int bits = countBits(15);

	cout << bits << endl;
		
	getline(cin, line);
	return 0;
}

