/*
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 */

#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int>& cost)
    {
        int start_pos = 0;
        int total_cost = 0;
        int minimum = INT_MAX;
        for (int i = 0; i < gas.size(); ++i)
        {
            total_cost += gas[i] - cost[i];
            if (total_cost < minimum)
            {
                minimum = total_cost;
                start_pos = i;
            }
        }
        if (total_cost >= 0)
            return (start_pos + 1) % gas.size();
        else
            return -1;
    }
};
