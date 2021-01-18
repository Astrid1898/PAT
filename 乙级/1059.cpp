#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
bool is_prime_number(const int&);
int main()
{
    int id[10000]={0};
    int n;
    cin>>n;
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        id[temp]=i+1;
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>temp;
        if(id[temp]==1)
            {
                cout<<setw(4)<<setfill('0')<<temp<<": "<<"Mystery Award"<<endl;
                id[temp]=-1;
            }
        else if(is_prime_number(id[temp]))
        {
            cout<<setw(4)<<setfill('0')<<temp<<": "<<"Minion"<<endl;
            id[temp]=-1;
        }
        else if(id[temp]==0)
        {
            cout<<setw(4)<<setfill('0')<<temp<<": "<<"Are you kidding?"<<endl;
        }
        else if(id[temp]==-1)
        {
            cout<<setw(4)<<setfill('0')<<temp<<": "<<"Checked"<<endl;
        }
        else
        {
            cout<<setw(4)<<setfill('0')<<temp<<": "<<"Chocolate"<<endl;
            id[temp]=-1;
        }
    }
    return 0;
}
bool is_prime_number(const int& k)
{
    if(k<1)
        return false;
    for(int i=2;i<=sqrt(k);i++)
    {
        if(k%i==0)
            return false;
    }
    return true;
}
