#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string itochar(int result,int d);
int main()
{
    int a,b,d,result;
    cin>>a>>b>>d;
    result=a+b;
    cout<<itochar(result,d);
    return 0;
}
string itochar(int result,int d)
{
    string Result="";
    do
    {
        int t=result%d;
        Result+=t+'0';
        result=result/d;
    }
    while(result);
    reverse(Result.begin(),Result.end());
    return Result;
}

