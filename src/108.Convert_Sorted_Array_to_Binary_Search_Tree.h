/*
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 */

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& num)
    {
        if (num.empty())
            return NULL;
        return build(num, 0, num.size() - 1);
    }

    TreeNode* build(vector<int>& num, int left, int right)
    {
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(num[mid]);

        if (right == left)
            return node;

        if (left <= mid - 1)
            node->left = build(num, left, mid - 1);
        if (mid + 1 <= right)
            node->right = build(num, mid + 1, right);
        return node;
    }
};
