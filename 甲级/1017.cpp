/*这道题目也真的是坑，卡在最后一个测试点上过不了了，到最后发现是选择窗口算法的问题，银行窗口可能工作的24点后，这也真的是滑稽*/
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
class Time	//定义一个Time类提供对时间的操作，不过全都化成秒更好
{
    public:
        Time(const string& str);
        Time():hour{8},minute{0},second{0}{}
        bool operator>(const Time& t) const;
        bool operator<(const Time& t) const;
        void plus(double m);
        int operator-(const Time &t) const;
        int getHour(){return hour;}
        void printTime()
        {
            cout<<setw(2)<<setfill('0')<<hour<<':'<<setw(2)<<setfill('0')<<minute<<':';
            cout<<setw(2)<<setfill('0')<<second<<endl;
        }
    private:
        int hour;
        int minute;
        int second;
};
struct window
{
    Time nextFreeTime;	//记录当前窗口出现空闲的时间
    void serveThisCustomer(double m,Time *t)	//服务顾客时就把时间加上顾客时间就好
    {
        if(*t<nextFreeTime)
            nextFreeTime.plus(m);
        else
        {
            nextFreeTime=*t;
            nextFreeTime.plus(m);
        }
    }
};
struct customer
{
    string arriveTime;
    double serviceTime;
};
int findEarliestWindow(window w[],int k);
bool cmp(const customer &a,const customer &b)
{
    return a.arriveTime<b.arriveTime;
}
int main()
{
    int n,k;
    cin>>n>>k;
    window windows[k];
    Time closeTime("17:00:00");
    int waitTime=0;
    int customernum=0;
    customer customers[n];
    for(int i=0;i<n;i++)
    {
        cin>>customers[i].arriveTime>>customers[i].serviceTime;
    }
    sort(customers,customers+n,cmp);
    for(int i=0;i<n;i++)
    {
        int tmp=0;
        int index=findEarliestWindow(windows,k);
        Time *t=new Time(customers[i].arriveTime);
        if(customers[i].serviceTime>60)
        {
            customers[i].serviceTime=60;
        }
        if(*t>closeTime)
        {
            delete t;
            continue;
        }
        if(windows[index].nextFreeTime<*t)
        {
            tmp=0;
        }
        else
        {
            tmp=windows[index].nextFreeTime-*t;
        }			
        waitTime+=tmp;
        customernum++;
        windows[index].serveThisCustomer(customers[i].serviceTime,t);
        delete t;
    }
    if(customernum!=0)
        cout<<setiosflags(ios::fixed)<<setprecision(1)<<float(waitTime)/float(customernum)/float(60.0);
    else
        cout<<"0.0";
    return 0;
}
Time::Time(const string& str)
{
    hour=(str[0]-'0')*10+(str[1]-'0');
    minute=(str[3]-'0')*10+(str[4]-'0');
    second=(str[6]-'0')*10+(str[7]-'0');
}
bool Time::operator>(const Time& t) const
{
    return hour==t.hour?(minute==t.minute?second>t.second:minute>t.minute):hour>t.hour;
}
bool Time::operator<(const Time& t) const
{
    return hour==t.hour?(minute==t.minute?second<t.second:minute<t.minute):hour<t.hour;
}
void Time::plus(double m)
{
    int tmp=hour*60*60+minute*60+second+60*m;
    second=tmp%60;
    tmp=tmp/60;
    minute=tmp%60;
    hour=tmp/60;
}
int Time::operator-(const Time &t) const
{
    int s1=0,s2=0,ss=0;
    s1=hour*60*60+minute*60+second;
    s2=t.hour*60*60+t.minute*60+t.second;
    ss=s1-s2;
    return ss;
}
int findEarliestWindow(window w[],int k)	//其实这里使用优先队列更好
{
    int ans=0;
    Time early=w[0].nextFreeTime;
    for(int i=1;i<k;i++)
    {
        if(w[i].nextFreeTime<early)
        {
            early=w[i].nextFreeTime;	//注意，这里存在坑，都与第一个窗口比可以避免设置最大值，由于17点到来之前的人必须被服务，窗口可能持续工作到几天后
            ans=i;
        }
    }
    return ans;
}
