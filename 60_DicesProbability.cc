// 面试题60：n个骰子的点数
// 题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s
// 的所有可能的值出现的概率。

// 解法: 掷第n个骰子时出现点数为s的次数为掷完前n-1个骰子出现点数s-j (j=1,...,6)的次数之和.
// 使用两个数组来保存这一轮和下一轮的情况. 掷n个骰子最小点数为n, 最大点数为6n.
// 每次小于n的部分置0, 修改n~6n的部分.

#include "utils.h"

class Solution
{
public:
	vector<pair<int, double> > DicesProbability(int nDices) {
		vector<pair<int, double> > res;
		if (nDices <= 0) return res;

		vector<vector<int> > prob(2, vector<int>(maxNum * nDices + 1, 0));
		fill(prob[0].begin()+1, prob[0].begin()+maxNum+1, 1);
		int flag = 0;

		for (int k = 2; k <= nDices; k++) {
			for (int i = 0; i < k; i++) {
				prob[1-flag][i] = 0;
			}
			for (int i = k; i <= maxNum * k; i++) {
				prob[1-flag][i] = 0;
				for (int j = 1; j <= min(i, maxNum); j++) {
					prob[1-flag][i] += prob[flag][i-j];
				}
			}
			flag = 1 - flag;
		}

		int total = pow(maxNum, nDices);
		for (int i = nDices; i <= maxNum * nDices; i++) {
			res.emplace_back(i, 1.0 * prob[flag][i] / total);
		}

		return res;
	}

private:
	int maxNum = 6;
};

class Check {
public:
	vector<pair<int, double> > PrintProbability(int number)
	{
		vector<pair<int, double> > res;
	    if(number < 1)
	        return res;
	 
	    int maxSum = number * g_maxValue;
	    int* pProbabilities = new int[maxSum - number + 1];
	    for(int i = number; i <= maxSum; ++i)
	        pProbabilities[i - number] = 0;
	 
	    Probability(number, pProbabilities);
	 
	    int total = pow((double)g_maxValue, number);
	    for(int i = number; i <= maxSum; ++i)
	    {
	        double ratio = (double)pProbabilities[i - number] / total;
	        res.emplace_back(i, ratio);
	    }
	 
	    delete[] pProbabilities;
	    return res;
	}
	 
	void Probability(int number, int* pProbabilities)
	{
	    for(int i = 1; i <= g_maxValue; ++i)
	        Probability(number, number, i, pProbabilities);
	}
	 
	void Probability(int original, int current, int sum, 
	                 int* pProbabilities)
	{
	    if(current == 1)
	    {
	        pProbabilities[sum - original]++;
	    }
	    else
	    {
	        for(int i = 1; i <= g_maxValue; ++i)
	        {
	            Probability(original, current - 1, i + sum, pProbabilities);
	        }
	    }
	} 
private:
	int g_maxValue = 6;	
};

void Test(int n) {
	vector<pair<int, double> > res = Solution().DicesProbability(n);
	vector<pair<int, double> > expected = Check().PrintProbability(n);
	bool status = true;
	if (res.size() != expected.size()) {
		status = false;
	}
	else {
		double err = 0;
		for (int i = 0; i < res.size(); i++) {
			if (res[i].first != expected[i].first) {
				err = INT_MAX;
				break;
			}
			err += fabs(res[i].second - expected[i].second);
		}
		status = err < 1e-6;
	}

	cout << "Test" << n << ":" << (status ? "passed." : "FAILED.") << endl;
}

int main(int argc, char* argv[])
{
    Test(1);
    Test(2);
    Test(3);
    Test(4);
    
    Test(11);

    Test(0);

    return 0;
}