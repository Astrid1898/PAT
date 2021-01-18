#include<iostream>
#include<cmath>
#include<iomanip>
#define CLK_TCK 100
using namespace std;
int main()
{
    int c1,c2;
    cin>>c1>>c2;
    double time;
    time=double(c2-c1)/(double(CLK_TCK));
    cout<<time<<endl;
    int s_time=round(time);
    cout<<s_time<<endl;
    int ss=s_time%60;
    s_time=s_time/60;
    int mm=s_time%60;
    int hh=s_time/60;
    cout<<setw(2)<<setfill('0')<<hh<<':'<<setw(2)<<setfill('0')<<mm<<':'<<setw(2)<<setfill('0')<<ss;
    return 0;
}
