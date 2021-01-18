/*
使用dfs算法，但是不能从叶节点到跟节点，否则最后一个测试点
会超时，和ROME那道题目不同，这里有多个叶节点需要遍历，会导致
很多路径需要重复遍历，但是根节点只有一个，所以需要从根节点开始
遍历。ROME那道题里面根节点和叶节点都只有一个，区别不大，而从
叶节点开始的话要简单的多，这两种要做区分
*/
#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
#define max 100005
using namespace std;
vector<int> distributor[max];
int maxLevel=0,cnt=0,n;
void dfs(int index,int tmplevel)    //dfs遍历
{
    if(distributor[index].size()==0)    //到达叶节点
    {
        if(tmplevel>maxLevel)   //层级更深，就更新层级和计数
        {
            cnt=1;
            maxLevel=tmplevel;
        }
        else if(tmplevel==maxLevel) //层级同样深就增加计数
        {
            cnt++;
        }
        return;
    }
    for(int i=0;i<distributor[index].size();i++)
    {
        dfs(distributor[index][i],tmplevel+1);
    }
}
int main()
{
    double p,r;
    int root;
    cin>>n>>p>>r;
    for(int i=0;i<n;i++)    //输入需要改变技巧，从给的父节点转为存储子节点
    {
        int tmp;
        scanf("%d",&tmp);
        if(tmp==-1)
            root=i;
        else
            distributor[tmp].push_back(i);
    }
    dfs(root,0);
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<p*double(pow(double(1.0+r/100.0),maxLevel));
    cout<<" "<<cnt<<endl;
    return 0;
}
