/*这道题有测试点6没有通过，不知道为什么，总之这道题目测试点各种坑*/

#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;
class Time	//写一个可以用的Time类，虽然可以统一化成秒，但是习惯性写个类
{
    public:
        Time():hour{8},minute{0},second{0}{}
		Time(int a,int b,int c):hour{a},minute{b},second{c}{}
        explicit Time(const string &str);
        Time(const Time &t){hour=t.hour;minute=t.minute;second=t.second;}
        bool operator<(const Time &t) const;
        bool operator==(const Time &t) const;
        void showTime() const;
        Time operator+(const int t);
        int operator-(const Time &t);
    private:
        int hour;
        int minute;
        int second;
};
struct Player
{
    Time arriveTime;	//到达时间
    int playTime;	//需要占用的时间
    bool isVip;	//VIP标志
    Time servedTime;	//被服务的时间
    bool operator<(const Player& p) const
    {
        return arriveTime<p.arriveTime;
    }
};
struct Table
{
    int cnt{0};	//计数
    Time nextFreeTime;	//下一次可用的时间
    bool isVip{false};	//VIP标志
    void servePlayer(Player& p);	//服务player的过程
};
int findEarliestTable(Table tables[],int size) //返回最早空出的桌子
{
    int id=0;
    Time minTime("23:59:59");
    for(int i=1;i<=size;i++)
    {
        if(tables[i].nextFreeTime<minTime)
        {
            minTime=tables[i].nextFreeTime;
            id=i;
        }
    }
    return id;
}
int findEarliestVipTable(Table tables[],int size)	//返回最早空出的VIP桌子
{
    int id=0;
    Time minTime("23:59:59");
    for(int i=1;i<=size;i++)
    {
        if(tables[i].nextFreeTime<minTime&&tables[i].isVip)
        {
            minTime=tables[i].nextFreeTime;
            id=i;
        }
    }
    return id;
}
int main()
{
    int n;
    cin>>n;	//读入player数量
    vector<Player> players(n);
    for(int i=0;i<n;i++)	//读入player信息
    {
        string str;
        int min,sign;
        cin>>str>>min>>sign;
        if(min>120)
            min=120;
        Time tmp(str);
        players[i].arriveTime=tmp;
        players[i].playTime=min;
        players[i].isVip=false;
        if(sign)
            players[i].isVip=true;
        
    }
    sort(players.begin(),players.end());	//按照到达时间排序
    int k,m;	//读入桌子数量k和vip桌子数量m
    cin>>k>>m;
    Table tables[k+1];
    while(m--)	//读入table的VIP信息
    {
        int vipNum;
        cin>>vipNum;
        tables[vipNum].isVip=true;
    }
	Time closeTime(21,0,0);
    while(players.size())	//如果队列中还有人，就一直处理
    {
        auto itr=players.begin();	//返回队列中到达时间最早的player
        int id=findEarliestTable(tables,k);	//最早释放的桌子ID号
		//cout<<"id="<<id<<"    "<<"isVIP="<<tables[id].isVip<<endl;
		//cout<<"tables["<<id<<"].nextFreeTime=";		
		//tables[id].nextFreeTime.showTime();
		//cout<<endl;
		if(!(tables[id].nextFreeTime<closeTime))	//所有桌子都占用到关门时间后就停止循环
		{
			//tables[id].nextFreeTime.showTime();
			//cout<<endl;
			break;
		}
        if(tables[id].isVip)	//如果最早结束的桌子是VIP的就询问在这之前是否有VIP客户
        {
            auto tmpItr=itr;
            while((*tmpItr).arriveTime<(tables[id].nextFreeTime)||(*tmpItr).arriveTime==(tables[id].nextFreeTime))
            {
                if((*tmpItr).isVip)
                {
                    itr=tmpItr;	//找到VIP，该轮服务VIP客户
                    break;
                }
                else
                    tmpItr++;
            }
        }
        else if((*itr).isVip)	//如果桌子不是VIP但当前轮次要服务的客户是VIP，就试图询问最早空闲的VIP桌子在该客户到来之前是否可用
        {
            int vipId=findEarliestVipTable(tables,k);
            if(tables[vipId].nextFreeTime<(*itr).arriveTime||tables[vipId].nextFreeTime==(*itr).arriveTime)
                id=vipId;	//判断为可用，就使用这张桌子
        }
        if(!((*itr).arriveTime<closeTime))	//题目嘴上说客户都是在营业时间到达，但是不加判断会有测试点过不去，真的是个很难看出来的坑，以后不管题目怎么说还是要考虑边界条件的，增加鲁棒性
        {
            players.erase(itr);
            continue;
        }
        tables[id].servePlayer(*itr);	//调用服务例程
        (*itr).arriveTime.showTime();
        cout<<' ';
        (*itr).servedTime.showTime();
        cout<<' '<<(*itr).servedTime-(*itr).arriveTime<<endl;
        players.erase(itr);
    }
    cout<<tables[1].cnt;
    for(int i=2;i<=k;i++)
    {
        cout<<" "<<tables[i].cnt;
    }
    return 0;
}
void Time::showTime() const
{
    cout<<setw(2)<<setfill('0')<<hour<<":";
    cout<<setw(2)<<setfill('0')<<minute<<":";
    cout<<setw(2)<<setfill('0')<<second;
}
Time::Time(const string &str)
{
    hour=(str[0]-'0')*10+str[1]-'0';
    minute=(str[3]-'0')*10+str[4]-'0';
    second=(str[6]-'0')*10+str[7]-'0';
}
bool Time::operator<(const Time &t) const
{
    return hour==t.hour?(minute==t.minute?second<t.second:minute<t.minute):hour<t.hour;
}
Time Time::operator+(const int t)
{
    int tmp1=this->hour*60*60+this->minute*60+this->second;
    int tmp2=t*60;
    int ans=tmp1+tmp2;
	Time tt;
    tt.second=ans%60;
    ans=(ans-tt.second)/60;
    tt.minute=ans%60;
    ans=(ans-tt.minute)/60;
    tt.hour=ans;
    return tt;
}
int Time::operator-(const Time &t)
{
    int tmp1=hour*60*60+minute*60+second;
    int tmp2=t.hour*60*60+t.minute*60+t.second;
    int ans=tmp1-tmp2;
    ans=(ans+30)/60;
    return ans;
}
void Table::servePlayer(Player& p)
{
    cnt++;
    if(!(nextFreeTime<p.arriveTime))
    {
        p.servedTime=nextFreeTime;
        nextFreeTime=nextFreeTime+p.playTime;
    }
    else
    {
        p.servedTime=p.arriveTime;
        nextFreeTime=p.arriveTime+p.playTime;
    }
}
bool Time::operator==(const Time &t) const
{
    if(hour!=t.hour)
        return false;
    if(minute!=t.minute)
        return false;
    if(second!=t.second)
        return false;
    return true;
}



