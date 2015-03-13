/*
 * Say you have an array for which the ith element is the price of a given stock on day i.
 *
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 */

#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int bot = INT_MAX;
        int n = prices.size();
        int max_profit = 0;

        for (int i = 0; i < n; ++i)
        {
            if (prices[i] < bot)
                bot = prices[i];
            else if (prices[i] - bot > max_profit)
                max_profit = prices[i] - bot;
        }
        return max_profit;
    }
};
