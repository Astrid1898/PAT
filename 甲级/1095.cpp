/*
之前写了很久，可惜思路有问题，只能对每一问都重新查找一遍
毫无疑问，三个测试点超时，这是https://www.liuchuo.net/archives/2951
的代码
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
struct node //用于存储每条记录
{
    string id;
    int time,flag=0;
};
bool cmp1(node a,node b)    //按照车牌号排序，相等则按时间，可以将记录集中,便于筛选
{
    if(a.id!=b.id)
        return a.id<b.id;
    else
        return a.time<b.time;
}
bool cmp2(node a,node b)    //按时间排序
{
    return a.time<b.time;
}
int main()
{
    int n,k,maxtime=-1,tempindex=0;
    scanf("%d%d\n",&n,&k);
    vector<node> record(n),car;
    for(int i=0;i<n;i++)
    {
        string temp;
        int h,m,s;
        cin>>record[i].id;
        scanf("%d:%d:%d",&h,&m,&s);
        cin>>temp;
        int temptime=h*3600+m*60+s;
        record[i].time=temptime;
        record[i].flag=temp=="in"?1:-1; //进设为1,出为-1
    }
    sort(record.begin(),record.end(),cmp1);
    map<string,int> mapp;   //记录停车时间
    for(int i=0;i<n-1;i++)
    {
        /*
        筛选出有效记录放在car中
        */
        if(record[i].id==record[i+1].id&&record[i].flag==1&&record[i+1].flag==-1)
        {
            car.push_back(record[i]);
            car.push_back(record[i+1]);
            mapp[record[i].id]+=(record[i+1].time-record[i].time);
            if(maxtime<mapp[record[i].id])  //找到最大时间
            {
                maxtime=mapp[record[i].id];
            }
        }
    }
        sort(car.begin(),car.end(),cmp2);   //按照时间给有效记录排序
        vector<int> cnt(n);     //这里先把每个时刻车辆算出来
        for(int i=0;i<car.size();i++) //只要加上flag就行
        {
            if(i==0)
                cnt[i]+=car[i].flag;
            else
                cnt[i]=cnt[i-1]+car[i].flag;
        }
        for(int i=0;i<k;i++)
        {
            int h,m,s;
            scanf("%d:%d:%d",&h,&m,&s);
            int temptime=h*3600+m*60+s;
            int j;
            for(j=tempindex;j<car.size();j++)   //找出最晚的记录即可
            {
                if(car[j].time>temptime)
                {
                    cout<<cnt[j-1]<<endl;
                    break;
                }
                else if(j==car.size()-1)
                {
                    cout<<cnt[j]<<endl;
                }
            }
            tempindex=j;    //避免从头开始找，防止超时
        }
    for(auto it=mapp.begin();it!=mapp.end();it++)   //找出车辆
    {
        if(it->second==maxtime)
        cout<<it->first<<" ";
    }
    cout<<setw(2)<<setfill('0')<<maxtime/3600<<":";
    cout<<setw(2)<<setfill('0')<<(maxtime%3600)/60<<":";
    cout<<setw(2)<<setfill('0')<<maxtime%60<<endl;
    return 0;
}
