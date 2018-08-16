// 面试题41：数据流中的中位数
// 题目：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么
// 中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
// 那么中位数就是所有数值排序之后中间两个数的平均值。

// 解法: 左半段用最大堆, 右半段用最小堆, 保证左边长度不小于右边且长度差不超过2.

#include "utils.h"

class Solution {
public:
	void Insert(double num) {
		if (left.empty() || num < left.top()) left.push(num);
		else right.push(num);

		if (right.size() > left.size()) {
			left.push(right.top());
			right.pop();
		}
		else if (left.size() - right.size() == 2) {
			right.push(left.top());
			left.pop();
		}
	}

	double GetMedian() {
		if (!left.size()) return -1;
		return left.size() > right.size() ? left.top() : (left.top() + right.top()) / 2.0;
	}

private:
	priority_queue<int, vector<int>, less<int> > left;
	priority_queue<int, vector<int>, greater<int> > right;
};



// ====================测试代码====================
void Test(string testName, Solution& numbers, double expected)
{
	printf("%s begins: ", testName.c_str());

    if(abs(numbers.GetMedian() - expected) < 0.0000001)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
	Solution numbers = Solution();
    Test("Test1", numbers, -1);

    numbers.Insert(5);
    Test("Test2", numbers, 5);

    numbers.Insert(2);
    Test("Test3", numbers, 3.5);

    numbers.Insert(3);
    Test("Test4", numbers, 3);

    numbers.Insert(4);
    Test("Test6", numbers, 3.5);

    numbers.Insert(1);
    Test("Test5", numbers, 3);

    numbers.Insert(6);
    Test("Test7", numbers, 3.5);

    numbers.Insert(7);
    Test("Test8", numbers, 4);

    numbers.Insert(0);
    Test("Test9", numbers, 3.5);

    numbers.Insert(8);
    Test("Test10", numbers, 4);

    return 0;
}