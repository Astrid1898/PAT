/*
这题不知道在考什么，以为会有大量数据导致超时，结果却没有，
不敢相信这是25分的题目，觉得PAT考试分值设置有点奇怪
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct node     //存储考生信息
{
    string name;
    string id;
    int grade;
};
bool cmp(const node &a,const node &b)
{
    return a.grade>b.grade;
}
int main()
{
    int n;
    cin>>n;
    vector<node> student(n);
    for(int i=0;i<n;i++)
    {
        cin>>student[i].name>>student[i].id>>student[i].grade;
    }
    int grade1,grade2;
    cin>>grade1>>grade2;
    vector<node> stuinInterval;
    for(auto tmp:student)   //先筛选数据后排序比反过来要快
    {
        if(tmp.grade>=grade1&&tmp.grade<=grade2)
        {
            stuinInterval.push_back(tmp);
        }
    }
    if(stuinInterval.size()==0)
    {
        cout<<"NONE"<<endl;
        return 0;
    }
    sort(stuinInterval.begin(),stuinInterval.end(),cmp);
    for(auto tmp:stuinInterval)
    {
        cout<<tmp.name<<" "<<tmp.id<<endl;
    }
    return 0;
}
