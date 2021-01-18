/*挺简单的一道题，PAT的难度分布可真不均衡啊*/
#include<iostream>
#include<string>
using namespace std;
string toMars(int);	//转换为13进制，注意是固定两位
int main()
{
    int int_r,int_g,int_b;
    cin>>int_r>>int_g>>int_b;
    string marsR=toMars(int_r);
    string marsG=toMars(int_g);
    string marsB=toMars(int_b);
    cout<<"#"<<marsR<<marsG<<marsB<<endl;
    return 0;
}
string toMars(int a)	
{
    string ans;
    int quo=a/13;
    int rem=a-13*quo;
    switch(rem)
    {
        case 10:
            ans='A'+ans;
            break;
        case 11:
            ans="B"+ans;
            break;
        case 12:
            ans="C"+ans;
            break;
        default:
            ans=char(rem+'0')+ans;
    }
    a=quo;
    quo=a/13;
	cout<<"quo="<<quo<<endl;
    rem=a-13*quo;
    switch(rem)
    {
        case 10:
            ans='A'+ans;
            break;
        case 11:
            ans="B"+ans;
            break;
        case 12:
            ans="C"+ans;
            break;
        default:
            ans=char(rem+'0')+ans;
    }
    return ans;
}
