#include<iostream>
#include<iomanip>
using namespace std;
int main()
{   
    int n,d;
    float e;
    cin>>n>>e>>d;
    int pos_sum=0,sum=0;
    for(int i=0;i<n;i++)
    {   
        int cont=0;
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            float temp;
            cin>>temp;
            if(temp<e)
                cont++;
        }
        if(cont>(k/2))
        {
            pos_sum++;
            if(k>d)
            {
                sum++;
                pos_sum--;
            }
        }
    }
    float pos_vacant=float(pos_sum)/float(n)*100;
    float vacant=float(sum)/float(n)*100;
    cout<<setiosflags(ios::fixed)<<setprecision(1);
    cout<<pos_vacant<<'%'<<' '<<vacant<<'%';
    return 0;
}
