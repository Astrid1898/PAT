/*
和今年考试的题目有点相似，给一行字符串分成子串处理，若是当初提前做了这道题目或许
就不至于那么悲惨了
*/
#include<iostream>
#include<string>
#include<map>
using namespace std;
bool isAlphaNumerical(char& c)  //判断是否是alphanumberical
{
    if(c>='0'&&c<='9')
        return true;
    if(c>='A'&&c<='Z')
        return true;
    if(c>='a'&&c<='z')
        return true;
    return false;
}
int main()
{
    int max=0;
    string str,tmp,maxStr;
    getline(cin,str);
    map<string,int> mp; //记录单词出现的次数
    for(int i=0;i<str.size();i++)
    {
        str[i]=tolower(str[i]);
        if(isAlphaNumerical(str[i]))
        {
            tmp.push_back(str[i]);
        }
        else
        {
            if(!tmp.empty())    //一定要检测非空，不然有连续两个非alphanumeric时就会会出现错误
            {
                mp[tmp]++;
                tmp.clear();
            }
            continue;
        }
    }
    if(!tmp.empty())
    {
        mp[tmp]++;
    }
    auto itr=mp.begin();
    for(;itr!=mp.end();itr++)
    {
        if((itr->second)>max)
        {
            maxStr=itr->first;
            max=itr->second;
        }
    }
    cout<<maxStr<<" "<<max<<endl;
    return 0;
}
