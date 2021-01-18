/*着一道题目也挺简单的，就是求最大值问题，估计是想再提供个和赔率有关的胜率什么的让算最大期望，到最后简化成了这个样子*/

#include<iostream>
#include<iomanip>
using namespace std;
inline double the_max_profit(const double max[3])	//利用公示计算收益
{
    double profit=1;
    for(int i=0;i<3;i++)
    {
        profit*=max[i];
    }
    profit=(profit*0.65-1)*2;
    return profit;
}
int main()
{
    double odd[3],best[3]={0};	//算出来每场比赛最大值赔率保存在best中
    char c[3]={'W','T','L'};
    for(int j=0;j<3;j++)
    {
        double max=0.0;
        int index;
        for(int i=0;i<3;i++)
        {
            cin>>odd[i];
            if(odd[i]>max)
            {
                max=odd[i];
                index=i;
            }
        }
        best[j]=max;
        cout<<c[index]<<' ';
    }
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<the_max_profit(best)<<endl;
    return 0;
}
