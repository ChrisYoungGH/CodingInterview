// 面试题49：丑数
// 题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
// 大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做第一个丑数。

// 解法: 开辟一个数组来存找到的丑数, 空间换时间. 下一个丑数一定是之前的某个丑数*2或*3或*5得到.
// 某个丑数前一段*factor小于当前数, 而后一段*factor大于. 每次分别记录2,3,5的这个位置.
// 时间: O(n), 空间: O(n)

#include "utils.h"

class Solution {
public:
	int GetUglyNumber(int n) {
		if (n <= 0) return 0;
		vector<int> uglyNumber(n);
		uglyNumber[0] = 1;

		int ugly2 = 0, ugly3 = 0, ugly5 = 0;
		for (int i = 1; i < n; i++) {
			uglyNumber[i] = min(uglyNumber[ugly2] * 2, min(uglyNumber[ugly3] * 3, uglyNumber[ugly5] * 5));
			while (uglyNumber[ugly2] * 2 <= uglyNumber[i]) ugly2++;
			while (uglyNumber[ugly3] * 3 <= uglyNumber[i]) ugly3++;
			while (uglyNumber[ugly5] * 5 <= uglyNumber[i]) ugly5++;
		}

		return uglyNumber.back();
	}
};

// ====================测试代码====================
void Test(int index, int expected)
{
	Solution s = Solution();
    if(s.GetUglyNumber(index) == expected)
        printf("solution1 passed\n");
    else
        printf("solution1 failed\n");
}

int main(int argc, char* argv[])
{
    Test(1, 1);

    Test(2, 2);
    Test(3, 3);
    Test(4, 4);
    Test(5, 5);
    Test(6, 6);
    Test(7, 8);
    Test(8, 9);
    Test(9, 10);
    Test(10, 12);
    Test(11, 15);

    Test(1500, 859963392);

    Test(0, 0);

    return 0;
}
