/*
这种题目至今已经见了很多次，就是用dijstra和dfs去做，
今后要进一步熟练这两种算法
*/
#include<iostream>
#include<vector>
#include<map>
#include<string>
#define MAX 205
#define INF 99999999
using namespace std;
map<string,int> mp; //建立城市与数字的映射，方便处理
map<int,string> mp1;    //与mp对应，将数字映射到城市
vector<int> happiness,temppath,path;
vector<vector<int>> pre(MAX); //记录路径上每一座城市的前一座城市
int road[MAX][MAX];
int visited[MAX]={0};
int dis[MAX];   //dijstra算法中各点到起点的最短路径
double maxavg;
int maxvalue=0,cntpath=0;
void dfs(int v)  //dfs算法从最低花费路径中选择合适路径
{
    temppath.push_back(v);  //从pre中取出一条路径
    if(v==0)
    {
        int value=0;
        for(int i=0;i<temppath.size();i++)
        {
            value+=happiness[temppath[i]]; //记录下本条路径幸福度之和
        }
        double tempavg=double(value)/double(temppath.size()-1);
        if(value>maxvalue)
        {
            maxvalue=value;
            maxavg=tempavg;
            path=temppath;  //选择幸福度高的
        }
        else if(value==maxvalue&&tempavg>maxavg)    //幸福度相同选择平均值高的
        {
            maxavg=tempavg;
            path=temppath;
        }
        temppath.pop_back();    //将目的地弹出，因为容器后面还要被别的路径用到
        cntpath++;
        return;
    }
    for(int i=0;i<pre[v].size();i++)
    {
        dfs(pre[v][i]);
    }
    temppath.pop_back();    //将中间城市依次弹出，因为容器后面还要被别的路径用到
}
int main()
{
    fill(road[0],road[0]+MAX*MAX,INF);
    fill(dis,dis+MAX,INF);
    int n,k;
    string starCity;
    map<string,int> mp;
    cin>>n>>k>>starCity;
    mp[starCity]=0; //设置出发点为0号
    mp1[0]=starCity;
    happiness.resize(n);
    for(int i=1;i<n;i++)
    {
        string tmp;
        cin>>tmp;
        mp[tmp]=i;
        mp1[i]=tmp;
        cin>>happiness[i];
    }
    for(int i=0;i<k;i++)
    {
        string tmp1,tmp2;
        cin>>tmp1>>tmp2;
        cin>>road[mp[tmp1]][mp[tmp2]];
        road[mp[tmp2]][mp[tmp1]]=road[mp[tmp1]][mp[tmp2]];
    }
    dis[0]=0;   //将出发点到出发点的距离设定为0;
    for(int i=0;i<n;i++)
    {
        int u=-1,min=INF;
        for(int j=0;j<n;j++)    //取出距离最短的点
        {
            if(visited[j]==0&&dis[j]<min)
            {
                u=j;
                min=dis[j];
            }
        }
        if(u==-1) break;
        visited[u]=1;
        for(int v=0;v<n;v++)    //依次更新未被选中的点的dis
        {
            if(visited[v]==0&&road[u][v]!=INF)
            {
                if(dis[u]+road[u][v]<dis[v])    //若有新的短路经就更新
                {
                    dis[v]=dis[u]+road[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(dis[u]+road[u][v]==dis[v])  //相等则追加
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
    int destiontion=mp["ROM"];
    dfs(destiontion);   //求幸福度
    cout<<cntpath<<" "<<dis[destiontion]<<" "<<maxvalue<<" "<<int(maxavg)<<endl;
    for(int i=path.size()-1;i>0;i--)
    {
        cout<<mp1[path[i]]<<"->";
    }
    cout<<mp1[path[0]]<<endl;
    return 0;
}
