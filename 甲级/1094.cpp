/*
这道题目也做过，又是BFS
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> child;  //后代信息
vector<int> levels; //每层人数信息
struct node //存储每个人信息
{
    int id;
    int level;
};
void bfs(int id,int level)  //bfs遍历，算出每层人数存储在levels数组中
{
    node tnode={id,level};
    queue<node> q;
    q.push(tnode);
    while(!q.empty())
    {
        node top=q.front();
        q.pop();
        levels[top.level]++;
        int nextid=top.id;
        for(int i=0;i<child[nextid].size();i++)
        {
            node nextNode={child[nextid][i],top.level+1};
            q.push(nextNode);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    child.resize(n+1);
    levels.resize(n+1);
    for(int i=0;i<=n;i++)
    {
        levels[i]=0;

    }
    for(int i=0;i<m;i++)
    {
        int id,k;
        cin>>id>>k;
        for(int j=0;j<k;j++)
        {
            int childId;
            cin>>childId;
            child[id].push_back(childId);
        }
    }
    bfs(1,1);
    int corresLevel=0,population=0;
    for(int i=1;i<=n;i++)   //找出人数最多的代及其人数
    {
        if(levels[i]>population)
        {
            corresLevel=i;
            population=levels[i];
        }
    }
    cout<<population<<" "<<corresLevel<<endl;
    return 0;
}
