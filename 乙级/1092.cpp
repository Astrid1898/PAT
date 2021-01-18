#include<iostream>
using namespace std;
int main()
{
    int n,m,max=0,temp;
    cin>>n>>m;
    int mooncakes[n+1]={0};
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>temp;
            mooncakes[j]+=temp;
            if(mooncakes[j]>temp)
                temp=mooncakes[j];
        }
    }
    cout<<temp<<endl;
    int sign=1;
    for(int i=1;i<=n;i++)
    {
        if(mooncakes[i]==temp&&sign)
        {
            cout<<i;
            sign=0;
        }
        else if(mooncakes[i]==temp&&!sign)
        {
            cout<<' '<<i;
        }
    }
    return 0;
}
