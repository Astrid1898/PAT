/*又是一道简单的数字题目，并没有那一道搞进制的难
*唯一的坑点大概就在要用string而不能用long long上，长度不够*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void addReverseNum(string &n);
bool isPolindormicNum(const string &n);
int main()
{
    int k,i=0;
    string n;
    cin>>n>>k;
    if(isPolindormicNum(n));
    else
    {
        for(i=0;i<k;i++)
        {
            addReverseNum(n);
            if(isPolindormicNum(n))
            {
                i++;
                break;
            }
        }
    }
    cout<<n<<endl;
    cout<<i<<endl;
    return 0;
}
void addReverseNum(string &n)
{
    string revN=n;
    string ans;
    int up=0;
    reverse(revN.begin(),revN.end());
    for(int i=0;i<n.size();i++)
    {
        int tmp=(revN[i]-'0')+(n[i]-'0')+up;
        up=tmp/10;
        tmp=tmp-up*10;
        ans=char(tmp+'0')+ans;
    }
    if(up)
    {
        ans=char(up+'0')+ans;
    }
    n=ans;
}
bool isPolindormicNum(const string &n)
{
    int size=n.size();
    for(int i=0;i<size/2;i++)
    {
        if(n[i]!=n[size-i-1])
        {
            return false;
        }
    }
    return true;
}
