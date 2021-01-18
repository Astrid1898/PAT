/*
*PAT考试后休息了几天，但是成绩不理想，从今天起继续刷题
*不过每天刷题时间将会减少，作为学习之余的娱乐，折腾了几天
*vs2019,但是觉得我需要的功能不必那么繁杂，而且实在不喜欢win
*下点点的操作和一堆弹窗，所以还是用终端里的g++方便
*这题目唯一要注意的是6747的时候也要运算一遍，用一个do while就好
*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string calculate(const string &str)
{
    string num1=str,num2=str;
    sort(num1.begin(),num1.end(),greater<int>{});
    sort(num2.begin(),num2.end());
    int ans=stoi(num1)-stoi(num2);
    string s=to_string(ans);
    while(s.size()<4)
    {
        s='0'+s;
    }
    cout<<num1<<" - "<<num2<<" = "<<s<<endl;
    return s;
}
int main()
{
    string num;
    cin>>num;
    while(num.size()<4)
    {
        num='0'+num;
    }
    if(num[0]==num[1]&&num[2]==num[3]&&num[1]==num[3])
    {
        cout<<num<<" - "<<num<<" = 0000"<<endl;
        return 0;
    }
    do
    {
        num=calculate(num);
    }
    while(num!="6174");
    return 0;
}
