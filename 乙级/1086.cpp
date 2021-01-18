#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string operator*(string &a,string &b)
{
    int a_size=a.size();
    int b_size=b.size();
    if(a_size>b_size)
    {
        b=b.insert(0,a_size-b_size,'0');
    }
    else
    {
        a=a.insert(0,b_size-b_size,'0');
    }
    int up=0;
    string ans;
    for(int i=a.size()-1;i>=0;i--)
    {
        int int_a=a[i]-'0';
        int int_b=b[i]-'0';
        int ab=int_a*int_b+up;
        up=ab/10;
        ab=ab%10;
        ans=char(ab+'0')+ans;
    }
    if(up)
        ans=char(up+'0')+ans;
    return ans;
}
int main()
{
    string a,b;
    cin>>a>>b;
    string ans=a*b;
    reverse(ans.begin(),ans.end());
    int sign=0;
    for(int i=ans.size()-1;i>=0;i--)
    {
        if(ans[i]=='0'&&sign==0)
        {
        }
        else
        {
            cout<<ans[i];
            sign=1;
        }
    }
    cout<<endl;
    return 0;
}
