/*一开始想到的是用回溯算法，后来经提醒采用了动态规划的算法，使用
*一个dp数组记录截止到i时最长串的长度dp[i]*/


#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m,l,ans=0;
    cin>>n>>m;
    vector<int> colors(n+1,-1),stripe;
    for(int i=0;i<m;i++)
    {
        int tmp;
        cin>>tmp;
        colors[tmp]=i;	//给选定的颜色依次赋权值
    }
    cin>>l;
    while(l--)
    {
        int tmp;
        cin>>tmp;
        if(colors[tmp]!=-1)
        {
            stripe.push_back(tmp);	//只顺序保留选定的颜色
        }
    }
    int size=stripe.size();
    vector<int> dp(size);
    for(int i=0;i<size;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(colors[stripe[i]]>=colors[stripe[j]])
            {
                dp[i]=max(dp[j]+1,dp[i]);	//若j节点是权值小于等于i，则更新dp[i]
            }
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}	
