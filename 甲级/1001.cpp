/*其实一开始的想法是重载int基本类型的输出，但是编译不通过，猜测可能<<符号不能直接用int型变量做参数*/
/*这个方法实际上是一个比较麻烦的方法，只是想尝试一下重载运算符，因为是先从左边的数字开始输出，但是逗号却是以右边数字开始计数的，造成了很多问题*/
#include <iostream>
using namespace std;
ostream &operator<<(ostream &output, string &s)
{
    if (s[0] == '-')
    {
        output << '-';
        s.erase(0, 1);
    }
    int sign = 1; //用于控制前几为不满3时的输出
    while (true)
    {
        int s_len = s.size();
        if (s.size() < 4)
        {
            output << s.substr(0, s.size()) << endl;
            return output;
        }
        else
        {
            if (sign)
            {
                output << s.substr(0, s.size() % 3);
                if (s.size() % 3 != 0)
                    output << ',';
                s.erase(0, s.size() % 3);
                sign = 0;
            }
            else
            {
                output << s.substr(0, 3) << ',';
                s.erase(0, 3);
            }
        }
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    string s = to_string(a + b);
    cout << s;
    return 0;
}
