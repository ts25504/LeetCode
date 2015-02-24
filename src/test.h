class Solution {
public:
    int atoi(const char *str) {
        if (!str || !*str) return 0; //空
        
        while (isspace(*str)) str++; //前导空格
        
        int flag = 1; //正负号
        if (*str == '+') str++;
        else if(*str == '-') flag = -1, str++;
        
        int ans = 0;
        for (; isdigit(*str); str++) //非法字符
        {
            int x = *str - '0';
            if (flag == 1 && ans > (INT_MAX - x) / 10)       //正溢出
                return INT_MAX;
            else if(flag == -1 && -ans < (INT_MIN + x) / 10) //负溢出
                return INT_MIN;
            else
                ans = ans * 10 + x;
        }
        
        return flag * ans;
    }
};
