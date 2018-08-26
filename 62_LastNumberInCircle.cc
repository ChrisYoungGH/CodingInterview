// 面试题62：圆圈中最后剩下的数字
// 题目：0, 1, …, n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里
// 删除第m个数字。求出这个圆圈里剩下的最后一个数字。

// 解法1: 模拟, 使用list.
// 解法2: f(n,m) = (f(n-1, m) + m) % n, f(1,m) = 0.

#include "utils.h"

class Solution {
public:
	int LastRemaining(int n, int m) {
		if (n <= 0 || m <= 0) return -1;
		list<int> circle;
		for (int i = 0; i < n; i++) {
			circle.push_back(i);
		}

		list<int>::iterator curr = circle.begin();	
		while (circle.size() > 1) {
			for (int i = 0; i < m-1; i++) {
				curr++;
				if (curr == circle.end()) curr = circle.begin();
			}
			list<int>::iterator byebye = curr;
			curr++;
			if (curr == circle.end()) curr = circle.begin();
			circle.erase(byebye);
		}

		return *curr;
	}
};

class Solution2 {
public:
	int LastRemaining(int n, int m) {
		int res = 0;
		for (int i = 2; i <= n; i++)	{
			res = (res + m) % i;
		}
		return n > 0 && m > 0 ? res : -1;
	}
};

// ====================测试代码====================
void Test(string testName, unsigned int n, unsigned int m, int expected) {
    printf("%s begins: \n", testName.c_str());

    if(Solution().LastRemaining(n, m) == expected)
        printf("Solution1 passed.\n");
    else
        printf("Solution1 failed.\n");

    if(Solution2().LastRemaining(n, m) == expected)
        printf("Solution2 passed.\n");
    else
        printf("Solution2 failed.\n");

    printf("\n");
}

void Test1()
{
    Test("Test1", 5, 3, 3);
}

void Test2()
{
    Test("Test2", 5, 2, 2);
}

void Test3()
{
    Test("Test3", 6, 7, 4);
}

void Test4()
{
    Test("Test4", 6, 6, 3);
}

void Test5()
{
    Test("Test5", 0, 0, -1);
}

void Test6()
{
    Test("Test6", 4000, 997, 1027);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
