/*
乙级中的题目，并不难
*/
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct mooncake
{
    float storge;	//记录库存
    float price;	//记录单价
    float totalprice;	//记录总价格
};
bool cmp(const mooncake&a,const mooncake &b)
{
    return a.price>b.price;
}
int main()
{
    int n,d;
    cin>>n>>d;
    mooncake Mooncake[n];
    for(int i=0;i<n;i++)
    {
        cin>>Mooncake[i].storge;
    }
    for(int i=0;i<n;i++)
    {
        cin>>Mooncake[i].totalprice;
        Mooncake[i].price=Mooncake[i].totalprice/Mooncake[i].storge;
    }
    sort(Mooncake,Mooncake+n,cmp);	//按照单价非升排序
    float sum=0.0;
    for(int i=0;i<n;i++)	//按照单价非升选取不超过d的数量的月饼，并记录总价格
    {
        if(d==0)
        {
            break;
        }
        if(Mooncake[i].storge<=d)
        {
            sum+=Mooncake[i].totalprice;
            d-=Mooncake[i].storge;
        }
        else
        {
            sum+=Mooncake[i].price*d;
            d=0;
        }
    }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum<<endl;
    return 0;
}
