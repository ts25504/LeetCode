/*
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 * Note:
 * You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 */

class Solution {
public:
    void merge(int A[], int m, int B[], int n)
    {
        int mm = m - 1, nn = n - 1;
        int tail = mm + nn + 1;
        while (mm >= 0 && nn >= 0)
        {
            if (A[mm] > B[nn])
                A[tail--] = A[mm--];
            else
                A[tail--] = B[nn--];
        }
        while (mm >= 0)
            A[tail--] = A[mm--];
        while (nn >= 0)
            A[tail--] = B[nn--];
    }
};
