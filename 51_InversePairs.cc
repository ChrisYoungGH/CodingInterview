// 面试题51：数组中的逆序对
// 题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组
// 成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

// 解法: 归并排序, 从后往前排, 同时根据左右两段数组计算交叉的逆序对. 初始化时copy=data保证任意一个都允许到最后一层.

#include "utils.h"

class Solution {
public:
	int InversePairs(vector<int> &data) {
		int n = data.size();
		if (!n) return 0;

		vector<int> copy = data;
		return InversePairsCount(data, copy, 0, n-1);
	}

	int InversePairsCount(vector<int> &data, vector<int> &copy, int low, int high) {
		if (low == high) {
			copy[low] = data[low];
			return 0;
		}

		int mid = low + (high - low) / 2;
		int left = InversePairsCount(copy, data, low, mid);
		int right = InversePairsCount(copy, data, mid+1, high);

		int inter = 0;
		int i = mid, j = high, k = high;
		while (i >= low && j >= mid+1) {
			if (copy[i] > copy[j]) {
				data[k--] = copy[i--];
				inter += j - mid;
			}
			else {
				data[k--] = copy[j--];
			}
		}
		while (i >= low) data[k--] = copy[i--];
		while (j >= mid+1) data[k--] = copy[j--];

		return left + right + inter;
	}
};

// ====================测试代码====================
void Test(string testName, int* data, int length, int expected)
{
    printf("%s begins: ", testName.c_str());
    Solution s = Solution();
    vector<int> arr = Array2Vector(data, length);
    int res = s.InversePairs(arr);
    if(res == expected)
        printf("Passed.\n");
    else
        printf("Failed: res=%d, expected=%d\n", res, expected);
}

void Test1()
{
    int data[] = { 1, 2, 3, 4, 7, 6, 5 };
    int expected = 3;

    Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// 递减排序数组
void Test2()
{
    int data[] = { 6, 5, 4, 3, 2, 1 };
    int expected = 15;

    Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3()
{
    int data[] = { 1, 2, 3, 4, 5, 6 };
    int expected = 0;

    Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4()
{
    int data[] = { 1 };
    int expected = 0;

    Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// 数组中只有两个数字，递增排序
void Test5()
{
    int data[] = { 1, 2 };
    int expected = 0;

    Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6()
{
    int data[] = { 2, 1 };
    int expected = 1;

    Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7()
{
    int data[] = { 1, 2, 1, 2, 1 };
    int expected = 3;

    Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
    int expected = 0;

    Test("Test8", nullptr, 0, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();

    return 0;
}
