

#include "utils.h"

class Solution {
public:
	void Serialize(TreeNode *head, ofstream &out) {
		if (!head) {
			out << "#,";
			return;
		}
		out << head->val << ",";
		Serialize(head->left, out);
		Serialize(head->right, out);
	}

	TreeNode* Deserialize(istream &in) {
		TreeNode *node = nullptr;
		int val;
		if (ReadStream(in, &val)) {
			node = new TreeNode(val);
			node->left = Deserialize(in);
			node->right = Deserialize(in);
		}
		return node;
	}

private:
	bool ReadStream(istream& stream, int* number) {
	    if(stream.eof())
	        return false;

	    char buffer[32];
	    buffer[0] = '\0';

	    char ch;
	    stream >> ch;
	    int i = 0;
	    while(!stream.eof() && ch != ',')
	    {
	        buffer[i++] = ch;
	        stream >> ch;
	    }

	    bool isNumeric = false;
	    if(i > 0 && buffer[0] != '$')
	    {
	        *number = atoi(buffer);
	        isNumeric = true;
	    }

	    return isNumeric;
	}
};