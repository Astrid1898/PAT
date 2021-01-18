/*这个问题看似和前面那个医疗救护一样，实际上还是有点区别的
*这里涉及两个问题，找出最短的路径集合以及从这些路径中找出需要自行车最少或
*带回最少的路径，所以并不能只用一次Dijkstra算法或者DFS算法搞定，所以参考
*网上的算法使用了一次Dijkstra算法找出最短路径集合，再用一次DFS算法找出所要
*使用的路径，这里Dijkstra算法并没有使用优先队列，有进一步优化的空间，实际上考虑问题很可能是个稀疏的赋权无向图，简单易点的和话使用两次DFS算法可能更好
*/


#include<iostream>
#include<vector>
#include<algorithm>
#define INF 9e7
using namespace std;
int capacity;
int station[510],dis[510],road[510][510];
int visit[510]={0};
int minNeed=INF,minBack=INF;
vector<int> pre[510],tempPath,Path;
void dijkstra(int n);
void dfs(int v);
int main()
{
    fill(road[0],road[0]+510*510,INF);
    fill(dis,dis+510,INF);
    int n,sp,m;
    cin>>capacity>>n>>sp>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>station[i];
        station[i]=station[i]-(capacity/2);	//这里为了方便可以以和半满的的距离作为权重    
	}
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        road[x][y]=road[y][x]=z;
    }
    dijkstra(n);
    dfs(sp);
    cout<<minNeed<<' ';
    for(int i=Path.size()-1;i>0;i--)
    {
        cout<<Path[i]<<"->";
    }
    cout<<Path[0]<<' '<<minBack;
    return 0;
}
void dijkstra(int n)	//找出所有顶点的最短路径，还有很大优化空间
{
    dis[0]=0;
    for(int i=0;i<=n;i++)
    {
        int u=-1,min=INF;
        for(int j=0;j<=n;j++)
        {
            if(!visit[j]&&dis[j]<min)
            {
                u=j;
                min=dis[j];
            }
        }
        if(u==-1)break;
        visit[u]=1;
        for(int v=0;v<=n;v++)
        {
            if(!visit[v]&&road[u][v]!=INF)
            {
                if(dis[v]>dis[u]+road[u][v])
                {
                    dis[v]=dis[u]+road[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(dis[v]==dis[u]+road[u][v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
void dfs(int v)	//依次找出最适合的路径
{
    tempPath.push_back(v);
    if(v==0)
    {
        int need=0,back=0;
        for(int i=tempPath.size()-1;i>=0;i--)
        {
            int id=tempPath[i];
            if(station[id]>0)
            {
                back+=station[id];            
            }
            else
            {
                if(back>abs(station[id]))
                {
                    back+=station[id];
                }
                else
                {
                    need+=(abs(station[id])-back);
                    back=0;
                }
            }
        }
        if(need<minNeed)
        {
            minNeed=need;
            minBack=back;
            Path=tempPath;
        }
        else if(need==minNeed&&back<minBack)
        {
            minBack=back;
            Path=tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for(int i=0;i<pre[v].size();i++)
    {
        dfs(pre[v][i]);
    }
    tempPath.pop_back();
}
