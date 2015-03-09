/*
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 */

class Solution {
public:
    int numTrees(int n)
    {
        vector<int> cnt;
        cnt.push_back(1);
        for (int i = 1; i <= n; ++i)
        {
            cnt.push_back(0);
            for (int j = 1; j <= i; ++j)
                cnt[i] += cnt[j-1] * cnt[i-j];
        }
        return cnt[n];
    }
};
