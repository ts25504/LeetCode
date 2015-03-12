/*
 * Given numRows, generate the first numRows of Pascal's triangle.
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> > res;
        for (int i = 0; i < numRows; ++i)
        {
            vector<int> ans = {1};
            if (i == 0)
            {
                res.push_back(ans);
            }
            else if (i == 1)
            {
                ans.push_back(1);
                res.push_back(ans);
            }
            else
            {
                for (int j = 1; j < res[i-1].size(); ++j)
                    ans.push_back(res[i-1][j] + res[i-1][j-1]);
                ans.push_back(1);
                res.push_back(ans);
            }
        }
        return res;
    }
};
