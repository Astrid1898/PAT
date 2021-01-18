#include<iostream>
#include<iomanip>
using namespace std;
void TheMostExpensive(int a[],int b[],int var);
float TheProfit(int requirement,int i,int a[],int b[]);
int main()
{
    int var=0,requirement=0;
    cin>>var>>requirement;
    int stock[var]={0},price[var]={0};
    int i=0,sum=0;
    float profit=0.0;
    for(i;i<var;i++)
    {
        cin>>stock[i];
    }
    for(i=0;i<var;i++)
    {
        cin>>price[i];
    }
    TheMostExpensive(stock,price,var);
    i=0;
    while(sum<requirement)
    {
        sum+=stock[i];
        i++;
    }
    i=i-1;
    profit=TheProfit(requirement,i,stock,price);
    cout<<setprecision(2)<<std::fixed<<profit;
    return 0;
}
void TheMostExpensive(int a[],int b[],int var)
{
    float c[var]={0.0};
    for(int i=0;i<var;i++)
    {
        c[i]=float(b[i])/float(a[i]);
    }
    for(int i=0;i<var-1;i++)
    {
        for(int j=var-1;j>i;j--)
        {
            if(c[j]>c[j-1])
            {
                float ctmp=c[j-1];
                int atmp=a[j-1];
                int btmp=b[j-1];
                c[j-1]=c[j];
                a[j-1]=a[j];
                b[j-1]=b[j];
                c[j]=ctmp;
                a[j]=atmp;
                b[j]=btmp;
            }
        }
    }
}
float TheProfit(int requirement,int i,int a[],int b[])
{
    float profit=0;
    int sum=0;
    for(int j=0;j<i;j++)
    {
        profit+=b[j];
        sum+=a[j];
    }
    profit=profit+(requirement-sum)*(float(b[i])/float(a[i]));
    return profit;
}
