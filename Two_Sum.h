/*
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

#ifndef Two_Sum_h
#define Two_Sum_h

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> ret;
        multimap<int, int> m;
        for (int i = 0; i < numbers.size(); ++i)
            m.insert(make_pair(numbers[i], i+1));
        sort(numbers.begin(), numbers.end());
        int left = 0, right = numbers.size() - 1;
        int sum = 0;
        while (left < right)
        {
            sum = numbers[left] + numbers[right];
            if (sum == target)
            {
                int min_iter1 = numbers.size();
                int max_iter1 = 0;
                int min_iter2 = numbers.size();
                int max_iter2 = 0;
                for (auto iter = m.lower_bound(numbers[left]);
                        iter != m.upper_bound(numbers[left]);
                        ++iter)
                {
                    if (iter->second < min_iter1)
                        min_iter1 = iter->second;
                    if (iter->second > max_iter1)
                        max_iter1 = iter->second;
                }
                for (auto iter = m.lower_bound(numbers[right]);
                        iter != m.upper_bound(numbers[right]);
                        ++iter)
                {
                    if (iter->second < min_iter2)
                        min_iter2 = iter->second;
                    if (iter->second > max_iter2)
                        max_iter2 = iter->second;
                }
                ret.push_back(min_iter1 < min_iter2 ? min_iter1 : min_iter2);
                ret.push_back(max_iter1 > max_iter2 ? max_iter1 : max_iter2);
                break;
            }
            else
            {
                sum < target ? ++left : --right;
            }
        }
        return ret;
    }
};

#endif

