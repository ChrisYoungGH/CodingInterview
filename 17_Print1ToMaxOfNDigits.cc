// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

// 解法1: 模拟+1, 确定溢出.
// 解法2: 全排列回溯, 注意输出时去掉前缀0.

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    vector<string> Print1ToMaxOfNDigits(int n) {
        vector<string> res;

        if (n <= 0) return res;

        string numStr(n, '0');
        while (increment(numStr)) {
            printNum(res, numStr);
        }

        return res;
    }

    bool increment(string &numStr) {
        int carry = 1;
        for (int i = int(numStr.size()) - 1; i >= 0; i--) {
            int curr = numStr[i] - '0';
            int sum = curr + carry;
            curr = sum % 10;
            carry = sum / 10;
            numStr[i] = curr + '0';
        }

        return !carry;
    }

    void printNum(vector<string> &res, string &numStr) {
        int n = numStr.size();
        int begin = n;
        for (int i = 0; i < n; i++) {
            if (numStr[i] != '0') {
                begin = i;
                break;
            }
        }

        if (begin < n) {
            res.emplace_back(numStr.substr(begin));
        }
    }
};


class Solution2 {
public:
    vector<string> Print1ToMaxOfNDigits(int n) {
        vector<string> res;
        if (n <= 0) {
            return res;
        }

        string numStr(n, '0');
        printRecursive(res, numStr, n, 0);

        return res;
    }

    void printRecursive(vector<string> &res, string &numStr, int n, int begin) {
        if (n <= 0) {
            printNum(res, numStr);
            return;
        }

        for (int i = 0; i <= 9; i++) {
            numStr[begin] = i + '0';
            printRecursive(res, numStr, n-1, begin+1);
        }
    }

    void printNum(vector<string> &res, string &numStr) {
        int n = numStr.size();
        int begin = n;
        for (int i = 0; i < n; i++) {
            if (numStr[i] != '0') {
                begin = i;
                break;
            }
        }
        if (begin < n) {
            res.emplace_back(numStr.substr(begin));
        }
    }
};



class Check {
public:
    static vector<string> Print1ToMaxOfNDigits(int n)
    {
        vector<string> res;

        if (n <= 0)
            return res;

        char* number = new char[n + 1];
        number[n] = '\0';


        for (int i = 0; i < 10; ++i)
        {
            number[0] = i + '0';
            Print1ToMaxOfNDigitsRecursively(res, number, n, 0);
        }

        delete[] number;

        return res;
    }

    static void Print1ToMaxOfNDigitsRecursively(vector<string> &res, char* number, int length, int index)
    {
        if (index == length - 1)
        {
            PrintNumber(res, number);
            return;
        }

        for (int i = 0; i < 10; ++i)
        {
            number[index + 1] = i + '0';
            Print1ToMaxOfNDigitsRecursively(res, number, length, index + 1);
        }
    }

    // ====================公共函数====================
    // 字符串number表示一个数字，数字有若干个0开头
    // 打印出这个数字，并忽略开头的0
    static void PrintNumber(vector<string> &res, char* number)
    {
        bool isBeginning0 = true;
        int nLength = strlen(number);

        int begin = nLength;
        for (int i = 0; i < nLength; ++i)
        {
            if (number[i] != '0') {
                begin = i;
                break;
            }
        }

        if (begin < nLength) {
            res.push_back(string(number+begin));
        }
    }

    static bool check(int n, vector<string> &res) {
        vector<string> expect = Print1ToMaxOfNDigits(n);
        bool correct = true;
        if (res.size() != expect.size()) {
            cout << "Size: " << res.size() << " " << expect.size() << endl;
            correct = false;
        }
        for (int i = 0; i < res.size(); i++) {
            if (res[i] != expect[i]) {
                cout << res[i] << " " << expect[i] << endl;
                correct = false;
                break;
            }
        }
        return correct;
    }
};


// ====================测试代码====================
void Test(int n)
{
    Solution1 s1 = Solution1();
    vector<string> res1 = s1.Print1ToMaxOfNDigits(n);
    bool status1 = Check::check(n, res1);
    cout << "Solution1: Test for " << n << " " << (status1 ? "pass" : "FAILED") << "." << endl;

    Solution2 s2 = Solution2();
    vector<string> res2 = s2.Print1ToMaxOfNDigits(n);
    bool status2 = Check::check(n, res2);
    cout << "Solution1: Test for " << n << " " << (status2 ? "pass" : "FAILED") << "." << endl;
}


int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

    return 0;
}
