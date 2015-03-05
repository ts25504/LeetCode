/*
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 */

#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        string dir, res;
        vector<int> slash_pos;
        int i = 0;
        for (int i = 0; i < path.length(); ++i)
            if (path[i] == '/')
                slash_pos.push_back(i);
        for (i = 1; i < slash_pos.size(); ++i)
        {
            dir = path.substr(slash_pos[i-1], slash_pos[i] - slash_pos[i-1]);
            if (dir == "/..")
            {
                if (st.empty())
                    continue;
                else
                    st.pop();
            }
            else if (dir == "/." || dir == "/")
                continue;
            else
                st.push(dir);
        }
        dir = path.substr(slash_pos[i-1], path.length() - slash_pos[i-1]);
        if (dir == "/..")
        {
            if (!st.empty())
                st.pop();
        }
        else if (dir != "/." && dir != "/")
            st.push(dir);
        while (!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        if (res.empty())
            res += "/";
        return res;
    }
};
