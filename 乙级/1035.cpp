#include<iostream>
#include<algorithm>
using namespace std;
int insertion(int n,int chushi[],int temp[],int flag)
{
    for(int i=2;i<n;i++)
    {
        sort(chushi,chushi+i);
        int mm=0;
        for(int m=0;m<n;m++)
        {
            if(chushi[m]==temp[m])
            {
                mm++;
            }
        }
        if(mm==n)
        {
            flag=0;
            cout<<"Insertion Sort"<<endl;
            sort(chushi,chushi+i+1);
            for(int i=0;i<n-1;i++)
            {
                cout<<chushi[i]<<' ';
            }
            cout<<chushi[n-1];
        }
    }
    return flag;
}
void merge(int n,int chushi[],int temp[],int flag)
{
    int k=1;
for(int i=0;i<n;i++)
	cout<<chushi[i]<<endl;
    while(flag)
    {
        flag=0;
        for(int i=0;i<n;i++)
        {
            if(chushi[i]!=temp[i])
            {
                flag=1;
                break;
            }
        }
        k=2*k;
        int kk=n/k;
        for(int j=0;j<kk;j++)
        {
            sort(chushi+j*k,chushi+(j+1)*k);
        }
        sort(chushi+k*kk,chushi+n);
    }
    cout<<"Merge Sort"<<endl;
    for(int i=0;i<n-1;i++)
    {
        cout<<chushi[i]<<' ';
    }
    cout<<chushi[n-1];
}
int main()
{
    int n;
    cin>>n;
    int chushi[n],temp[n],chushi1[n],temp1[n];
    for(int i=0;i<n;i++)
    {
        cin>>chushi[i];
        chushi1[i]=chushi[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>temp[i];
        temp1[i]=temp[i];
    }
    int flag=1;
    flag=insertion(n,chushi,temp,flag);
    if(flag)
        merge(n,chushi1,temp1,flag);
    return 0;
}
