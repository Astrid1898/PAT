/*求最长回文串，有很多经典的算法
*这里采用的是动态规划的方法*/
#include<iostream>
#include<string>
using namespace std;
int maxn=1,len=0;
string str;
bool dp[1010][1010];
int main()
{
    getline(cin,str);
    len=str.size();
    fill(dp[0],dp[0]+1010*1010,false);
    for(int i=0;i<len;i++)
    {
        dp[i][i]=true;
        if(i!=len-1&&str[i]==str[i+1])
        {
            dp[i][i+1]=true;
            maxn=2;
        }
    }
    for(int k=3;k<=len;k++)
    {
        for(int i=0;i+k-1<len;i++)
        {
            if(str[i]==str[i+k-1]&&dp[i+1][i+k-2])
            {
                dp[i][i+k-1]=true;
                maxn=k;
            }
        }
    }
    cout<<maxn<<endl;
    return 0;
}
