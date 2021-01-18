/*不用过于复杂，只要一个记录1到i的的距离的数组即可*/

#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    int dis[n+1]={0};
    for(int i=1;i<=n;i++)
    {
        cin>>dis[i];
        dis[i]+=dis[i-1]; //dis[i]记录0到i+1的距离的和
    }
    cin>>m;
    while(m--)
    {
        int s,d;
        cin>>s>>d;
        cout<<min(abs(dis[d-1]-dis[s-1]),dis[n]-abs(dis[d-1]-dis[s-1]))<<endl;
    }
    return 0;
}
