/*
 * Implement pow(x, n).
 */

class Solution {
public:
    double pow(double x, int n)
    {
        if (n < 0)
        {
            x = 1 / x;
            n = -n;
        }
        return pow_cal(x, n);
    }
    double pow_cal(double x, int n)
    {
        if (n == 0)
            return 1;
        double res = pow_cal(x, n / 2);
        res = res * res;
        if (n % 2 == 1)
            res *= x;
        return res;
    }
};
