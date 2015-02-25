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
        int max_j = 0;
        int s = 0;
        for (int i = 1; i < height.size(); ++i)
        {
            if (height[i] == 0)
                continue;
            max_j = i - max_area / height[i];
            for (int j = 0; j < i && j <= max_j; ++j)
            {
                s = (i - j) * (height[i] < height[j] ? height[i] : height[j]);
                max_area = max_area > s ? max_area : s;
            }
        }
        return max_area;
    }
};
