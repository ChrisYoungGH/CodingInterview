// 删除第一个字符串中在第二个字符串出现的字符.

#include "utils.h"

class Solution {
public:
	void DeleteCharFromSecondString(string &s1, string &s2) {
		int n1 = s1.length(), n2 = s2.length();
		if (!n1 || !n2) return;

		char ch[256] = {0};
		for (char c : s2) {
			ch[c] = 1;
		}

		int pos = 0;
		for (int i = 0; i < n1; i++) { 
			if (!ch[s1[i]]) s1[pos++] = s1[i];
		}
		s1.erase(s1.begin() + pos, s1.end());
	}
};


int main() {
	string s1 = "We are students.";
	string s2 = "aeiou";
	Solution s = Solution();
	s.DeleteCharFromSecondString(s1, s2);
	cout << s1 << endl;
	return 0;
}