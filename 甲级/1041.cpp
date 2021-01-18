/*同样是没有看清楚题目，以为是按每一位Unique的，结果是整体Unique的
*这就好办了，用一个辅助数组就解决了*/
#include<iostream>
using namespace std;
#define INF 10005
int main()
{
    int num[INF]={0};
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        num[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(num[a[i]]==1)
        {
            cout<<a[i]<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;
    return 0;
}
