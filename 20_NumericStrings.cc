// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是

// 解法: 数表示: A[.[B]][(e|E)C]或.B[(e|E)C], 依次提取整数部分, 小数部分, 指数部分, 
// 结果为 Z (如果有小数点则 || F) (如果有指数符号 && E), 检查时记录长度和符号, 扫描移动位置指针.

#include "utils.h"

class Solution {
public:
	bool isNumeric(string &str) {
		int pos = 0;

		bool sign = false;
		int numLen = scan(str, pos, sign);
		bool numeric = numLen > 0;
		pos += sign + numLen;

		if (str[pos] == '.') {
			pos++;
			numLen = scan(str, pos, sign);
			numeric = numeric || (numLen > 0);
			pos += sign + numLen;
		}

		if (str[pos] == 'E' || str[pos] == 'e') {
			pos++;
			numLen = scan(str, pos, sign);
			numeric = numeric && (numLen > 0);
			pos += sign + numLen;
		}

		return numeric && str.length() && pos == str.length();
	}

	int scan(string &str, int pos, bool &sign) {
		sign = (str[pos] == '+' || str[pos] == '-');

		int len = 0;
		for (int i = pos + sign; i < str.length(); i++) {
			if (str[i] >= '0' && str[i] <= '9') len++;
			else break;
		}
		return len;
	}
};

class Solution2 {
public:
    bool isNumeric(const char* str)
    {
    	if (!str) return false;

        int prevLen = 0;
        bool numeric = scan(str, prevLen);
        str += prevLen;
        
        if (*str == '.') {
        	int lastLen = 0;
            numeric = scan(++str, lastLen) || numeric;
            str += lastLen;
        }
        if (*str == 'E' || *str == 'e') {
        	int lastLen = 0;
            numeric = scan(++str, lastLen) && numeric;
            str += lastLen;
        }
        
        return numeric && *str == '\0';
    }
    
    bool scan(const char *str, int &len) {
        if (!str) return false;

        bool sign = str[0] == '+' || str[0] == '-';
        len += sign;

        for (int i = sign; str[i] != '\0'; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                len++;
            }
            else break;
        }

        return len - sign > 0;
    }
};

// ====================Test====================
void Test(const char* testName, string str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    Solution s = Solution();
    if(s.isNumeric(str) == expected)
        printf("Passed");
    else
        printf("FAILED");
    cout << " " << str << endl;
}


int main(int argc, char* argv[])
{
    Test("Test1", "100", true);
    Test("Test2", "123.45e+6", true);
    Test("Test3", "+500", true);
    Test("Test4", "5e2", true);
    Test("Test5", "3.1416", true);
    Test("Test6", "600.", true);
    Test("Test7", "-.123", true);
    Test("Test8", "-1E-16", true);
    Test("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    Test("Test10", "12e", false);
    Test("Test11", "1a3.14", false);
    Test("Test12", "1+23", false);
    Test("Test13", "1.2.3", false);
    Test("Test14", "+-5", false);
    Test("Test15", "12e+5.4", false);
    Test("Test16", ".", false);
    Test("Test17", ".e1", false);
    Test("Test18", "e1", false);
    Test("Test19", "+.", false);
    Test("Test20", "", false);
    // Test("Test21", nullptr, false);

    return 0;
}
