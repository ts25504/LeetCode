/*
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container.
 */

#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int max_area = 0;
        int s = 0;
        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            s = (right - left) *
                (height[left] < height[right] ? height[left] : height[right]);
            max_area = max_area > s ? max_area : s;
            if (height[left] < height[right])
                ++left;
            else
                --right;
        }
        return max_area;
    }
};
