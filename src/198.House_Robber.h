#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& num)
    {
        if (num.empty())
            return 0;
        int len = num.size();
        vector<int> money(len, 0);
        money[0] = num[0];
        money[1] = max(num[0], num[1]);
        for (int i = 2; i < len; ++i)
            money[i] = max(money[i-2] + num[i], money[i-1]);
        return money[len-1];
    }
}:
