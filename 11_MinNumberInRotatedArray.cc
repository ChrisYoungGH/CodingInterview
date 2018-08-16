// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

// 解法: 与右边比较, 分四种情况. 注意前比后大则最小值一定落在中间.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> &arr) {
        int n = arr.size();
        if (!n) {
            return 0;
        }
        
        int low = 0, high = n - 1;
        while (low < high) {
        	int mid = low + (high - low) / 2;
        	if (arr[mid] < arr[high]) {
        		high = mid;
        	}
        	else if (arr[mid] > arr[high]) {
        		low = mid + 1;
        	}
        	else {
        		if (arr[mid] < arr[low]) {
        			high = mid;
        		}
        		else {
        			high--;
        		}
        	}
        }

        return arr[low];
    }
};


// ====================测试代码====================
void Test(vector<int> &numbers, int expected)
{
    int result = 0;
    try {
    	Solution s = Solution();
        result = s.minNumberInRotateArray(numbers);

        for(int i = 0; i < numbers.size(); ++i)
            printf("%d ", numbers[i]);

        if(result == expected)
            printf("\tpassed\n");
        else
            printf("\tfailed, res=%d, exp=%d\n", result, expected);
    }
    catch (...) {
        if(!numbers.size())
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }
}


int main() {
	vector<int> arr;

	// 典型输入，单调升序的数组的一个旋转
	arr = { 3, 4, 5, 1, 2 };
	Test(arr, 1);

	// 有重复数字，并且重复的数字刚好的最小的数字
	arr = { 3, 4, 5, 1, 1, 2 };
	Test(arr, 1);

	// 有重复数字，但重复的数字不是第一个数字和最后一个数字
	arr = { 3, 4, 5, 1, 2, 2 };
	Test(arr, 1);

	// 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
	arr = { 1, 0, 1, 1, 1 };
	Test(arr, 0);

	// 单调升序数组，旋转0个元素，也就是单调升序数组本身
	arr = { 1, 2, 3, 4, 5 };
	Test(arr, 1);

	// 数组中只有一个数字
	arr = { 2 };
	Test(arr, 2);

	// 输入nullptr
	arr = {};
	Test(arr, 0);

	return 0;
}