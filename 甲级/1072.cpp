/*
找最短路径的题目，不过后面增加了排序，一开始使用DFS算法，结果第四个测试点会超时，
大概是因为递归的速度要慢，改为dijstra算法后就通过了
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
static const int MAX=1<<30;
int dis[1020][1020],visited[1020]={0},minDis[1020];
int n,m,k,ds;
void dijstra(int s)     //dijstra算法找出s点出发到各点的最短路径
{
    minDis[s]=0;
    for(int i=1;i<=m+n;i++)
    {
        int tmp=MAX,u=-1;
        for(int v=1;v<=m+n;v++)
        {
            if(visited[v]==0&&minDis[v]<tmp)
            {
                tmp=minDis[v];u=v;
            }
        }
        if(u==-1)
            return;
        visited[u]=1;
        for(int j=1;j<=m+n;j++)
        {
            if(visited[j]==0&&dis[u][j]!=MAX)
            {
                if(minDis[j]>minDis[u]+dis[u][j])
                {
                    minDis[j]=minDis[u]+dis[u][j];
                }
            }
        }
    }
}
int main()
{
    cin>>n>>m>>k>>ds;
    fill(dis[0],dis[0]+1020*1020,MAX);
    fill(minDis,minDis+1020,MAX);
    for(int i=0;i<k;i++)
    {
        string aTmp,bTmp;
        int distance,a,b;
        cin>>aTmp>>bTmp>>distance;
        if(aTmp[0]=='G')
            a=(stoi(aTmp.substr(1)))+n; //这里需要注意atmp长度不一定都是2，m可能很大
        else
            a=stoi(aTmp);
        if(bTmp[0]=='G')
            b=(stoi(bTmp.substr(1)))+n;
        else
            b=stoi(bTmp);
        dis[a][b]=dis[b][a]=distance;
    }
    int minSum=MAX;
    int ansLocation=-1,ansMin=0;
    float ansAve=float(MAX);
    for(int i=n+1;i<=n+m;i++)
    {
        dijstra(i);     //对每个站点执行dijstra
        int sum=0,sign=0,minD=MAX;
        for(int j=1;j<=n;j++)
        {
            if(minDis[j]>ds)
            {
                sign=1;     //用sign做标记以便直接跳过不合格的站点
                break;
            }
            else
            {
                sum+=minDis[j];
            }
            if(minDis[j]<minD)
            {
                minD=minDis[j];
            }
        }
        fill(minDis,minDis+1020,MAX);
        fill(visited,visited+1020,0);
        if(sign==0)
        {
            if(ansMin<minD)     //找出最短距离最大的恶站点
            {
                ansLocation=i;
                ansMin=minD;
                ansAve=float(sum)/float(n);
            }
            else if(ansMin==minD)
            {
                if(ansAve>(float(sum)/float(n)))    //若相等，就找出平均距离小的
                {
                    ansLocation=i;
                    ansMin=minD;
                    ansAve=float(sum)/float(n);
                }
            }
        }
    }
    if(ansLocation==-1)
    {
        cout<<"No Solution"<<endl;
        return 0;
    }
    cout<<"G"<<char(ansLocation-n+'0')<<endl;

    /*奇怪的是这里用例子中的结果是2.0,3.3，将ansAve加0.05后反而不正确*/
    printf("%.1f %.1f\n",float(ansMin),ansAve);     
    return 0;
}
