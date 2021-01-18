/************************************************************
*先是试图回溯法解决，但是写到一半写不下去了，看到大家都用的动态
*规划，就学习了一下动态规划。之前就看过相关东西，但一直用不好，现在
*依然用不好，看来得加强动态规划的训练
**************************************************************/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int main()
{
    int n,m;
    cin>>n>>m;
    v.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];	//记录面值
    }
    vector<vector<int>> flag(n+1),dp(n+1);	//flag[i][j]记录面值为i时某个点j是否被使用，dp[i][j]记录总面值不超过j的前i个元素所能组成的最大和
    for(int i=0;i<=n;i++)
    {
        flag[i].resize(101);
        dp[i].resize(101);
    }
    sort(v.begin()+1,v.end(),greater<int>{});	//因为要求尽量用小面值，所以从大到小排序
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j<v[i])
            {
                dp[i][j]=dp[i-1][j];	//v[i]面值超过了总面值，不能使用
            }
            else
            {
                if(dp[i-1][j]>dp[i-1][j-v[i]]+v[i])
                {
                    dp[i][j]=dp[i-1][j];	//不使用v[i]的面值更大
                }
                else
                {
                    dp[i][j]=dp[i-1][j-v[i]]+v[i];	//使用v[i]的面值更大，因为要尽量选取后面小的元素，所以相等时往后取
                    flag[i][j]=1;	//记录使用了这个元素
                }
            }
        }
    }
    if(dp[n][m]<m)
    {
        cout<<"No Solution"<<endl;	//n个元素获得的最大总面值小于m
    }
    else
    {
        int i=n;
        while(m)
        {
            while(!flag[i][m])	//没有被使用就自减i，直到找到一个被使用的点
                i--;
            m-=v[i];	//继续找剩下面值的使用情况
            if(m==0)
            {
                cout<<v[i];	//最后一个
            }
            else
            {
                cout<<v[i]<<" ";
            }
            i--;
        }
    }
    return 0;
}
