/*如此简单的题目，以至于不敢相信，没想到一遍AC*/
#include<iostream>
using namespace std;
int main()
{
    int n,temp,ans=0,pre=0;
    cin>>n;
    while(n--)
    {
        cin>>temp;
        if(temp>pre)
            ans+=(temp-pre)*6+5;
        else
            ans+=(pre-temp)*4+5;
        pre=temp;
    }
    cout<<ans;
}
