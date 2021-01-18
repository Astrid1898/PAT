#include<iostream>
#include<vector>
#include<algorithm>
bool cmp(const int& a,const int& b)
{
    return a>b;
}
int get_friend_num(int a)
{
    int sum=0;
    while(a)
    {
        sum+=a%10;
        a=a/10;
    }
    return sum;
}
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num[n];
    int temp=0;
    vector<int> friend_num;
    vector<int>::iterator it;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        temp=get_friend_num(num[i]);
        it=find(friend_num.begin(),friend_num.end(),temp);
        if(it==friend_num.end())
            friend_num.push_back(temp);
    }
    cout<<friend_num.size()<<endl;
    sort(friend_num.begin(),friend_num.end(),cmp);
    cout<<friend_num[0];
    for(int i=1;i<friend_num.size();i++)
    {
        cout<<' '<<friend_num[i];
    }
    return 0;
}
