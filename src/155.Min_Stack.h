/*
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 */

#include <stack>
#include <limits.h>

using namespace std;

class MinStack {
public:
    stack<int> min_stack;
    stack<int> data_stack;
    void push(int x)
    {
        if (min_stack.empty())
        {
            min_stack.push(x);
            data_stack.push(x);
            return;
        }
        data_stack.push(x);
        if (min_stack.top() >= x)
            min_stack.push(x);
    }
    void pop()
    {
        if (!min_stack.empty())
        {
            if (data_stack.top() == min_stack.top())
                min_stack.pop();
            data_stack.pop();
        }
    }
    int top()
    {
        return data_stack.top();
    }
    int getMin()
    {
        return min_stack.top();
    }
};
