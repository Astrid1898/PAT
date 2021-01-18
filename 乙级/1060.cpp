#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(const int& a,const int &b)
{
    return a>b;
}
int main()
{
    int n;
    cin>>n;
    int mile[n];
    for(int i=0;i<n;i++)
        cin>>mile[i];
    sort(mile,mile+n,cmp);
    int e=0;
    for(int i=0;i<n;i++)
    {
        if((i+1)<mile[i])
            e=i+1;
        else
            break;
    }
    cout<<e<<endl;
    return 0;
}
