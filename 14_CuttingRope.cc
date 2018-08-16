// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。

// 解法1: 动态规划, f(i) = max(f(j)*f(n-j)), 0<j<i.
// 解法2: 贪心, 长度>=5时减最多的3.

#include <bits/stdc++.h>
using namespace std;

// ====================动态规划====================
class Solution1 {
public:
    int maxProduct(int length) {
        if (length <= 0) return 0;

        vector<int> products(length+1, 0);
        for (int i = 0; i < length; i++) {
            products[i] = i;
        }

        for (int i = 2; i <= length; i++) {
            for (int j = 1; j <= i / 2; j++) {
                products[i] = max(products[i], products[j] * products[i-j]);
            }
        }

        return products[length];
    }
};


// ====================贪婪算法====================
class Solution2 {
public:
    int maxProduct(int length) {
        if (length <= 1) return 0;
        if (length == 2) return 1;
        if (length == 3) return 2;
        if (length == 4) return 4;
        int n3 = length / 3;
        int remain = length % 3;
        if (remain == 1) {
            n3--;
            remain += 3;
        }
        return pow(3, n3) * (remain != 0 ? remain : 1);
    }
};


// ====================测试代码====================
void test(const char* testName, int length, int expected) {
    Solution1 s1 = Solution1();
    int result1 = s1.maxProduct(length);
    if(result1 == expected)
        std::cout << "Solution1 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution1 for " << testName << " FAILED." << std::endl;

    Solution2 s2 = Solution2();
    int result2 = s2.maxProduct(length);
    if(result2 == expected)
        std::cout << "Solution2 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution2 for " << testName << " FAILED." << std::endl;
}

void test1()
{
    int length = 1;
    int expected = 0;
    test("test1", length, expected);
}

void test2()
{
    int length = 2;
    int expected = 1;
    test("test2", length, expected);
}

void test3()
{
    int length = 3;
    int expected = 2;
    test("test3", length, expected);
}

void test4()
{
    int length = 4;
    int expected = 4;
    test("test4", length, expected);
}

void test5()
{
    int length = 5;
    int expected = 6;
    test("test5", length, expected);
}

void test6()
{
    int length = 6;
    int expected = 9;
    test("test6", length, expected);
}

void test7()
{
    int length = 7;
    int expected = 12;
    test("test7", length, expected);
}

void test8()
{
    int length = 8;
    int expected = 18;
    test("test8", length, expected);
}

void test9()
{
    int length = 9;
    int expected = 27;
    test("test9", length, expected);
}

void test10()
{
    int length = 10;
    int expected = 36;
    test("test10", length, expected);
}

void test11()
{
    int length = 50;
    int expected = 86093442;
    test("test11", length, expected);
}

int main(int agrc, char* argv[])
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
    test11();

    return 0;
}