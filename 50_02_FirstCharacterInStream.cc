// 面试题50（二）：字符流中第一个只出现一次的字符
// 题目：请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从
// 字符流中只读出前两个字符"go"时，第一个只出现一次的字符是'g'。当从该字
// 符流中读出前六个字符"google"时，第一个只出现一次的字符是'l'。

// 解法: 数组存对应字符出现的位置. 初始化为-1, 插入时没出现过则更新位置, 出现过则置为-2.
// 查找时找到位置>=0的字符中位置最小的.

#include "utils.h"

class Solution {
public:
	Solution() {
		for (int i = 0; i < 256; i++) ch[i] = -1;
	}

	void Insert(char c) {
		if (ch[c] == -1) ch[c] = index++;
		else if (ch[c] >= 0) ch[c] = -2;
	}

	char FirstAppearingOnce() {
		int min_index = INT_MAX;
		char res = '\0';
		for (int i = 0; i < 256; i++) {
			if (ch[i] >= 0 && ch[i] < min_index) {
				min_index = ch[i];
				res = (char)i;
            }
		}

		return res;
	}

private:
	int ch[256];
	int index = 0;
};

// ====================测试代码====================
void Test(string testName, Solution chars, char expected)
{
    printf("%s begins: ", testName.c_str());
    char res = chars.FirstAppearingOnce();
    if(res == expected)
        printf("Passed.\n");
    else
        printf("FAILED. res=%c, expected=%c\n", res, expected);
}

int main(int argc, char* argv[])
{
    Solution chars;

    Test("Test1", chars, '\0');

    chars.Insert('g');
    Test("Test2", chars, 'g');

    chars.Insert('o');
    Test("Test3", chars, 'g');

    chars.Insert('o');
    Test("Test4", chars, 'g');

    chars.Insert('g');
    Test("Test5", chars, '\0');

    chars.Insert('l');
    Test("Test6", chars, 'l');

    chars.Insert('e');
    Test("Test7", chars, 'l');

    return 0;
}