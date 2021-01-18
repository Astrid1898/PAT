/*这个题目很有难度，一开始我是计划用优先队列去做，想了一大堆方法去补坑，但最后卡在时间上没法解决，参考了网上的代码才写出这道题。实际上优先队列只是在窗口较多时找最大值有时间上的优势，但这个题目窗口数量只有不到20个，并不会有优势，反而给编程带来了极大的挑战。以后做题还必须先把代码整体框架写出来再动手编程*/
#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;
class Time	//定义一个时间的类，方便后面使用时间赋值比较等运算
{
    public:
        explicit Time(int h=0,int m=0);
        Time operator+(const int &t) const;
        Time operator+(const Time &t)const;
        Time &operator=(const Time &t);
        int getHour(){return hour;}
        int getMin(){return minute;}
        bool operator<(const Time &t)
        {
            if(hour<t.hour)
                return true;
            else if(minute<t.minute)
                return true;
            return false;
        }
    private:
        int hour;
        int minute;
};
struct person
{
    int serviceTime;
    Time leaveTime;
};
class window	//定义一个窗口，包含队列
{
    public:
    static int capacity;
    window():backTime(8,0){}
    static void setCapacity(unsigned int initCapcity);
    bool isFull()
    {
        return wQueue.size()==capacity;
    }
    void enqueue(person &p);
    void dequeue(){wQueue.pop();}
    person top(){return wQueue.front();}
    int curInQueue(){return wQueue.size();}
    private:
        Time backTime;
        queue<person> wQueue;
};
int window::capacity=5;
int findSmallestQueue(window w[],int size);
int main()
{
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    window::setCapacity(m);	//静态变量必须用静态函数访问
    window* winList=new window[n];
    person persons[k+1];
    for(int i=1;i<=k;i++)
    {
        cin>>persons[i].serviceTime;
        try{
        int index=findSmallestQueue(winList,n);
        if(winList[index].isFull())
        {
            winList[index].dequeue();
            winList[index].enqueue(persons[i]);
        }
        else
        {
            winList[index].enqueue(persons[i]);
        }
		}catch(const char* msg){cerr<<msg<<endl;} //这里调试BUG用
    }
    Time closeTime(17,0);
    while(q--)
    {
        int query;
        cin>>query;
        if(persons[query].leaveTime<(closeTime+persons[query].serviceTime))
        {
            cout<<setw(2)<<setfill('0')<<persons[query].leaveTime.getHour()<<":";
            cout<<setw(2)<<setfill('0')<<persons[query].leaveTime.getMin()<<endl;
        }
        else
        {
            cout<<"Sorry"<<endl;
        }
    }
    delete [] winList;
    return 0;
}
Time::Time(int h,int m)
{
    if(m>=60)
    {
        int up=m/60;
        h+=up;
        m=m-up*60;
    }
    this->hour=h;
    this->minute=m;
}
Time Time::operator+(const int &t) const
{
    Time tmp(this->hour,this->minute+t);
    return tmp;
}
Time Time::operator+(const Time &t)const
{
    Time tmp(this->hour+t.hour,this->minute+t.minute);
    return tmp;
}
Time &Time::operator=(const Time &t)
{
    this->hour=t.hour;
    this->minute=t.minute;
    return *this;
}
int findSmallestQueue(window w[],int size)
{
    int bestWin=0;
    int bestSize=window::capacity;
    for(int i=0;i<size;i++)
    {
        if(!w[i].isFull()&&w[i].curInQueue()<bestSize)
        {
            bestWin=i;
            bestSize=w[i].curInQueue();
        }
    }
    if(bestSize<window::capacity)
        return bestWin;
    bestWin=0;
    Time earlistTime(24,0);
    for(int i=0;i<size;i++)
    {
        if(w[i].top().leaveTime<earlistTime)
        {
            bestWin=i;
            earlistTime=w[i].top().leaveTime;
        }
    }
    return bestWin;
}
void window::enqueue(person &p)	//每次入队的时候把时间更新，实际上队列都满的时候选择最佳窗口就是用的第一个人离开时间最早的窗口，这比我设想的按照时间流逝给每个窗口的元素递减时间要好很多
{
    if(wQueue.size()<capacity)
    {
        backTime=backTime+p.serviceTime;
        p.leaveTime=backTime;
        wQueue.push(p);
    }
    else
    {
        throw "enqueue to a full w_queue.";
    }
}
void window::setCapacity(unsigned int initCapcity)
{
    capacity=initCapcity;
}
