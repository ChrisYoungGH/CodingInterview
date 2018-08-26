// 面试题67：把字符串转换成整数
// 题目：请你写一个函数StrToInt，实现把字符串转换成整数这个功能。当然，不
// 能使用atoi或者其他类似的库函数。

#include "utils.h"

bool g_nStatus = true;

class Solution
{
public:
	int StrToInt(const char* str) {
		g_nStatus = true;

		if (!str || !strlen(str)) {
			g_nStatus = false;
			return 0;
		}

		int n = strlen(str);
		int start = n;
		for (int i = 0; i < n; i++) {
			if (str[i] != ' ') {
				start = i;
				break;
			}
		}
		if (start == n) {
			g_nStatus = false;
			return 0;
		}

		int sign = 1;
		if (str[start] == '+') {
			sign = 1;
			start++;
		}
		else if (str[start] == '-') {
			sign = -1;
			start++;
		}

		int end = n;
		for (int i = start; i < n; i++) {
			if (str[i] < '0' || str[i] > '9') {
				end = i;
				break;
			}
		}
		if (end <= start) {
			g_nStatus = false;
			return 0;
		}


		long res = 0;
		for (int i = start; i < end; i++) {
			res = res * 10L + (str[i] - '0');
			if (res > long(INT_MAX) + 1) {
				g_nStatus = false;
				return 0;
			}
		}

		if (sign == -1) {
			res = -res;
		}
		if (res > long(INT_MAX) || res < long(INT_MIN)) {
			g_nStatus = false;
			return 0;
		}

		return int(res);
	}
};


// ====================测试代码====================
void Test(const char* str)
{
    int result = Solution().StrToInt(str);
    int expected = atoi(str);
    cout << "Test " << str << " " << result << " " << expected << endl;
}

int main(int argc, char* argv[])
{
    // Test(nullptr);

    Test("");

    Test("123");

    Test("+123");
    
    Test("-123");

    Test("1a33");

    Test("+0");

    Test("-0");

    //有效的最大正整数, 0x7FFFFFFF
    Test("+2147483647");    

    Test("-2147483647");

    Test("+2147483648");

    //有效的最小负整数, 0x80000000
    Test("-2147483648");    

    Test("+2147483649");

    Test("-2147483649");

    Test("+");

    Test("-");

    return 0;
}