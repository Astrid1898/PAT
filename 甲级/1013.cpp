/*这道题目依然采用深度优先搜索（dsf）算法，简单的遍历就好，记得有n个孤立的部分就需要至少n-1条路径*/

#include<iostream>
#include<cstring>
#define MAX 1001
using namespace std;
int v[MAX][MAX]={0};
int visit[MAX]={0};
void dfs(int node,int n);
int main()
{
    int m,n,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a][b]=v[b][a]=1;
    }
    for(int i=0;i<k;i++)
    {
        int c,cnt=0;
        cin>>c;
        memset(visit,0,sizeof(visit));
        visit[c]=1;
        for(int j=1;j<=n;j++)
        {
            if(!visit[j])
            {
                dfs(j,n);
                cnt++;	//一开始当作一个孤立部分
            }
        }
        cout<<(cnt?cnt-1:cnt)<<endl;	//只有一个点时候要输出0
    }
    return 0;
}
void dfs(int node,int n)
{
    visit[node]=1;
    for(int i=1;i<=n;i++)
    {
        if(!visit[i]&&v[node][i])
        {
            dfs(i,n);
        }
    }
}
