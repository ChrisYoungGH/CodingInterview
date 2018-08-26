// 面试题48：最长不含重复字符的子字符串
// 题目：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子
// 字符串的长度。假设字符串中只包含从'a'到'z'的字符。

// 解法: 每次查看当前字符之前是否出现, 以及出现的位置是否为当前子串范围内. 注意最后一个字符位置有可能没计算在循环里, 需要单独计算.


# include "utils.h"

class Solution {
public:
	int longestSubstringWithoutDuplication(string str) {
		vector<int> ch(26, -1);
		int currLen = 0, maxLen = 0;

		for (int i = 0; i < str.length(); i++) {
			int prev = ch[str[i] - 'a'];
			if (prev == -1 || i - prev > currLen) {
				currLen++;
			}
			else {
				maxLen = max(maxLen, currLen);
				currLen = i - prev;
			}
			ch[str[i] - 'a'] = i;
		}

		return max(maxLen, currLen);		// the last one 
	}
};



// ====================测试代码====================
void testSolution1(const std::string& input, int expected)
{
	Solution s = Solution();
    int output = s.longestSubstringWithoutDuplication(input);
    if(output == expected)
        std::cout << "Solution 1 passed, with input: " << input << std::endl;
    else
        std::cout << "Solution 1 FAILED, with input: " << input << std::endl;
}

void test(const std::string& input, int expected)
{
    testSolution1(input, expected);
}

void test1()
{
    const std::string input = "abcacfrar";
    int expected = 4;
    test(input, expected);
}

void test2()
{
    const std::string input = "acfrarabc";
    int expected = 4;
    test(input, expected);
}

void test3()
{
    const std::string input = "arabcacfr";
    int expected = 4;
    test(input, expected);
}

void test4()
{
    const std::string input = "aaaa";
    int expected = 1;
    test(input, expected);
}

void test5()
{
    const std::string input = "abcdefg";
    int expected = 7;
    test(input, expected);
}

void test6()
{
    const std::string input = "aaabbbccc";
    int expected = 2;
    test(input, expected);
}

void test7()
{
    const std::string input = "abcdcba";
    int expected = 4;
    test(input, expected);
}

void test8()
{
    const std::string input = "abcdaef";
    int expected = 6;
    test(input, expected);
}

void test9()
{
    const std::string input = "a";
    int expected = 1;
    test(input, expected);
}

void test10()
{
    const std::string input = "";
    int expected = 0;
    test(input, expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}