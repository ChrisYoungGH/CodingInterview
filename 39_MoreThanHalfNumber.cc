// 面试题39：数组中出现次数超过一半的数字
// 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
// 如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
// 出现了5次，超过数组长度的一半，因此输出2。

#include "utils.h"

// 解法1: 如果一个数出现次数超过一半, 则它是中位数. 使用快排的Patition方法, O(n).
class Solution1 {
public:
	int MoreThanHalfNum(vector<int> &arr) {
		int n = arr.size();
		if (!n) return -1;

		int low = 0, high = n - 1;
		int res = -1;
		while (low <= high) {
			int p = Partition(arr, low, high);
			if (p == n / 2) {
				res = arr[p];
				break;
			}
			if (p > n / 2) high = p - 1;
			else low = p + 1;
		}

		return CheckValid(arr, res) ? res : -1;
	}

	int Partition(vector<int> &arr, int low, int high) {
		int index = RandomChoice(low, high);
		swap(arr[index], arr[high]);
		int pivot = arr[high];
		int i = low - 1;
		for (int j = low; j <= high - 1; j++) {
			if (arr[j] < pivot) {
				i++;
				swap(arr[i], arr[j]);
			}
		}
		i++;
		swap(arr[i], arr[high]);
		return i;
	}

private:
	int RandomChoice(int low, int high) {
		return rand() % (high - low + 1) + low;
	}

	bool CheckValid(vector<int> &arr, int res) {
		int cnt = 0;
		for (int num : arr) {
			if (num == res) cnt++;
			if (cnt > arr.size() / 2) return true;
		}
		return false;
	}
};


// 解法2: 依次计数, 出现相同数+1, 不同数-1. 为0则更新. 超过一半的数为最后设置的数.
class Solution2 {
public:
	int MoreThanHalfNum(vector<int> &arr) {
		int n = arr.size();
		if (!n) return -1;

		int cnt = 1;
		int res = arr[0];
		for (int i = 1; i < n; i++) {
			if (arr[i] == res) cnt++;
			else cnt--;
			if (!cnt) {
				res = arr[i];
				cnt = 1;
			}
		}

		return CheckValid(arr, res) ? res : -1;
	}

private:
	bool CheckValid(vector<int> &arr, int res) {
		int cnt = 0;
		for (int num : arr) {
			if (num == res) cnt++;
			if (cnt > arr.size() / 2) return true;
		}
		return false;
	}
};


// ====================测试代码====================
void Test(string testName, vector<int> &numbers, int length, int expectedValue, bool expectedFlag)
{
    cout << "begins: " << testName << endl;


    vector<int> copy = numbers;
    printf("Test for solution1: ");
    Solution1 s1 = Solution1();
    int result = s1.MoreThanHalfNum(copy);
    if(result == expectedValue)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Test for solution2: ");
    Solution2 s2 = Solution2();
    result = s2.MoreThanHalfNum(numbers);
    if(result == expectedValue)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 存在出现次数超过数组长度一半的数字
void Test1()
{
    vector<int> numbers = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 不存在出现次数超过数组长度一半的数字
void Test2()
{
    vector<int> numbers = {1, 2, 3, 2, 4, 2, 5, 2, 3};
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), -1, true);
}

// 出现次数超过数组长度一半的数字都出现在数组的前半部分
void Test3()
{
    vector<int> numbers = {2, 2, 2, 2, 2, 1, 3, 4, 5};
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 出现次数超过数组长度一半的数字都出现在数组的后半部分
void Test4()
{
    vector<int> numbers = {1, 3, 4, 5, 2, 2, 2, 2, 2};
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 输入空指针
void Test5()
{
   vector<int> numbers = {1};
   Test("Test5", numbers, 1, 1, false);
}

void quicksort(vector<int> &arr, int low, int high) {
	if (low < high) {
		Solution1 s = Solution1();
		int p = s.Partition(arr, low, high);
		quicksort(arr, low, p-1);
		quicksort(arr, p+1, high);
	}
}


int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    vector<int> vec(100);
    for (int i = 0; i < vec.size(); i++) {
    	vec[i] = rand() % 1000;
    }
    quicksort(vec, 0, int(vec.size())-1);

    bool correct = true;
    for (int i = 1; i < vec.size(); i++) {
    	if (vec[i] < vec[i-1]) {
    		correct = false;
    		break;
    	}
    }
    cout << "Sort: " << (correct ? "Pass" : "Failed") << endl;

    return 0;
}
