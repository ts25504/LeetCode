/*
 * Implement pow(x, n).
 */

class Solution {
public:
    double pow(double x, int n)
    {
        double res = 1;
        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }
        while (n > 0)
        {
            if (n % 2 == 1)
                res = res * x;
            x *= x;
            n = n / 2;
        }
        return res;
    }
};
