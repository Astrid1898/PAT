/*按照考场和名词排序的题目，实际上倒也并不是真的要专门搞个数据存储名次
*在输出的时候就能顺带解决*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Testee 	//存储考生的信息
{
    string registrationNum;
    int score;
    int location;	//存储考场号
};
bool cmp(const Testee &a,const Testee &b)
{
    return a.score==b.score? a.registrationNum<b.registrationNum:a.score>b.score;
}
int main()
{
    vector<Testee> testees;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            Testee tmp;
            cin>>tmp.registrationNum>>tmp.score;
            tmp.location=i;
            testees.push_back(tmp);
        }
    }
    if(!testees.size())
    {
        return 0;
    }
    sort(testees.begin(),testees.end(),cmp);	//按照分数从高到低排序
    cout<<testees.size()<<endl;
    int finalRank=1,localRank[n+1],lastLocalScore[n+1],localCnt[n+1];	//finalRank记录全部排名，localRank数组记录各个考场的排名，lastLocalScore记录输出中上一个该考场的考生分数，以处理并列情况给出考场排名，localCnt记录每个考场人数
    fill(localRank,localRank+n+1,1);fill(lastLocalScore,lastLocalScore+n+1,-1);fill(localCnt,localCnt+n+1,0);
    
	/*下面这一堆代码很混乱，需要整理一下，实际上只要用个记录上一个输出分数的变量就可以把testee[0]的
	*的情况并入循环，但是已经AC了就不想改了，人类的惰性*/	
	localCnt[testees[0].location]++;
    if(testees[0].score!=lastLocalScore[testees[0].location]) localRank[testees[0].location]=localCnt[testees[0].location];
    cout<<testees[0].registrationNum<<" "<<finalRank<<" "<<testees[0].location<<' '<<localRank[testees[0].location]<<endl;
    lastLocalScore[testees[0].location]=testees[0].score; 
    for(int i=1;i<testees.size();i++)
    {
        localCnt[testees[i].location]++;
        if(testees[i].score!=testees[i-1].score)
        {
            finalRank=i+1;
        }
        if(testees[i].score!=lastLocalScore[testees[i].location]) 
        {
            localRank[testees[i].location]=localCnt[testees[i].location];
        }
        cout<<testees[i].registrationNum<<' '<<finalRank<<' '<<testees[i].location<<' '<<localRank[testees[i].location]<<endl;
        lastLocalScore[testees[i].location]=testees[i].score;
    }
    return 0;
}
