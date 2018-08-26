#include "utils.h"

class Solution {
public:
	bool isAnagram(string s1, string s2) {
		int ch[256] = {0};
		for (char c : s1) ch[c]++;
		for (char c : s2) {
			if (!ch[c]) return false;
			ch[c]--;
		}
		return true;
	}
};

int main() {
	string s1 = "listen", s2 = "silent";
	Solution s = Solution();
	cout << s.isAnagram(s1, s2) << endl;
	return 0;
}