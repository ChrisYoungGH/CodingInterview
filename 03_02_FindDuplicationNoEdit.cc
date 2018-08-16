// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。

// 解法: 二分查找, n+1个位置放1~n, 取中点n/2将数组按与n/2相比的大小分成两半, 
// 则必有一半有重复(此时长度>n/2).
// Time: O(nlogn), Space: O(1).

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
			if (num < 1 || num > n-1) {
				return -1;
			}
		}

		// find duplicates
		int low = 1, high = n - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			int cnt = countRange(arr, low, mid);

			if (low == high) {
				if (cnt > 1) return low;
				return -1;
			}

			if (cnt > mid - low + 1) high = mid;
			else low = mid + 1;		// notice that cnt == m-l+1 here and [l,m] will not be checked next
		}

		return -1;
	}

private:
	int countRange(vector<int> &arr, int low, int high) {
		int cnt = 0;
		for (int num : arr) {
			if (num >= low && num <= high) {
				cnt++;
			}
		}
		return cnt;
	}
};

void check(vector<int> &arr, set<int> &ans, int caseNum) {
	bool correct = false;

	vector<int> vec = arr;
	set<int> ansSet = ans;
	int res = INT_MIN;
	try {
		Solution s = Solution();
		res = s.duplicate(vec);
		correct = ansSet.find(res) != ansSet.end();
	}
	catch (exception e) {
		correct = false;
	}
	
	cout << "case " << caseNum << ": ";
	if (correct) cout << "Correct.";
	else {
		cout << "Wrong. arr: ";
		for (int num : arr) cout << num << " ";
		cout << ", res: " << res << ", ans: ";
		for (int num : ans) cout << num << " ";
	}
	cout << endl;
}


int main() {
	vector<int> arr;
	set<int> ans;

	int nCases = 0;

	// 多个重复的数字
	arr = { 2, 3, 5, 4, 3, 2, 6, 7 };
	ans = { 2, 3 };
	check(arr, ans, ++nCases);

	// 一个重复的数字
	arr = { 3, 2, 1, 4, 4, 5, 6, 7 };
	ans = { 4 };
	check(arr, ans, ++nCases);

	// 重复的数字是数组中最小的数字
	arr = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
	ans = { 1 };
	check(arr, ans, ++nCases);

	// 重复的数字是数组中最大的数字
	arr = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
	ans = { 8 };
	check(arr, ans, ++nCases);

	// 数组中只有两个数字
	arr = { 1, 1 };
	ans = { 1 };
	check(arr, ans, ++nCases);

	// 重复的数字位于数组当中
	arr = { 3, 2, 1, 3, 4, 5, 6, 7 };
	ans = { 3 };
	check(arr, ans, ++nCases);

	// 多个重复的数字
	arr = { 1, 2, 2, 6, 4, 5, 6 };
	ans = { 2, 6 };
	check(arr, ans, ++nCases);

	// 一个数字重复三次
	arr = { 1, 2, 2, 6, 4, 5, 2 };
	ans = { 2 };
	check(arr, ans, ++nCases);

	// 没有重复的数字
	arr = { 1, 2, 6, 4, 5, 3 };
	ans = { -1 };
	check(arr, ans, ++nCases);

	// 无效的输入
	arr = {};
	ans = { -1 };
	check(arr, ans, ++nCases);


	return 0;
}