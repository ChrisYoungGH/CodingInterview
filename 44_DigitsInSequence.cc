// 面试题44：数字序列中某一位的数字
// 题目：数字以0123456789101112131415…的格式序列化到一个字符序列中。在这
// 个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。请写一
// 个函数求任意位对应的数字。

// 解法: 先找对应的数, 再找该数对应的位. 找数时先找对应长度的数区间, 再找对应的数.

#include "utils.h"

class Solution {
public:
	int digitAtIndex(int index) {
		if (index < 0) {
			return -1;
		}

		int digits = 1;
		while (true) {
			int cnt = numCountOfDigit(digits);
			if (index < cnt) {
				return digitOfIndexPos(digits, index);
			}
			index -= cnt;
			digits++;
		}
		return -1;
	}

	int numCountOfDigit(int digits) {
		if (digits == 1)
			return 10;
		return 9 * digits * pow(10, digits-1);
	}

	int digitOfIndexPos(int digits, int index) {
		int num = index / digits + beginNum(digits);
		int posFromRight = digits - index % digits;
		for (int i = 0; i < posFromRight-1; i++) {
			num /= 10;
		}
		return num % 10;
	}

	int beginNum(int digits) {
		if (digits == 1) {
			return 0;
		}
		return pow(10, digits-1);
	}
};


// ====================测试代码====================
void test(string testName, int inputIndex, int expectedOutput)
{
	Solution s = Solution();
	if(s.digitAtIndex(inputIndex) == expectedOutput)
		cout << testName << " passed." << endl;
	else
		cout << testName << " FAILED." << endl;
}


int main()
{
	test("Test1", 0, 0);
	test("Test2", 1, 1);
	test("Test3", 9, 9);
	test("Test4", 10, 1);
	test("Test5", 189, 9);  // 数字99的最后一位，9
	test("Test6", 190, 1);  // 数字100的第一位，1
	test("Test7", 1000, 3); // 数字370的第一位，3
	test("Test8", 1001, 7); // 数字370的第二位，7
	test("Test9", 1002, 0); // 数字370的第三位，0
	return 0;
}
