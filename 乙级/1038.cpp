#include<iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int number[101]={0};
    int score;
    for(int i=0;i<N;i++)
    {
        cin>>score;
        number[score]++;
    }
    int n;
    cin>>n;
    int temp[n];
    for(int i=0;i<n;i++)
    {
        cin>>temp[i];
    }
    for(int i=0;i<n-1;i++)
    {
        cout<<number[temp[i]];
    }
    cout<<number[temp[n-1]];
    return 0;    
}
