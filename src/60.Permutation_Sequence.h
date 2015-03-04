/*
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * Given n and k, return the kth permutation sequence.
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k)
    {
        string res, s;
        int cur_n = n;
        int cur_k = k;
        int pos = 0;
        int x = 1;
        for (int i = 1; i <= n; ++i)
            x *= i;
        if (k > x)
            return res;
        for (int i = 0; i < n; ++i)
            s.push_back(i + 1 + '0');
        while (!s.empty())
        {
            x = 1;
            for (int i = 1; i < cur_n; ++i)
                x *= i;
            pos = (cur_k - 1) / x;
            cur_k = (cur_k - 1) % x + 1;
            res.push_back(s[pos]);
            s.erase(s.find(s[pos]), 1);
            --cur_n;
        }
        return res;
    }
};
