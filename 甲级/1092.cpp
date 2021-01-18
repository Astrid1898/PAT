/*
用map轻松解决，需要注意的是map中的count函数是参数出现的次数
*/
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    string owner,eva;
    map<char,int> mp;
    bool sign=false;    //缺少珠子的标志
    int extra=0,miss=0;     //extra是多余的珠子数，miss是缺少的珠子数
    cin>>owner>>eva;
    for(int i=0;i<owner.size();i++)
    {
        mp[owner[i]]++; //先将商店的珠子散列
    }
    for(int i=0;i<eva.size();i++)
    {
        if(mp[eva[i]]==0)   //该珠子缺少，不能购买，并计数缺少数目
        {
            sign=true;
            miss++;
        }
        else
        {
            mp[eva[i]]--;   //珠子存在，先去掉
        }
    }
    if(sign)
    {
        cout<<"No"<<" "<<miss<<endl;
    }
    else
    {
        auto itr=mp.begin();
        for(;itr!=mp.end();itr++)  //剩下珠子就是剩余的
        {
            extra+=itr->second;
        }
        cout<<"Yes"<<" "<<extra<<endl;
    }
    return 0;
}
