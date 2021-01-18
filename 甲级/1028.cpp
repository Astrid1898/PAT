/*这道题目试着使用了新看到的函数指针当作练习
*最后一个测试点有一定概率运行超时，网上说是cin的缘故要改成sanf最好不要用string
*不过既然能过就不改了，大概293ms*/


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct Student
{
    string id;
    string name;
    int score;
};
istream &operator>>(istream &input,Student &s)
{
    input>>s.id>>s.name>>s.score;
    return input;
}
ostream &operator<<(ostream &output,const Student &s)
{
    output<<s.id<<' '<<s.name<<' '<<s.score;
    return output;
}
bool cmp1(const Student &a,const Student &b)
{
    return a.id<b.id;
}
bool cmp2(const Student &a,const Student &b)
{
    return a.name==b.name?a.id<b.id:a.name<b.name;
}
bool cmp3(const Student &a,const Student &b)
{
    return a.score==b.score?a.score<b.score:a.name<b.name;
}
int main()
{
    int n,c;
    cin>>n>>c;
    Student stu[n];
    for(int i=0;i<n;i++)
    {
        cin>>stu[i];
    }
    bool (*fun[3])(const Student&,const Student&)={cmp1,cmp2,cmp3};	//定义一个函数数组
    sort(stu,stu+n,*fun[--c]);
    for(int i=0;i<n;i++)
    {
        cout<<stu[i]<<endl;
    }
    return 0;
}
