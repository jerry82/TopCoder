#include<iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <limits>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <list>
#include <forward_list>
using namespace std;

#include "Source.cpp";

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

//http://en.cppreference.com/w/cpp/container
void cheat() {
	//double linked list
	list<string> ll;

	//single linked list 
	forward_list<string> fl;



	queue<string> myQ; 
	//myQ.push(value) -> push value to queue
	//myQ.size() -> return size of queue
	//myQ.front() -> return first one added
	//myQ.back() -> return last one added
	//myQ.pop() -> delete first added 

	stack<string> myS;
	//myS.push() -> push value
	//myS.size() -> return size of stack
	//myS.pop() -> remove top one
	//myS.top() -> return top one

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

}

int main() {
	string line;

	Birthday bd;
	string c = "06/17";
	vector<string> b = { "02/17 Wernie", "10/12 Stefan" };

	cout << bd.getNext(c, b);

	getline(cin, line);
	return 0;
}

