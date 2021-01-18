/*正数可以唯一分解为素数的乘积
*建立素数表从小到大相除*/
#include<iostream>
using namespace std;
typedef long int ll;
const int maxn=1e4;
int prime[maxn]={0};
int main()
{
    int i,j;
    for(i=2;i*i<maxn;i++)
    {
        if(prime[i]==1) continue;
        for(j=2;j*i<maxn;j++)
        {
            prime[i*j]=1;
        }
    }
    ll num;
    cin>>num;
    cout<<num<<"=";
    if(num==1)
    {
        cout<<1<<endl;
        return 0;
    }
    bool state=false;
    for(int i=2;num>=2;i++)
    {
        int cnt=0,flag=0;
        while(prime[i]==0&&num%i==0)
        {
            cnt++;
            flag=1;
            num/=i;
        }
        if(flag)
        {
            if(state)
            {
                cout<<"*";

            }
            cout<<i;
            state=true;
        }
        if(cnt>=2)
        {
            cout<<"^"<<cnt;
        }
    }
    cout<<endl;
    return 0;
}
