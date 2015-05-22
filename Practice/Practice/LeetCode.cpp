
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	int sumNumbers(TreeNode* root) {
		int sum = 0;
		string s = "";
		traverse(root, s, sum);
		return sum;
	}

	void traverse(TreeNode* node, string numStr, int &sum) {
		
		if (node == nullptr) {
			return;
		}

		numStr += to_string(node->val);

		if (node->left != nullptr) {
			traverse(node->left, numStr, sum);
		}

		if (node->right != nullptr) {
			traverse(node->right, numStr, sum);
		}

		if (node->left == nullptr && node->right == nullptr) {
			sum += atoi(numStr.c_str());
		}
	}
};