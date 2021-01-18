#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long number[n];
    long sort_number[n];
    int sign=1;
    int cont=0;
    vector<long> zhuyuan;
    for(int i=0;i<n;i++)
    {
        cin>>number[i];
        sort_number[i]=number[i];
    }
    sort(sort_number,sort_number+n);
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(number[i]>max)
        {
            max=number[i];
            if(number[i]==sort_number[i])
            {
                cont++;
                zhuyuan.push_back(number[i]);
            }
        }
    }
    cout<<cont<<endl;
    cout<<zhuyuan[0];
    for(int i=1;i<zhuyuan.size();i++)
    {
        cout<<' '<<zhuyuan[i];
    }
    return 0;
}
