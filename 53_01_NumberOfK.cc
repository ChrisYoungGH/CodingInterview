// 面试题53（一）：数字在排序数组中出现的次数
// 题目：统计一个数字在排序数组中出现的次数。例如输入排序数组{1, 2, 3, 3,
// 3, 3, 4, 5}和数字3，由于3在这个数组中出现了4次，因此输出4。

// 解法: 相等时再比较前一个或后一个数确定是否退出.

#include "utils.h" 

class Solution {
public:
	int GetNumberOfK(vector<int> &arr, int k) {
		int low = lower_bound(arr, k);
		int high = upper_bound(arr, k);
		return high - low + 1;
	}

	int lower_bound(vector<int> &arr, int k) {
		int n = arr.size();
		if (!n) return -1;
		int low = 0, high = n-1;
		while (low < high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] > k) high = mid - 1;
			else if (arr[mid] < k) low = mid + 1;
			else {
				if (mid == 0 || arr[mid-1] != k) {
					return mid;
				}
				else high = mid - 1;
			}
		}

		return arr[low] == k ? low : -1;
	}

	int upper_bound(vector<int> &arr, int k) {
		int n = arr.size();
		if (!n) return -2;
		int low = 0, high = n - 1;
		while (low < high) {
			int mid = low + (high - low) / 2;
			if (arr[mid] > k) high = mid - 1;
			else if (arr[mid] < k) low = mid + 1;
			else {
				if (mid == n-1 || arr[mid+1] != k) {
					return mid;
				}
				else low = mid + 1;
			}
		}
		return arr[low] == k ? low : -2;
	}
};

// ====================测试代码====================
void Test(string testName, int data[], int length, int k, int expected)
{
	vector<int> arr = Array2Vector(data, length);
    printf("%s begins: ", testName.c_str());

    Solution s = Solution();
    int result = s.GetNumberOfK(arr, k);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed: res=%d, expected=%d\n", result, expected);
}

// 查找的数字出现在数组的中间
void Test1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的开头
void Test2()
{
    int data[] = {3, 3, 3, 3, 4, 5};
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的结尾
void Test3()
{
    int data[] = {1, 2, 3, 3, 3, 3};
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数字不存在
void Test4()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// 查找的数字比第一个数字还小，不存在
void Test5()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// 查找的数字比最后一个数字还大，不存在
void Test6()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// 数组中的数字从头到尾都是查找的数字
void Test7()
{
    int data[] = {3, 3, 3, 3};
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
void Test8()
{
    int data[] = {3, 3, 3, 3};
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// 数组中只有一个数字，是查找的数字
void Test9()
{
    int data[] = {3};
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// 数组中只有一个数字，不是查找的数字
void Test10()
{
    int data[] = {3};
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// 鲁棒性测试，数组空指针
void Test11()
{
    Test("Test11", nullptr, 0, 0, 0);
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
    Test9();
    Test10();
    Test11();

    return 0;
}