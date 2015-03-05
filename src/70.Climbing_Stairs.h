/*
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

class Solution {
public:
    int climbStairs(int n)
    {
        int a = 1, b = 2, c = 0;
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        for (int i = 0; i < n - 2; ++i)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
