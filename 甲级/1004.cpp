/*今天两道题目对我来说都很难，花费了很多时间，已经很晚了，先仓促写一些*/
/*又是一道DFS的题目，我一开始竟然没有看出来，其实就是求一个树每个结点所在层级，再统计每个层级上的叶节点*/
#include<iostream>
#include<vector>
#define MAX_N 101
using namespace std;
vector<int> tree[MAX_N];	//用于存储每个节点及其字节点的信息
int levelcnt[MAX_N]={0},maxlevel=0;	//levelcnt用于统计每一层级的叶节点数目，maxlevel用于统计最大层级，用于输出时候的控制
void dfs(int index,int level)
{
    if(tree[index].size()==0)	//叶节点
    {
        if(level>maxlevel)
            maxlevel=level;		//若当前层级超过maxlevel，更新maxlevel
        levelcnt[level]++;
        return;
    }
    for(int i=0;i<tree[index].size();i++)
    {
        dfs(tree[index][i],level+1);	//递归统计
    }
}
int main()
{
    int n,m,id,k,tmp;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>id>>k;
        for(int j=0;j<k;j++)
        {
            cin>>tmp;
            tree[id].push_back(tmp);
        }
    }
    dfs(1,0);
    cout<<levelcnt[0];
    for(int i=1;i<=maxlevel;i++)
    {
        cout<<' '<<levelcnt[i];
    }
    cout<<endl;
    return 0;
}



