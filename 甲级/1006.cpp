/*这几日生活很糟糕，情绪很低落，幸的友人造访，放松半日*/

/*这道题目很简单，单纯的找出最大值和最小值，可以在O(n-1)的时间复杂度完成，看到网上有人甚至用了sort排序，实在是没有必要，不过这个数据量差别也不大吧*/

/*其实可以有统一化成秒比较和直接字符串比较两种做法，这里采用了后一种做法，感觉上这种方法要比前者快一些*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct record
{
    string id;
    string sign_in;
    string sign_out;
};//用于记录每个人的打卡记录
istream &operator>>(istream& input,record &r)
{
    input>>r.id>>r.sign_in>>r.sign_out;
    return input;
}	//重载>>运算符，提高代码易读性
int main()
{
    int m;
    cin>>m;
    record records[m];
    for(int i=0;i<m;i++)
    {
        cin>>records[i];
    }
    string sign_in_id,sign_out_id,min("23:59:59"),max("00:00:00");
    for(int i=0;i<m;i++)	//开始逐个比较
    {
        if(records[i].sign_in<min)
        {
            sign_in_id=records[i].id;
            min=records[i].sign_in;
        }
        if(records[i].sign_out>max)
        {
            sign_out_id=records[i].id;
            max=records[i].sign_out;
        }
    }
    cout<<sign_in_id<<' '<<sign_out_id<<endl;
    return 0;
}
