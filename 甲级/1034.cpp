/*作为一道30分的题目，难度还是对得起其分数的，我一开始看得毫无头绪。
*上一题虽然也难，但还不至于到完全没有思路，但这道自己想了很久甚至连
*采用什么数据结构什么算法都不知道
*读题目的时候还以为是Gang是每两个成员的关系都大于K，这样这道题目就
*相当地棘手,后来才知道Gand是有联系的成员关系总和大于K，这样这道题就
*转化成了看一个无向图里面有几个连通的部分了，需要注意的是名字用map就
*好了*/


#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
string head;
int cnt,total;
map<string,int>weight;	//记录关系权重
map<string,bool>visit;	//记录是否访问过
map<string,vector<string>> adjlist;	//使用邻接表保存图
map<string,int> res;	//记录每个Gang的头目和人数
void dfs(string start)	//dfs算法遍历每个连通的部分，计算关系和
{
    visit[start]=1;
    cnt++;
    total+=weight[start];
    if(weight[start]>weight[head])
    {
        head=start;	//若该点的权重比head大，就更新head;
    }
    for(vector<string>::iterator it=adjlist[start].begin();it!=adjlist[start].end();it++)	//遍历
    {
        if(!visit[*it])
        {
            dfs(*it);
        }
    }
}
int main()
{
    int n,k,t; 
    cin>>n>>k;
    string name1,name2;
    for(int i=0;i<n;i++)
    {
        cin>>name1>>name2>>t;
        weight[name1]+=t;
        weight[name2]+=t;
        adjlist[name1].push_back(name2);	
        adjlist[name2].push_back(name1);
        visit[name1]=0;
        visit[name2]=0;
    }
    for(auto it=visit.begin();it!=visit.end();it++)	//遍历图的连通部分
    {
        if(it->second==0)
        {
            total=0;
            cnt=0;
            head=it->first;
            dfs(it->first);	//从一个未被访问过的点开始遍历
        }
        if(cnt>2&&total/2>k)
        {
            res[head]=cnt;	//人数大于2,关系大于k，就是一个Gang;
        }
    }
    cout<<res.size()<<endl;
    for(auto itr=res.begin();itr!=res.end();itr++)
    {
        cout<<itr->first<<" "<<itr->second<<endl;
    }
    return 0;
}
