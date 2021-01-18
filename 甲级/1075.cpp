/*
这道题目最后一个测试点有很多坑，但我偏偏踩了一个网上都没有介绍的坑，找了好久。
这个坑是排序方式带来的，代码中注释有详细介绍
*/
#include<iostream>
#include<iomanip>
#include<algorithm>
#define maxk 6
using namespace std;
struct examinee //定义examinee以存储每位考生信息
{
    examinee()  //构造函数初始化scores数组，其实可以直接在类里初始化的
    {
        for(int i=0;i<maxk;i++)
        {
            scores[i]=-2;   //全部初始化为-2,为了和编译未通过的-1区分开来
        }
    }
    int userId=-1;
    int totalScore=0;
    int scores[maxk];
    int perfectNum=0;   //记录AC题目数
    int flag=0; //标志该考生是否计入ranklist
};
bool cmp(const examinee &a,const examinee &b)   //依题意的cmp函数
{
    return a.totalScore!=b.totalScore?a.totalScore>b.totalScore:(a.perfectNum!=b.perfectNum?a.perfectNum>b.perfectNum:a.userId<b.userId);
}
int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    int fullMark[k+1];  //记录各道题目满分
    for(int i=1;i<=k;i++)
    {
        cin>>fullMark[i];
    }
    examinee exam[n+1]; //考生
    while(m--)
    {
        int tmp;
        cin>>tmp;   //考生ID
        exam[tmp].userId=tmp;   //因为排序后exam顺序会被打乱，所以需要记录ID
        int numid,s;    //numid记录题号，s记录分数
        cin>>numid>>s;
        if(s==-1)   //分数为-1,即编译未通过，按照题意算0分
        {
            s=0;
        }
        else    //只要有一道题目编译通过，该考生就要计入ranklist
        {
            exam[tmp].flag=1;
        }
        if(s>exam[tmp].scores[numid])   //取最大分数
        {
            exam[tmp].scores[numid]=s;
            if(s==fullMark[numid])      //全AC数写在这个if里面，以防出现同一题目重复计算AC数
                exam[tmp].perfectNum++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(exam[i].scores[j]>=0)
            {
                exam[i].totalScore+=exam[i].scores[j];
            }
        }
    }
    sort(exam+1,exam+n+1,cmp);  //注意排序的边界
    int rank=1,curRank=1,curScore=exam[1].totalScore;
    for(int i=1;i<=n;i++)
    {
        if(exam[i].flag)
        {
            if(exam[i].totalScore!=curScore)
            {
                curRank=rank;
                curScore=exam[i].totalScore;
            }
            cout<<curRank<<" ";
            cout<<setw(5)<<setfill('0')<<exam[i].userId<<" ";
            cout<<exam[i].totalScore;
            for(int j=1;j<=k;j++)
            {
                if(exam[i].scores[j]>=0)
                    cout<<" "<<exam[i].scores[j];
                else
                    cout<<" -";
            }
            cout<<endl;
            /*
            问题出在这里，因为没有题目编译通过的人总分是0分，有题目编译通过的人总分也有可能
            是0分，后者排序后可能在前者后面，所以rank++应该在if语句里面，不然可能会使后者排名
            出现问题，同时，我一开始在判断到有人不应该出现在排名中后就结束程序，这是不对的
            */
            rank++;
        }
    }
    return 0;
}
