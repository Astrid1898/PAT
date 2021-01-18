#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int temp,sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        sum+=temp;
    }
    sum=sum*(n-1);
    cout<<sum*10+sum;
    return 0;
}
