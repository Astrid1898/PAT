/*搬入新居所的第一天，心情并不是那么好，这道题目也是用到了尚未掌握的DFS算法，用了好久才看懂*/
/*DFS的方法虽然可行，但并不是一个高效的算法，类似的还有Dijkstra算法*/
#include<iostream>
using namespace std;
const int  maxn=500; 
const int INF=1e9;
/*关键变量*/
int edge[maxn][maxn]={0}; //边的长度
int v[maxn]={0};	//记录点是否被访问过
int men[maxn]={0};	//记录各点救援人数
int s,d;	//s出发，到d去
int n,e;	//n顶点数，e边数
int shortest_length=INF;	//最短路径长度
int shortest_num=0;		//最短路径个数
int max_man=0;	//最多救援人数
void DFS(int cur,int cur_length,int cur_men)
// cur为当前路径的终点，cur_length为从上一点到达cur的路径长，cur_men为cur处救援人数
{
    if(cur_length>shortest_length)return;	//路径过长，直接剪去
    if(cur==d)	//到达终点
    {
        if(cur_length<shortest_length)	//当前路径更短
        {
            shortest_length=cur_length;	//设置新的最短路径
            shortest_num=1;	//设置最短路径数目为1;
            max_man=cur_men;	//更新救援人员
        }
        else if(cur_length==shortest_length)	//长度相等
        {
            shortest_num++;	//路径数目增加
            if(cur_men>max_man)
            {
                max_man=cur_men;	//若有必要，更新最大救援人数
            }
        }
        return;
    }
	/*从cur出发，访问所有可能路径*/
    v[cur]=1;//设置点已经访问过
    for(int i=0;i<n;i++)
    {
        if(v[i]==1||edge[cur][i]==0)
        {
            continue;
        }
        DFS(i,cur_length+edge[cur][i],cur_men+men[i]);
    }
    v[cur]=0; //这里很重要，使得从其他节点出发时，cur可以被访问
} 
int main()
{
    cin>>n>>e>>s>>d;
	/*记录每个城市的救援人员*/
    for(int i=0;i<n;i++)
        cin>>men[i];
	/*记录每两个城市之间的路径长度*/
    for(int i=0;i<e;i++)
    {
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        edge[t1][t2]=edge[t2][t1]=t3;
    }
	/*从起点出发，开始遍历*/
    DFS(s,0,men[s]);
    cout<<shortest_num<<' '<<max_man<<endl;
    return 0;
}
