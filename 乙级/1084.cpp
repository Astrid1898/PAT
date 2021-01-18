#include<iostream>
#include<string>
using namespace std;
string get_the_n_term(const string& d,int n)
{
    if(n==1)
        return d;
    string ans;
    for(int i=0;i<d.size();i++)
    {
        int cnt=1;
        while((i+cnt)<d.size()&&d[i]==d[i+cnt])
        {
            cnt++;
        }
        i=i+cnt-1;
        ans.push_back(d[i]);
        ans.push_back(cnt+'0');
    }
    n--;
    if(n>1)
        return get_the_n_term(ans,n);
    else if(n==1)
        return ans;
}
int main()
{
    string d;
    int n;
    cin>>d>>n;
    string ans=get_the_n_term(d,n);
    cout<<ans<<endl;
    return 0;
}
