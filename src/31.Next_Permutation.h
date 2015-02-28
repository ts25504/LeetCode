/*
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

// next_permutation(num.begin(), num.end());

#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& num)
    {
        int i = num.size() - 1;
        while (i > 0)
        {
            if (num[i-1] < num[i])
                break;
            --i;
        }

        if (i == 0)
        {
            reverse(num.begin(), num.end());
            return;
        }

        int j = num.size() - 1;
        while (j >= i)
        {
            if (num[j] > num[i-1])
            {
                swap(num[j], num[i-1]);
                break;
            }
            --j;
        }
        sort(num.begin() + i, num.end());
    }
};
