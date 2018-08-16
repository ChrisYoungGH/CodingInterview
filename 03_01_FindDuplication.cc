// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

// 解法: 每次将i位置的数交换到与其值相等的a[i]位置, 在交换前检验该位置是否已经有对应的数.
// Time: O(n), Space: O(1).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int duplicate(vector<int> &arr) {
		int n = arr.size();
		if (!n) {
			return -1;
		}

		for (int num : arr) {
			if (num < 0 || num >= n) {
				return -1;
			}
		}

		int i = 0;
		while (i < n) {
			int curr = arr[i];
			if (curr == i) {
				i++;
			}
			else {
				if (arr[curr] == curr) {
					return curr;
				}
				swap(arr[i], arr[curr]);
			}
		}
		return -1;
	}
};


void check(vector<int> &arr, set<int> &ans, int caseNum) {
	bool correct = false;

	vector<int> vec = arr;
	set<int> ansSet = ans;
	try {
		Solution s = Solution();
		int res = s.duplicate(vec);
		correct = ansSet.find(res) != ansSet.end();
	}
	catch (exception e) {
		correct = false;
	}
	cout << "case " << caseNum << ": " << (correct ? "Correct" : "Wrong") << endl;
}


int main() {
	vector<int> arr;
	set<int> ans;

	// 重复的数字是数组中最小的数字
	arr = {2, 1, 3, 1, 4};
	ans = {1};
	check(arr, ans, 1);

	// 重复的数字是数组中最大的数字
	arr = {2, 4, 3, 1, 4};
	ans = {4};
	check(arr, ans, 2);

	// 数组中存在多个重复的数字
	arr = {2, 4, 2, 1, 4};
	ans = {2, 4};
	check(arr, ans, 3);

	// 没有重复的数字
	arr = {2, 1, 3, 0, 4};
	ans = {-1};
	check(arr, ans, 4);

	// 没有重复的数字
	arr = {2, 1, 3, 5, 4};
	ans = {-1};
	check(arr, ans, 5);

	// 无效的输入
	arr = {};	
	ans = {-1};
	check(arr, ans, 6);

	return 0;
}