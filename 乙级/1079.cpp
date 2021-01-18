#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int cnt=0;
string operator+(const string &a,const string &b)
{
    int len=a.size();
    int up=0;
    string ans;
    for(int i=len-1;i>=0;i--)
    {
        int int_a=a[i]-'0';
        int int_b=b[i]-'0';
        int sum=int_a+int_b+up;
		up=sum/10? 1:0;
        sum=sum%10;
        ans.insert(ans.begin(),1,sum+'0');
    }
    if(up)
        ans.insert(ans.begin(),1,'1');
    return ans;
}
bool is_pali_num(const string& num,const string& reve_num)
{
    if(num==reve_num)
        return true;
    return false;
}
bool is_delayed_pali_num(string& b)
{
    string a(b);
    reverse(b.begin(),b.end());
    if(is_pali_num(a,b))
        return true;
    else if(cnt>=10)
        return false;
    cnt++;
    cout<<a<<" + "<<b<<" = ";
    b=a+b;
    cout<<b<<endl;
    return is_delayed_pali_num(b);
}
int main()
{
    string b;
    cin>>b;
    if(is_delayed_pali_num(b))
        cout<<b<<" is a palindromic number."<<endl;
    else
        cout<<"Not found in 10 iterations."<<endl;
    return 0;
}
