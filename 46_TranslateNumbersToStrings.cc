// 面试题46：把数字翻译成字符串
// 题目：给定一个数字，我们按照如下规则把它翻译为字符串：0翻译成"a"，1翻
// 译成"b"，……，11翻译成"l"，……，25翻译成"z"。一个数字可能有多个翻译。例
// 如12258有5种不同的翻译，它们分别是"bccfi"、"bwfi"、"bczi"、"mcfi"和
// "mzi"。请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。

// 解法: 因为是计数不是求所有结果, 所以没必要回溯. 每个位置的结果取决于当前位置i字符与i+1开始的子串的结果,
// 以及下一位置i+1字符与i+2开始的子串的结果. 故使用DP从后往前算更好. 因为是一维且只有三个位置相关, 只需要三个变量记录,
// 空间复杂度为O(1).

#include "utils.h"

class Solution {
public:
	int GetTranslationCount(int num) {
		if (num < 0) return 0;

		string numStr = to_string(num);
		int n = numStr.length();
		if (!n) return 0;
		if (n == 1) return 1;

		int next2 = 1, next1 = 1;
		int rep = (numStr[n-2] - '0') * 10 + (numStr[n-1] - '0');
		if (rep >= 10 && rep <= 25) {
			next1 += 1;
		}
		int curr = next1;

		for (int i = n-3; i >= 0; i--) {
			int rep = (numStr[i] - '0') * 10 + (numStr[i+1] - '0');
			if (rep >= 10 && rep <= 25) {
				curr = next1 + next2;
			}
			else curr = next1;

			next2 = next1;
			next1 = curr;
		}

		return curr;
	}
};

// ====================测试代码====================
void Test(const string& testName, int number, int expected)
{	
	Solution s = Solution();
	int res = s.GetTranslationCount(number);
    if(res == expected)
        cout << testName << " passed." << endl;
    else
        cout << testName << " FAILED: " << "res=" << res << ", expected=" << expected << endl;
}

void Test1()
{
    int number = 0;
    int expected = 1;
    Test("Test1", number, expected);
}

void Test2()
{
    int number = 10;
    int expected = 2;
    Test("Test2", number, expected);
}

void Test3()
{
    int number = 125;
    int expected = 3;
    Test("Test3", number, expected);
}

void Test4()
{
    int number = 126;
    int expected = 2;
    Test("Test4", number, expected);
}

void Test5()
{
    int number = 426;
    int expected = 1;
    Test("Test5", number, expected);
}

void Test6()
{
    int number = 100;
    int expected = 2;
    Test("Test6", number, expected);
}

void Test7()
{
    int number = 101;
    int expected = 2;
    Test("Test7", number, expected);
}

void Test8()
{
    int number = 12258;
    int expected = 5;
    Test("Test8", number, expected);
}

void Test9()
{
    int number = -100;
    int expected = 0;
    Test("Test9", number, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}