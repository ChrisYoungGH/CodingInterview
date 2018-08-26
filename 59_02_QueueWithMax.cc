// 面试题59（二）：队列的最大值
// 题目：定义一个队列, 实现获取队列最大值的函数max, 要求max, push_back, pop_back都为O(1)操作.

// 解法: 两个deque, 一个存数据(下标和值), 一个存最大值, 每次将先前的小的数弹出. pop_front时检查两个
// deque队头是否是同个下标的元素, 是的话才删除maximum队头.

#include "utils.h"

class QueueWithMax {
public:
	QueueWithMax() : currIndex(0) {}

	void push_back(int num) {
		while (!maximum.empty() && maximum.back().num <= num) {
			maximum.pop_back();
		}
		InternalData internalData = {num, currIndex};
		data.push_back(internalData);
		maximum.push_back(internalData);
		currIndex++;
	}

	void pop_front() {
		if (maximum.empty()) return;
		if (maximum.front().index == data.front().index) {
			maximum.pop_front();
		}
		data.pop_front();
	}

	int max() const {
		if (maximum.empty()) return -1;
		return maximum.front().num;
	}

private:
	struct InternalData {
		int num;
		int index;
	};

	deque<InternalData> data;
	deque<InternalData> maximum;
	int currIndex;
};



// ====================测试代码====================
void Test(string testName, const QueueWithMax& queue, int expected)
{
    printf("%s begins: ", testName.c_str());

    if(queue.max() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    QueueWithMax queue;
    // {2}
    queue.push_back(2);
    Test("Test1", queue, 2);

    // {2, 3}
    queue.push_back(3);
    Test("Test2", queue, 3);

    // {2, 3, 4}
    queue.push_back(4);
    Test("Test3", queue, 4);

    // {2, 3, 4, 2}
    queue.push_back(2);
    Test("Test4", queue, 4);

    // {3, 4, 2}
    queue.pop_front();
    Test("Test5", queue, 4);

    // {4, 2}
    queue.pop_front();
    Test("Test6", queue, 4);

    // {2}
    queue.pop_front();
    Test("Test7", queue, 2);

    // {2, 6}
    queue.push_back(6);
    Test("Test8", queue, 6);

    // {2, 6, 2}
    queue.push_back(2);
    Test("Test9", queue, 6);

    // {2, 6, 2, 5}
    queue.push_back(5);
    Test("Test9", queue, 6);

    // {6, 2, 5}
    queue.pop_front();
    Test("Test10", queue, 6);

    // {2, 5}
    queue.pop_front();
    Test("Test11", queue, 5);

    // {5}
    queue.pop_front();
    Test("Test12", queue, 5);

    // {5, 1}
    queue.push_back(1);
    Test("Test13", queue, 5);

    return 0;
}