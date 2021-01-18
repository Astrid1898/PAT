/*
难度在于零的处理
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string str;
    cin>>str;
    vector<string> chinese={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    if(str[0]=='-') //检查负号
    {
        cout<<"Fu ";
        str.erase(0,1);
    }
    int sign=0,flag=0;  //sign作为零出现的标志，flag作为应该使用单位的标志
    int digit=str.size();
    if(digit==1&&str[0]=='0')   //若输入0,需要单独处理
    {
        cout<<"ling"<<endl;
        return 0;
    }
    int divisor=digit/4;int reminder=digit-4*divisor;
    for(int i=0;i<digit-1;i++)  //最后一位需要单独处理，因为最后一位的零往往不读出
    {
        if(reminder==0)
        {
            if(divisor==1&&flag)
            {
                cout<<" Wan";
                flag=0;
            }
            if(divisor==2&&flag)
            {
                cout<<" Yi";
                flag=0;
            }
            divisor--;
            reminder=4;
        }
        int index=stoi(str.substr(i,1));
        if(index==0)    //出现零就置位
        {
            sign=1;
        }
        else
        {
            if(sign)    //中间出现多个零只读一个，所以在这里输出
            {
                cout<<" ling";
                sign=0;
            }
            flag=1;
            if(i)
                cout<<" "<<chinese[index];
            else
                cout<<chinese[index];
            if(reminder==4)
                cout<<" Qian";
            else if(reminder==3)
                cout<<" Bai";
            else if(reminder==2)
                cout<<" Shi";
        }
        reminder--;
    }
    int index=stoi(str.substr(digit-1,1));
    if(index)
    {
        if(sign)
        {
            cout<<" ling";
            sign=0;
        }
        cout<<" "<<chinese[index];
    }
    cout<<endl;
    return 0;
}
