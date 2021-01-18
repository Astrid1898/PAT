/*看到题目还以为要写出课程的先修结构，读完才发现只是让写出课程
*这就比较简单了，用散列表就可以解决
*网上说用map会超时，但是这里并没有超时，所以也不用再把名字转化为数字*/
#include<iostream>
#include<map>
#include<vector>
#include<lgorithm>
using namespace std;
int main()
{
    map<string,vector<int>> mp;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        int course=0,num=0;
        cin>>course>>num;
        while(num--)
        {
            string name;
            cin>>name;
            mp[name].push_back(course);
        }
    }
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        sort((it->second).begin(),(it->second).end());
    }
    while(n--)
    {
        string name;
        cin>>name;
        cout<<name;
        cout<<" "<<mp[name].size();
        for(int i=0;i<(mp[name]).size();i++)
        {
            cout<<" "<<(mp[name])[i];
        }
        cout<<endl;
    }
    return 0;
}
