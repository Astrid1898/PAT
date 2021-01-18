/*这道题又是不懂，但是看了网上的做法真是恍然大悟，
*想到了cmp函数的写法，就没啥难度了*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
bool cmp(const string &a,const string &b)
{
    return a+b<b+a;	//这个cmp函数是难点，用了贪心的思路，让任意两个都符合题意
}
int main()
{
    int n;
    string smallsetNum;
    cin>>n;
    vector<string> *str=new vector<string>(n);
    for(int i=0;i<n;i++)
    {
        cin>>(*str)[i];
    }
    sort((*str).begin(),(*str).end(),cmp);
    for(int i=0;i<(*str).size();i++)
    {
        smallsetNum+=(*str)[i];
    }
    delete str;
    auto itr=smallsetNum.begin();
    for(;itr!=smallsetNum.end();itr++)
    {
        if(*itr!='0')
        {
            break;
        }
    }
    if(itr==smallsetNum.end())
    {
        cout<<0<<endl;
        return 0;
    }
    for(;itr!=smallsetNum.end();itr++)
    {
        cout<<*itr;
    }
    cout<<endl;
    return 0;
}
