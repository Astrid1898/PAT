#include<iostream>
#include<vector>
using namespace std;
int mcm(int a,int b)
{
    if(a<b)
        swap(a,b);
    int ans=b;
    while(a%b)
    {
        ans=a%b;
        a=b;
        b=ans;
    }
    return ans;    
}
void swap(auto &a,auto &b)
{
    auto temp=a;
    a=b;
    b=temp;
}
struct frac
{
    int numerator;
    int denominator;
};
ostream &operator<<(ostream& output,const frac& f)
{
    output<<f.numerator<<'/'<<f.denominator;
}
int main()
{
    frac f1,f2;
    scanf("%d/%d",&f1.numerator,&f1.denominator);
    scanf("%d/%d",&f2.numerator,&f2.denominator);
    int k;
    cin>>k;
    double up,low;
    double multiplying1=double(f1.denominator)/double(k);
    double multiplying2=double(f2.denominator)/double(k);
    up=double(f1.numerator)/multiplying1;
    low=double(f2.numerator)/multiplying2;
    if(low>up)
        swap(up,low);
    int int_up=int(up);
    int int_low=int(low)+1;
    vector<frac> f;
    frac f3;
    for(int i=int_low;i<=int_up;i++)
    {
        if(mcm(i,k)==1)
            {
                f3.numerator=i;
                f3.denominator=k;
                f.push_back(f3);
            }
    }
    int i;
    for(i=0;i<f.size()-1;i++)
    {
        cout<<f[i]<<' ';
    }
    cout<<f[i];
    return 0;
}
