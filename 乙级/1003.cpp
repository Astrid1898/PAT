#include <iostream>
#include <string>
using namespace std;
bool Judge(string s)
{
    bool Pexist = false, Aexist = false, Texist = false; //定义P,A,T存在标志
    for (int i = 0; i < s.length(); i++)
    { //如果存在P,A,T，则标记为真
        if (s[i] == 'P')
            Pexist = true;
        else if (s[i] == 'A')
            Aexist = true;
        else if (s[i] == 'T')
            Texist = true;
        else //如果有不为P,A,T的字符则返回假
            return false;
    }
    if (Pexist && Aexist && Texist) //如果字符串都只由P,A,T组成
    {
        int posP, posT; //定义第1个P和最后1个T的位置
        for (int i = 0; i < s.length(); i++)
            if (s[i] == 'P')
            {
                posP = i;
                break;
            }
        for (int i = s.length() - 1; i >= 0; i--)
            if (s[i] == 'T')
            {
                posT = i;
                break;
            } //找到第1个P和最后1个T的位置
        for (int i = posP + 1; i < posT; i++)
            if (s[i] != 'A')  //检验两者之间是否只有字符A
                return false; //若出现不是A的字符，则返回假
        //现在，字符串只由P,A,T构成且只有一个P和一个T，P和T之间只有A
        int cntAbfP = posP;                  //统计P之前A的个数
        int cntAbtPT = posT - posP - 1;      //统计PT之间A的个数
        int cntAbhT = s.length() - 1 - posT; //统计T之后A的个数
        if (cntAbfP * cntAbtPT == cntAbhT)
            return true; //如果P之前A的个数*PT之间A的个数 =T之后A的个数 则符合要求，返回真
        return false;
    }
    return false; //如果字符串只由P,A,T中的一个或两个字符组成，返回假
}
int main()
{
    int n;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (Judge(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}