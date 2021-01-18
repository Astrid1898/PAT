#include<iostream>
using namespace std;
bool is_autonomous(int i,int ikk,int k)
{
    int sign=10;
    while(k)
    {
        if((k%sign)!=(ikk%sign))
            return false;
        k=k/10;
        ikk=ikk/10;
    }
    return true;
}
void is_autonomous_num(int k)
{
    int kk=k*k;
    for(int i=0;i<9;i++)
    {
        int ikk=i*kk;
        if(is_autonomous(i,ikk,k))
        {
            cout<<i<<' '<<ikk<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}
int main()
{
    int m;
    cin>>m;
    int temp;
    for(int i=0;i<m;i++)
    {
        cin>>temp;
        is_autonomous_num(temp);
    }
    return 0;
}
