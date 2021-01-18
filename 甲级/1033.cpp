/*这道题要使用贪心算法，一开始没有想出来，看了网上的代码和解析才会搞
*要仔细考虑范围内油价相同的点如何选取的问题
*/


#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct Station 		//存储加油站点
{
    double price;
    double distance;
};
bool cmp(const Station &a,const Station &b)
{
    return a.distance==b.distance?a.price<b.price:a.distance<b.distance;
}	//距离短，油价低的靠前，对加油站点进行排序，不排序当然也可以使用，但是运行时间会很长
int main()
{
    cout<<setiosflags(ios::fixed)<<setprecision(2); //设置输出精度
    double cmax,d,davg,c=0.0;
    int n;
    double costs=0.0;
    cin>>cmax>>d>>davg>>n;
    Station stations[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>stations[i].price>>stations[i].distance;
    }
    stations[n].price=0.0;stations[n].distance=d;
    sort(stations,stations+n+1,cmp);
    int thisstation=0;
	double maxdistance=cmax*davg;
    if(stations[0].distance)
    {
        cout<<"The maximum travel distance = 0.00"<<endl;
        return 0;
    }	//测试点2,注意边界条件
    while(thisstation<n)
    {
        if(stations[thisstation].distance+maxdistance<stations[thisstation+1].distance)
        {
            cout<<"The maximum travel distance = "<<stations[thisstation].distance+maxdistance<<endl;
            break;
        }	//下一个加油站距离太远，无法抵达
        int nextMinPriceStation=thisstation;
        for(int i=thisstation+1;i<=n;i++)
        {
            if(stations[thisstation].distance+maxdistance>=stations[i].distance)
            {
                if(stations[i].price<=stations[thisstation].price)
                {
                    nextMinPriceStation=i;	//找出第一个油价比当前站点低的站点，加足以到达该站点的油量
                    break;
                }
            }
            else
                break;
        }
        if(nextMinPriceStation==thisstation)	//处理范围内站点油价都比当前高点情况
        {
            nextMinPriceStation=thisstation+1;
            for(int i=thisstation+2;i<=n;i++)
            {
                if(stations[thisstation].distance+maxdistance>=stations[i].distance)
                {
                    if(stations[i].price<=stations[nextMinPriceStation].price)
                    {
                        nextMinPriceStation=i;	//找出范围内油价最低距离最远的加油站为下一个站点
                    }
                }
                else
                    break;
            }
            costs+=(cmax-c)*stations[thisstation].price;
            c=cmax-(stations[nextMinPriceStation].distance-stations[thisstation].distance)/davg;
            thisstation=nextMinPriceStation;
        }
        else
        {
            c=(stations[nextMinPriceStation].distance-stations[thisstation].distance)/davg-c;
            costs+=c*stations[thisstation].price;
            c=0;
            thisstation=nextMinPriceStation;
        }
    }
    if(thisstation==n)
        cout<<costs<<endl;
    return 0;
}
