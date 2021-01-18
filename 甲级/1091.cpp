/*
一开始没有想到该怎么做，以下代码来自https://blog.csdn.net/liuchuo/article/details/52267317?utm_source=blogxgwz0
本来想用map结构去存储每个区域，结果那样弄得很复杂，没想到用bfs轻易解决了，
这么一个求体积的问题巧妙地和bfs联系了起来，也是神奇
*/

#include<iostream>
#include<queue>
using namespace std;
struct node //存储坐标
{
    int x,y,z;
};
int m,n,l,t;
int arr[1300][130][65];
bool visit[1300][130][65];
bool judge(int x,int y,int z)   //判断点是可取
{
    if(x<0||x>=m||y<0||y>=n||z<0||z>=l) return false;   //超出边界不可取
    if(arr[x][y][z]==0||visit[x][y][z]==true) return false; //已被计算过或值为0不可取
    return true;
}
int X[6]={1,0,0,-1,0,0};
int Y[6]={0,1,0,0,-1,0};
int Z[6]={0,0,1,0,0,-1};
int bfs(int x,int y,int z)
{
        int cnt=0;
        node temp;
        temp.x=x,temp.y=y,temp.z=z;
        queue<node> q;
        q.push(temp);
        visit[x][y][z]=true;
        while(!q.empty())   //从一个点开始，遍历所有临接需要计算的点
        {
            node top=q.front();
            q.pop();
            cnt++;
            for(int i=0;i<6;i++)    //计算top的邻接
            {
                int tx=top.x+X[i];
                int ty=top.y+Y[i];
                int tz=top.z+Z[i];
                if(judge(tx,ty,tz))
                {
                    visit[tx][ty][tz]=true;
                    temp.x=tx,temp.y=ty,temp.z=tz;
                    q.push(temp);
                }
            }
        }
        if(cnt>=t)
        {
            return cnt;
        }
        else
            return 0;
}
int main()
{
    cin>>m>>n>>l>>t;
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                cin>>arr[j][k][i];
            }
        }
    }
    int ans=0;
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(arr[j][k][i]==1&&visit[j][k][i]==false)
                    ans+=bfs(j,k,i);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
