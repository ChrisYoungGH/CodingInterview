// 面试题45：把数组排成最小的数
// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼
// 接出的所有数字中最小的一个。例如输入数组{3, 32, 321}，则打印出这3个数
// 字能排成的最小数字321323。

// 解法: 比较两个数的两种拼接方式并排序.

#include "utils.h"

class Solution {
public:
	long PrintMinNumber(vector<int> &arr) {
		int n = arr.size();
		if (!n) return -1;

		sort(arr.begin(), arr.end(), cmp);

		stringstream ss;
		for (int num : arr) {
			ss << num;
		}
		long res;
		ss >> res;

		return res;
	}

	static int cmp(int num1, int num2) {
		string s1 = to_string(num1);
		string s2 = to_string(num2);
		return s1 + s2 < s2 + s1;
	}
};

// ====================测试代码====================
void Test(string testName, vector<int> &numbers, long expectedResult)
{
    Solution s = Solution();
    long res = s.PrintMinNumber(numbers);
    cout << testName << " begins: " << (res == expectedResult ? "passed." : "FAILED.") << endl;
}

void Test1()
{
    vector<int> numbers = {3, 5, 1, 4, 2};
    Test("Test1", numbers, 12345L);
}

void Test2()
{
    vector<int> numbers = {3, 32, 321};
    Test("Test2", numbers, 321323L);
}

void Test3()
{
    vector<int> numbers = {3, 323, 32123};
    Test("Test3", numbers, 321233233L);
}

void Test4()
{
    vector<int> numbers = {1, 11, 111};
    Test("Test4", numbers, 111111L);
}

// 数组中只有一个数字
void Test5()
{
    vector<int> numbers = {321};
    Test("Test5", numbers, 321L);
}


int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}