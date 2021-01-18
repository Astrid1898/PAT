/*
主要是排序，拍完挨个作为最小值找就行了
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    long long  n,p;
    cin>>n>>p;
    vector<long long> sequence(n);
    for(int i=0;i<n;i++)
        cin>>sequence[i];
    sort(sequence.begin(),sequence.end());
    int i=0,tmp=0,max=0,j=0;
    for(int i=0;i<n;i++)
    {
        while(sequence[i]*p>=sequence[j]&&j!=n) //找到临界的j
        {
            j++;
        }
        tmp=j-i;
        if(max<tmp)
            max=tmp;
    }
    cout<<max<<endl;
    return 0;
}
