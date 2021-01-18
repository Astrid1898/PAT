/*直接查找会超时，写了个二分查找的find就好了*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> coins;
int find(int begin,int end,int toFind) //二分法查找tofind
{
    if(begin>end||toFind>coins[end]||toFind<coins[begin])
    {
        return -1;
    }
    int mid=(begin+end)/2;
    if(toFind>coins[mid])
    {
        find(mid+1,end,toFind);
    }
    else if(toFind<coins[mid])
    {
        find(begin,mid-1,toFind);
    }
    else
    {
        return mid;
    }
    
}
int main()
{
    int n,k;
    cin>>n>>k;
    coins.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    sort(coins.begin(),coins.end());
    for(int i=0;i<coins.size()&&coins[i]<=k;i++)
    {
        int toFind=k-coins[i];
        int index=find(0,coins.size()-1,toFind);
        if(index!=-1&&index!=i)
        {
            cout<<coins[i]<<" "<<toFind<<endl;
            return 0;
        }
    }
    cout<<"No Solution"<<endl;
    return 0;
}
