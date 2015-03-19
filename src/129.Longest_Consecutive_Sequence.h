/*
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 *
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 *
 * Your algorithm should run in O(n) complexity.
 */

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& num)
    {
        map<int, int> m;
        int res = 1;
        int cur_length = 1;
        for (int i = 0; i < num.size(); ++i)
            m[num[i]] = 1;
        map<int, int>::iterator iter;
        int last_num = m.begin()->first;
        for (iter = m.begin(); iter != m.end(); ++iter)
        {
            int cur_num = iter->first;
            if (cur_num == last_num)
                continue;
            else if (cur_num == last_num + 1)
            {
                ++cur_length;
                res = max(res, cur_length);
                last_num = cur_num;
            }
            else
            {
                cur_length = 1;
                last_num = cur_num;
            }
        }
        return res;
    }
};
