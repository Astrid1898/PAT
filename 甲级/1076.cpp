/*
一开始理解错了题意，用了一种类似于DFS的算法进行，对于测试用例是可以，但是并不能
全部通过测试点，去找了一下别人写的才知道对间接转发层数的理解出了问题，用BFS的算法就
顺利AC
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n,l;
struct node //存储用户信息
{
    int id;
    int layer;
};
vector<vector<int>> user;   //用户
int bfs(node);
int main()
{
    cin>>n>>l;
    user.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        for(int j=0;j<m;j++)
        {
            int tmp;
            cin>>tmp;
            user[tmp].push_back(i); //读数据这里用了些手段，把follow改成了followed变成了followed
        }
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int toQuery;
        cin>>toQuery;
        node tNode={toQuery,0}; //每次将要查询的作为第一层运用BFS算法
        cout<<bfs(tNode)<<endl;
    }
    return 0;
}
int bfs(node tnode)
{
    bool visit[1010]={false};   //记录是否被访问过
    queue<node> q;
    q.push(tnode);
    visit[tnode.id]=true;
    int cnt=0;
    while(!q.empty())
    {
        node top=q.front();
        q.pop();
        int topid=top.id;
        for(int i=0;i<user[topid].size();i++)
        {
            int nextid=user[topid][i];  //下一个要被查看的id
            if(visit[nextid]==false&&top.layer<l)   //使用top判断，可以加快速度，但是要<l;
            {
                node next={nextid,top.layer+1}; //层级要加一
                q.push(next);
                visit[nextid]=true;
                cnt++;
            }
        }
    }
    return cnt;
}
