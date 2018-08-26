#include "utils.h"

class Solution {
public:
	void DeleteDuplicates(string &s) {
		int ch[256] = {0};
		int pos = 0;
		for (int i = 0; i < s.length(); i++) {
			if (!ch[s[i]]) {
				s[pos++] = s[i];
				ch[s[i]] = 1;
			}
		}
		s.erase(s.begin() + pos, s.end());
	}
};

int main() {
	Solution s = Solution();
	string str = "google";
	s.DeleteDuplicates(str);
	cout << str << endl;
	return 0;
}