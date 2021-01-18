/*
求最大连续因子，只能一个个去试了
*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int first=0,len=0,max=sqrt(n)+1;    //最大到sqrt(n)+1
    for(int i=2;i<=max;i++) //从2开始求连续
    {
        int j;
        int tmp=1;
        for(j=i;j<=max;j++) //连续乘积
        {
            tmp*=j;
            if(n%tmp!=0)    //不能被整数，连乘结束
                break;
        }
        if(len<j-i)
        {
            len=j-i;
            first=i;
        }
    }
    if(first==0)    //没有找到
        cout<<1<<endl<<n<<endl;
    else
    {
        cout<<len<<endl<<first;
        for(int i=1;i<len;i++)
        {
            cout<<"*"<<first+i;
        }
        cout<<endl;
    }
    return 0;
}
