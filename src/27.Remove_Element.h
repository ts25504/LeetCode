/*
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

class Solution {
public:
    int removeElement(int A[], int n, int elem)
    {
        if (n == 0)
            return 0;
        int last_pos = n;
        int i = 0;
        while (i < last_pos)
        {
            if (A[i] == elem)
                A[i] = A[--last_pos];
            else
                ++i;
        }
        return last_pos;
    }
};
