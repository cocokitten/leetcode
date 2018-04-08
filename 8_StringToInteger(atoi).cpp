#include <iostream>
#include <string>
using namespace std;

/*需考虑如下问题：
1、开头的空格
2、正负符号的处理
3、溢出处理
4、非法输入,比如"+-2",返回0;      //应该返回0*/

class Solution
{

  public:
    int myAtoi(string str)
    { 
        long result = 0;
        int i = 0, sign = 1;

        //过滤开头空格!
        while (str[i] == ' ')
            i++;

        //正负号问题
        if (str[i] == '-' || str[i] == '+')
        {
            sign = 1 - 2 * (str[i] == '-');
            i++;
        }

        //溢出判断、非法字符过滤
        while (str[i] >= '0' && str[i] <= '9')
        {

            result = result * 10 + (str[i] - '0');

            if (result * sign >= INT_MAX)
            {
                result = INT_MAX;
                break;
            }
            if (result * sign <= INT_MIN)
            {
                result = INT_MIN;
                break;
            }
            i++;
        }
        return sign * result;
    }
};