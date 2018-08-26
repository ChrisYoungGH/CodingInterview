// 面试题57（二）：和为s的连续正数序列
// 题目：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
// 例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、
// 4～6和7～8。

// 解法: 最外面一直加尾, 里面大于时一直减头直到小于等于, 如果等于计入一个结果. s/2上取整停止.

#include "utils.h"

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int> > res;
		if (sum < 3) return res;

		int start = 1, end = 2;
		int mid = (sum + 1) / 2;
		int currSum = start + end;

		while (start < mid) {
			while (start < mid && currSum > sum) {
				currSum -= start;
				start++;
			}
			
			if (currSum == sum) {
				vector<int> one;
				for (int i = start; i <= end; i++) {
					one.push_back(i);
				}
				res.push_back(one);
			}

			end++;
			currSum += end;
		}

		return res;
	}
	
};

// ====================测试代码====================
void Test(string testName, int sum)
{
    printf("%s begins: %d\n", testName.c_str(), sum);
    Solution s = Solution();
    vector<vector<int> > res = s.FindContinuousSequence(sum);
    PrintMatrix(res);
}

int main(int argc, char* argv[])
{
    Test("test1", 1);
    Test("test2", 3);
    Test("test3", 4);
    Test("test4", 9);
    Test("test5", 15);
    Test("test6", 100);

    return 0;
}