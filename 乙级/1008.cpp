#include<iostream>
using namespace std;
int main()
{
    int M,N;
    cin>>N>>M;
    int *p=new int[N];
    for(int i=0;i<N;i++)
        cin>>p[i];
    M=M%N;
    for(int i=N-M;i<N;i++)
    {
        cout<<p[i]<<" ";
    }
    for(int i=0;i<N-M-1;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<p[N-M-1];
    return 0;
}
