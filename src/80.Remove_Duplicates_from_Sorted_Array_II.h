/*
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array A = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, and A is now [1,1,2,2,3].
 */

class Solution {
public:
    int removeDuplicates(int A[], int n)
    {
        if (n < 3)
            return n;
        int i = 1, cur = 1, cnt = 1;
        while (i < n)
        {
            if (A[i] != A[i-1])
            {
                A[cur++] = A[i];
                cnt = 1;
            }
            else if (A[i] == A[i-1] && cnt < 2)
            {
                A[cur++] = A[i];
                ++cnt;
            }
            ++i;
        }
        return cur;
    }
};
