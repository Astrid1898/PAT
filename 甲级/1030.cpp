#include<iostream>
/*这道题目和那个公共自行车管理是一样的，不过那个是点权这个是边权罢了，相比较这个
*甚至要更简单*/

#include<vector>
#define MAX 500
#define INF 1e7
using namespace std;
int highWays[MAX][MAX];	//临接矩阵记录高速公路信息
int length[MAX];	//记录到某地的最短路程
vector<vector<int>> pre(MAX);	//记录最短路程路径中的上一个地点
int visited[MAX]={0};	//记录有没有被访问过
int costs[MAX][MAX]={0},minCost=INF; //costs记录两点费用，mincost记录最少费用
vector<int> tmppath,path;
void dijkstra(int s,int n) //Dijatra记录路径最短的路
{
    length[s]=0;
    for(int i=0;i<n;i++)
    {
        int u=-1,min=INF;
        for(int j=0;j<n;j++)
        {
            if(!visited[j]&&length[j]<min)
            {
                u=j;
                min=length[j];
            }
        }
        if(u==-1)
            break;
        visited[u]=1;
        for(int v=0;v<n;v++)
        {
            if(!visited[v]&&highWays[u][v]!=INF)
            {
                if(length[v]>length[u]+highWays[u][v])
                {
                    length[v]=length[u]+highWays[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(length[v]==length[u]+highWays[u][v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
void dfs(int v,int d) //从最短路径中选出费用最少路径
{
    tmppath.push_back(v);
    if(v==d)
    {
        int thiscost=0;
        for(int i=0;i<tmppath.size()-1;i++)
        {
            thiscost=thiscost+costs[tmppath[i]][tmppath[i+1]];
        }
        if(minCost>thiscost)
        {
            minCost=thiscost;
            path=tmppath;
        }
        tmppath.pop_back();
        return;
    }
    for(int i=0;i<pre[v].size();i++)
    {
        dfs(pre[v][i],d);
    }
    tmppath.pop_back();
    return;
}
int main()
{
    fill(length,length+MAX,INF);
    fill(highWays[0],highWays[0]+MAX*MAX,INF);
    int n,m,s,d;
    cin>>n>>m>>s>>d;
    while(m--)
    {
        int city1,city2,distance,cost;
        cin>>city1>>city2>>distance>>cost;
        highWays[city1][city2]=highWays[city2][city1]=distance;
        costs[city1][city2]=costs[city2][city1]=cost;
    }
    dijkstra(s,n);
    dfs(d,s);
    for(int i=path.size()-1;i>=0;i--)
    {
        cout<<path[i]<<' ';
    }
    cout<<length[d]<<" "<<minCost<<endl;
    return 0;
}


