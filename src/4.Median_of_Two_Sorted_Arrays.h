/*
 * There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */

#ifndef Median_of_Two_Sorted_Arrays
#define Median_of_Two_Sorted_Arrays

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        if (m == 0)
        {
            if ((n - 1) % 2 == 0)
                return static_cast<double>(B[(n-1)/2]);
            else
                return static_cast<double>(B[(n-1)/2]+B[(n-1)/2+1]) / 2;
        }

        if (n == 0)
        {
            if ((m - 1) % 2 == 0)
                return static_cast<double>(A[(m-1)/2]);
            else
                return static_cast<double>(A[(m-1)/2]+A[(m-1)/2+1]) / 2;
        }

        if (m == 1)
        {
            if (n == 1)
                return static_cast<double>(A[0]+B[0]) / 2;
            if ((n - 1) % 2 == 0)
            {
                if (A[0] > B[(n-1)/2])
                {
                    if (A[0] > B[(n-1)/2+1])
                        return static_cast<double>(B[(n-1)/2]+B[(n-1)/2+1]) / 2;
                    else
                        return static_cast<double>(B[(n-1)/2]+A[0]) / 2;
                }
                else if (A[0] < B[(n-1)/2])
                {
                    if (A[0] < B[(n-1)/2-1])
                        return static_cast<double>(B[(n-1)/2]+B[(n-1)/2-1]) / 2;
                    else
                        return static_cast<double>(B[(n-1)/2]+A[0]) / 2;
                }
                else
                    return static_cast<double>(A[0]);
            }
            else
            {
                if (A[0] > B[(n-1)/2+1])
                    return static_cast<double>(B[(n-1)/2+1]);
                else if (A[0] < B[(n-1)/2])
                    return static_cast<double>(B[(n-1)/2]);
                else
                    return A[0];
            }
        }

        if (n == 1)
        {
            if (m == 1)
                return static_cast<double>(A[0]+B[0]) / 2;
            if ((m - 1) % 2 == 0)
            {
                if (B[0] > A[(m-1)/2])
                {
                    if (B[0] > A[(m-1)/2+1])
                        return static_cast<double>(A[(m-1)/2]+A[(m-1)/2+1]) / 2;
                    else
                        return static_cast<double>(A[(m-1)/2]+B[0]) / 2;
                }
                else if (B[0] < A[(m-1)/2])
                {
                    if (B[0] < A[(m-1)/2-1])
                        return static_cast<double>(A[(m-1)/2]+A[(m-1)/2-1]) / 2;
                    else
                        return static_cast<double>(A[(m-1)/2]+B[0]) / 2;
                }
                else
                    return static_cast<double>(B[0]);
            }
            else
            {
                if (B[0] > A[(m-1)/2+1])
                    return static_cast<double>(A[(m-1)/2+1]);
                else if (B[0] < A[(m-1)/2])
                    return static_cast<double>(A[(m-1)/2]);
                else
                    return B[0];
            }
        }

        if (A[m-1] <= B[0])
        {
            if (m > n)
            {
                if ((m + n - 1) % 2 == 0)
                    return static_cast<double>(A[(m+n-1)/2]);
                else
                    return static_cast<double>
                        ((A[(m+n-1)/2] + A[(m+n-1)/2+1])) / 2;
            }
            else if (m < n)
            {
                if ((m + n - 1) % 2 == 0)
                    return static_cast<double>(B[(m+n-1)/2-m]);
                else
                    return static_cast<double>
                        (B[(m+n-1)/2-m] + B[(m+n-1)/2-m+1]) / 2;
            }
            else
                return static_cast<double>(A[m-1] + B[0]) / 2;
        }

        if (A[0] >= B[n-1])
        {
            if (m < n)
            {
                if ((m + n - 1) % 2 == 0)
                    return static_cast<double>(B[(m+n-1)/2]);
                else
                    return static_cast<double>
                        ((B[(m+n-1)/2] + B[(m+n-1)/2+1])) / 2;
            }
            else if (m > n)
            {
                if ((m + n - 1) % 2 == 0)
                    return static_cast<double>(A[(m+n-1)/2-n]);
                else
                    return static_cast<double>
                        (A[(m+n-1)/2-n] + A[(m+n-1)/2-n+1]) / 2;
            }
            else
                return static_cast<double>(A[0] + B[n-1]) / 2;
        }

        int mid_a = 0, mid_b = 0;
        int left_a = 0, left_b = 0;
        int right_a = m-1, right_b = n-1;
        while (true)
        {
            mid_a = (left_a + right_a) >> 1;
            mid_b = (left_b + right_b) >> 1;
            /*
            std::cout << "left_a: " << left_a << " right_a: " << right_a
                      << " mid_a: " << mid_a<< std::endl;
            std::cout << "left_b: " << left_b << " right_b: " << right_b
                      << " mid_b: " << mid_b<< std::endl;
            */
            if (left_a == right_a - 1)
            {
                if ((left_b + right_b) % 2 == 0 && right_b - 1 != left_b)
                {
                    if (A[left_a] > B[mid_b])
                        if (A[left_a] < B[mid_b+1])
                            return static_cast<double>(A[left_a]);
                        else
                            return static_cast<double>(B[mid_b+1]);
                    else if (A[right_a] < B[mid_b])
                        if (A[right_a] > B[mid_b-1])
                            return static_cast<double>(A[right_a]);
                        else
                            return static_cast<double>(B[mid_b-1]);
                    else
                        return static_cast<double>(B[mid_b]);
                }
                else
                {
                    if (A[left_a] >= B[mid_b+1])
                        if (A[left_a] > B[mid_b+2])
                            return static_cast<double>(B[mid_b+1]+B[mid_b+2]) / 2;
                        else
                            return static_cast<double>(A[left_a]+B[mid_b+1]) / 2;
                    else if (A[left_a] <= B[mid_b])
                    {
                        if (A[right_a] > B[mid_b+1] || A[right_a] < B[mid_b-1])
                            return static_cast<double>(B[mid_b]+B[mid_b-1]) / 2;
                        else
                            return static_cast<double>(B[mid_b]+A[right_a]) / 2;
                    }
                    else if (A[left_a] > B[mid_b] && A[left_a] < B[mid_b+1])
                    {
                        if (A[right_a] > B[mid_b+1])
                            return static_cast<double>(A[left_a]+B[mid_b+1]) / 2;
                        else
                            return static_cast<double>(A[left_a]+A[right_a]) / 2;
                    }
                }
            }

            if (left_b == right_b - 1)
            {
                if ((left_a + right_a) % 2 == 0 && right_a - 1 != left_a)
                {
                    if (B[left_b] > A[mid_a])
                        if (B[right_b] < A[mid_a+1])
                            return static_cast<double>(B[left_b]);
                        else
                            return static_cast<double>(A[mid_a+1]);
                    else if (B[right_b] < A[mid_a])
                        if (B[right_b] > A[mid_a-1])
                            return static_cast<double>(B[right_b]);
                        else
                            return static_cast<double>(A[mid_a-1]);
                    else
                        return static_cast<double>(A[mid_a]);
                }
                else
                {
                    if (B[left_b] >= A[mid_a+1])
                        if (B[left_b] > A[mid_a+2])
                            return static_cast<double>(A[mid_a+1]+A[mid_a+2]);
                        else
                            return static_cast<double>(B[left_b]+A[mid_a+1]) / 2;
                    else if (B[left_b] <= A[mid_a])
                    {
                        if (B[right_b] > A[mid_a+1] || B[right_b] < A[mid_a-1])
                            return static_cast<double>(A[mid_a]+A[mid_a-1]) / 2;
                        else
                            return static_cast<double>(A[mid_a]+B[right_b]) / 2;
                    }
                    else if (B[left_b] > A[mid_a] && B[left_b] < A[mid_a+1])
                    {
                        if (B[right_b] > A[mid_a+1])
                            return static_cast<double>(B[left_b]+A[mid_a+1]) / 2;
                        else
                            return static_cast<double>(B[left_b]+B[right_b]) / 2;
                    }
                }
            }

            if (A[mid_a] < B[mid_b])
            {
                if (mid_a - left_a < mid_b - left_b)
                {
                    right_b = right_b - mid_a + left_a;
                    left_a = mid_a;
                }
                else
                {
                    right_b = right_b - mid_b + left_b;
                    left_a = left_a + mid_b - left_b;
                }
            }
            else if (A[mid_a] > B[mid_b])
            {
                if (mid_a - left_a < mid_b - left_b)
                {
                    right_a = right_a - mid_a + left_a;
                    left_b = left_b + mid_a - left_a;
                }
                else
                {
                    right_a = right_a - mid_b + left_b;
                    left_b = mid_b;
                }
            }
            else
            {
                if ((left_b + right_b) % 2 != 0 && (left_a + right_a) % 2 != 0)
                    return static_cast<double>(A[mid_a]+A[mid_a+1]) / 2;
                return static_cast<double>(A[mid_a]);
            }
        }
    }
};

#endif
