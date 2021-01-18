/*
看到有人说这一题神奇的排列组合，这是真神奇
在A处，左边的P个数乘右边的T个数即是这个A带来的PAT数
竟然能有线性时间复杂度的算法，也真是奇怪，然而若是增加几个，
比如求PATT的又该如何？
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int n=str.size();
    int t=0,p=0;
    for(int i=0;i<n;i++)    //先求出t的总个数
    {
        if(str[i]=='T')
            t++;
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='P')
            p++;    //左边P的个数
        else if(str[i]=='T')
            t--;    //右边T的个数
        else if(str[i]=='A')
            ans=ans+p*t;
    }
    cout<<ans%1000000007<<endl;
    return 0;
}
