#include<iostream>
#include<map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *init_num=new int[n];
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        cin>>init_num[i];
        int temp=abs(init_num[i]-(i+1));
        mp[temp]++;
    }
    delete [] init_num;
    map<int,int>::reverse_iterator r_iter;
    for(r_iter=mp.rbegin();r_iter!=mp.rend();r_iter++)
    {
        if(r_iter->second>1)
            cout<<r_iter->first<<' '<<r_iter->second<<endl;
    }
    return 0;
}
