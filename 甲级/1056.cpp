/*这道题目的难点有两个：
*
*一、当前失败的排名是小组的个数加一
*
*二、用队列存储比赛次序

*搞明白了这两点题目就很好做了*/


#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int np,ng;
    cin>>np>>ng;
    int weight[np];	//存储贪吃鼠的重量
    int rank[np];	//存储每个人的排名
    for(int i=0;i<np;i++)
    {
        cin>>weight[i];
    }
    queue<int> order;
    for(int i=0;i<np;i++)
    {
        int tmp;
        cin>>tmp;
        order.push(tmp);	//依照比赛序号入队
    }
    int group,tmp=np;
    while(order.size()!=1)	//依次处理直到队伍中仅剩一人
    {
        group=tmp/ng;
        if(tmp-group*ng)
        {
            group++;
        }	//计算需要的组数
        for(int i=0;i<group;i++)
        {
            int max=order.front();
            for(int j=0;j<ng;j++)
            {
                if(i*ng+j>=tmp)	//因为队列是循环的，需要判断当前轮此是否处理完
                {
                    break;
                }
                int fro=order.front();
                if(weight[max]<weight[fro])
                {
                    max=fro;
                }
                rank[fro]=group+1;	//失败的名次，获胜的人会在接下来更新该名次
                order.pop();
            }
            order.push(max);	//获胜的人入队，进行下一轮
        }
        tmp=group;
    }
    rank[order.front()]=1;	//处理第一名
    if(np)
    {
        cout<<rank[0];
    }
    for(int i=1;i<np;i++)
    {
        cout<<" "<<rank[i];
    }
    cout<<endl;
    return 0;
}
