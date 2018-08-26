// 面试题47：礼物的最大价值
// 题目：在一个m×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值
// （价值大于0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向左或
// 者向下移动一格直到到达棋盘的右下角。给定一个棋盘及其上面的礼物，请计
// 算你最多能拿到多少价值的礼物？

// 解法: DP. f[i][j] = max(f[i-1][j], f[i][j-1]) + a[i][j].
// 优化: 使用一维数组. 每次覆盖当前值即可.


#include "utils.h"

class Solution {
public:
	int getMaxValue(vector<vector<int> > &arr) {
		int m = arr.size();
		if (!m) return 0;
		int n = arr[0].size();
		if (!n) return 0;

		vector<int> dp(n, 0);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int prev = j > 0 ? dp[j-1] : 0;
				dp[j] = max(prev, dp[j]) + arr[i][j];
			}
		}

		return dp.back();
	}
};

// ====================测试代码====================
void test(const char* testName, const int* values, int rows, int cols, int expected)
{	
	vector<vector<int> > matrix = Array2Matrix(values, rows, cols);
	Solution s = Solution();
	int res = s.getMaxValue(matrix);
    if(res == expected)
        cout << testName << ": solution1 passed: " << "res=expected=" << res << endl;
    else
        cout << testName << ": solution1 FAILED: " << "res=" << res << ", expected=" << expected << endl;
}

void test1()
{
    // 三行三列
    int values[][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 }
    };
    int expected = 29;
    test("test1", (const int*) values, 3, 3, expected);
}

void test2()
{
    //四行四列
    int values[][4] = {
        { 1, 10, 3, 8 },
        { 12, 2, 9, 6 },
        { 5, 7, 4, 11 },
        { 3, 7, 16, 5 }
    };
    int expected = 53;
    test("test2", (const int*) values, 4, 4, expected);
}

void test3()
{
    // 一行四列
    int values[][4] = {
        { 1, 10, 3, 8 }
    };
    int expected = 22;
    test("test3", (const int*) values, 1, 4, expected);
}

void test4()
{
    int values[4][1] = {
        { 1 },
        { 12 },
        { 5 },
        { 3 }
    };
    int expected = 21;
    test("test4", (const int*) values, 4, 1, expected);
}

void test5()
{
    // 一行一列
    int values[][1] = {
        { 3 }
    };
    int expected = 3;
    test("test5", (const int*) values, 1, 1, expected);
}

void test6()
{
    // 空指针
    int expected = 0;
    test("test6", nullptr, 0, 0, expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}