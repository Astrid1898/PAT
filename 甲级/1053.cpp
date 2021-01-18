/*DSF每条路径遍历就好了，算是30分的题目中比较简单的一类吧*/

#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 101
using namespace std;
vector<vector<int>> path(MAX);	//记录等于指定值的路径
vector<vector<int>> link(MAX);	//记录连接情况
vector<int> weight;	//记录权重
vector<int> tmpPath;	//记录每次遍历时的路径
int cnt=0;	//路径计数
void dfs(int s,int cur,int curtWeight)
{
    tmpPath.push_back(cur);
    if(curtWeight>s)
    {
		tmpPath.pop_back();	//若当前权重和已经大于指定值，直接返回
        return;
    }
    if(link[cur].size()==0)
    {
        if(curtWeight==s)
        {
            path[cnt++]=tmpPath;	//符合条件的路径，记录进path
        }
        tmpPath.pop_back();
        return;
    }
    for(int i=0;i<link[cur].size();i++)
    {
        int news=link[cur][i];
        dfs(s,news,curtWeight+weight[news]);	//递归遍历
    }
    tmpPath.pop_back();
}
bool cmp(const int &a,const int &b)
{
    return weight[a]>weight[b];	//先将每一层的点按权重排序
}
int main()
{    
    int n,s,m;
    cin>>n>>m>>s;
    weight.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    while(m--)
    {
        int id,k;
        cin>>id>>k;
        link[id].resize(k);
        for(int i=0;i<k;i++)
        {
            int tmp;
            cin>>tmp;
            {
                link[id][i]=tmp;
            }
        }
        sort(link[id].begin(),link[id].end(),cmp);	//排序
    }
    dfs(s,0,weight[0]);	//dsf找出所有符合的路径，此时已经是按题意排序好的了
    path.resize(cnt);
    for(int i=0;i<path.size();i++)
    {
        cout<<weight[path[i][0]];
        for(int j=1;j<path[i].size();j++)
        {
            cout<<" "<<weight[path[i][j]];
        }
        cout<<endl;
    }
    return 0;
}
