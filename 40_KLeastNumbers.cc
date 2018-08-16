// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
// 这8个数字，则最小的4个数字是1、2、3、4。

#include "utils.h"

// 解法1: 快排划分方法, 当划分的数下标为k-1则前k个数就是最小的k个数. O(n)
class Solution1 {
public:
	vector<int> GetLeastNumbers(vector<int> &arr, int k) {
		vector<int> res;

		int n = arr.size();
		if (!n || k <= 0 || n < k) return res;
		if (n == k) return arr;

		int low = 0, high = n - 1;
		while (low <= high) {
			int p = Partition(arr, low, high);
			if (p == k - 1) {
				res.assign(arr.begin(), arr.begin() + k);
				break;
			}
			if (p < k - 1) low = p + 1;
			else high = p - 1;
		}
		return res;
	}

	int Partition(vector<int> &arr, int low, int high) {
		int index = rand() % (high - low + 1) + low;
		swap(arr[index], arr[high]);
		int pivot = arr[high];
		int i = low - 1;
		for (int j = low; j <= high - 1; j++) {
			if (arr[j] < pivot) {
				swap(arr[j], arr[++i]);
			}
		}
		swap(arr[high], arr[++i]);
		return i;
	}
};


// 解法2: 利用一个multiset且内部从大到小排序来维护k个数. 查找/插入/删除为O(logk)
class Solution2 {
public:
	vector<int> GetLeastNumbers(vector<int> &arr, int k) {
		vector<int> res;

		int n = arr.size();
		if (!n || k <= 0 || n < k) return res;
		if (n == k) return arr;

		multiset<int, greater<int> > buffer;
		for (int i = 0; i < n; i++) {
			if (i < k) buffer.insert(arr[i]);
			else {
				if (arr[i] < *(buffer.begin())) {
					buffer.erase(buffer.begin());
					buffer.insert(arr[i]);
				}
			}
		}

		for (int num : buffer) {
			res.push_back(num);
		}

		return res;
	}
};


// 解法3: 维护一个大小为k的最大堆. 查找O(1), 插入/删除O(logk)
class Solution3 {
public:
	vector<int> GetLeastNumbers(vector<int> &arr, int k) {
		vector<int> res;

		int n = arr.size();
		if (!n || k <= 0 || n < k) return res;
		if (n == k) return arr;

		vector<int> buffer(k);
		buffer.assign(arr.begin(), arr.begin() + k);
		make_heap(buffer.begin(), buffer.end(), less<int>());

		for (int i = k; i < n; i++) {
			if (arr[i] < buffer[0]) {
				buffer[0] = arr[i];
				pop_heap(buffer.begin(), buffer.end(), less<int>());
				push_heap(buffer.begin(), buffer.end(), less<int>());
			}
		}

		sort_heap(buffer.begin(), buffer.end(), less<int>());
		for (int num : buffer) {
			res.push_back(num);
		}

		return res;
	}
};


// 解法4: 使用基于最大(小)堆的数据结构优先队列
class Solution4 {
public:
	vector<int> GetLeastNumbers(vector<int> &arr, int k) {
		vector<int> res;

		int n = arr.size();
		if (!n || k <= 0 || n < k) return res;
		if (n == k) return arr;

		priority_queue<int, vector<int>, less<int> > maxHeap;
		for (int i = 0; i < n; i++) {
			if (i < k) {
				maxHeap.push(arr[i]);
			}
			else {
				if (arr[i] < maxHeap.top()) {
					maxHeap.pop();
					maxHeap.push(arr[i]);
				}
			}
		}

		while (!maxHeap.empty()) {
			res.push_back(maxHeap.top());
			maxHeap.pop();
		}

		return res;
	}
};


bool compare(vector<int> arr1, vector<int> arr2) {
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	if (arr1.size() != arr2.size()) return false;
	for (int i = 0; i < arr1.size(); i++) {
		if (arr1[i] != arr2[i]) return false;
	}
	return true;
}

void printVector(vector<int> &arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


// ====================测试代码====================
void Test(string testName, vector<int> &data, int k, vector<int> &expected) {
	cout << "begins: " << testName << endl;

	// Solution 1
	vector<int> data1 = data;
	Solution1 s1 = Solution1();
	vector<int> res1 = s1.GetLeastNumbers(data1, k);
	bool correct1 = compare(res1, expected);
	cout << "Solution1 ";
	if (correct1) cout << "passed." << endl;
	else {
		cout << "FAILED." << endl;
		cout << "result: "; printVector(res1, res1.size());
		cout << "expect: "; printVector(expected, expected.size());
	}

    // Solution 2
	vector<int> data2 = data;
	Solution2 s2 = Solution2();
	vector<int> res2 = s2.GetLeastNumbers(data2, k);
	bool correct2 = compare(res2, expected);
	cout << "Solution2 ";
	if (correct2) cout << "passed." << endl;
	else {
		cout << "FAILED." << endl;
		cout << "result: "; printVector(res2, res2.size());
		cout << "expect: "; printVector(expected, expected.size());
	}

	// Solution 3
	vector<int> data3 = data;
	Solution3 s3 = Solution3();
	vector<int> res3 = s3.GetLeastNumbers(data3, k);
	bool correct3 = compare(res3, expected);
	cout << "Solution3 ";
	if (correct3) cout << "passed." << endl;
	else {
		cout << "FAILED." << endl;
		cout << "result: "; printVector(res3, res3.size());
		cout << "expect: "; printVector(expected, expected.size());
	}

	// Solution 4
	vector<int> data4 = data;
	Solution4 s4 = Solution4();
	vector<int> res4 = s4.GetLeastNumbers(data4, k);
	bool correct4 = compare(res4, expected);
	cout << "Solution4 ";
	if (correct4) cout << "passed." << endl;
	else {
		cout << "FAILED." << endl;
		cout << "result: "; printVector(res4, res4.size());
		cout << "expect: "; printVector(expected, expected.size());
	}

	cout << endl;
}

// k小于数组的长度
void Test1()
{
    vector<int> data = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> expected = {1, 2, 3, 4};
    Test("Test1", data, expected.size(), expected);
}

// k等于数组的长度
void Test2()
{
    vector<int> data = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8};
    Test("Test2", data, expected.size(), expected);
}

// k大于数组的长度
void Test3()
{
    vector<int> data = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> expected;
    Test("Test3", data, expected.size(), expected);
}

// k等于1
void Test4()
{
    vector<int> data = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> expected = {1};
    Test("Test4", data, expected.size(), expected);
}

// k等于0
void Test5()
{
    vector<int> data = {4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> expected;
    Test("Test5", data, expected.size(), expected);
}

// 数组中有相同的数字
void Test6()
{
    vector<int> data = {4, 5, 1, 6, 2, 7, 2, 8};
    vector<int> expected = {1, 2};
    Test("Test6", data, expected.size(), expected);
}

// 输入空指针
void Test7()
{
    vector<int> data;
    vector<int> expected;
    Test("Test6", data, expected.size(), expected);
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

    return 0;
}





// int main() {
// 	vector<int> arr;
// 	srand(time(NULL));
// 	for (int i = 0; i < 10000; i++) {
// 		arr.push_back(rand() % 100000);
// 	}

// 	int k = 10;
// 	vector<int> copy = arr;
// 	sort(copy.begin(), copy.end());
// 	printVector(copy, k);


// 	vector<int> maxHeap(k);
// 	maxHeap.assign(arr.begin(), arr.begin() + k);
// 	make_heap(maxHeap.begin(), maxHeap.end(), less<int>());

// 	for (int i = k; i < arr.size(); i++) {
// 		if (arr[i] < maxHeap[0]) {
// 			maxHeap[0] = arr[i];
// 			pop_heap(maxHeap.begin(), maxHeap.end(), less<int>());
// 			push_heap(maxHeap.begin(), maxHeap.end(), less<int>());
// 		}
// 	}

// 	sort(maxHeap.begin(), maxHeap.end());
// 	printVector(maxHeap, k);
// }