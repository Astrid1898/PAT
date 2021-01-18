/*
2020年的第一个代码，长时间不写。逻辑已经开始混乱了
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a;
    cin>>a;
    int integerPortion,sign=1,exponent=0;
    string fractionalPortion;
    if(a[0]=='-')
        cout<<'-';
    integerPortion=int(a[1]-'0');
    int i=3;
    for(;i<a.size();i++)
    {
        if(a[i]!='E')
            fractionalPortion.push_back(a[i]);
        else
            break;
    }
    if(a[++i]=='-')
        sign=0;
    i++;
    for(;i<a.size();i++)
    {
        exponent=exponent*10+int(a[i]-'0');
    }
    if(sign)
    {
        cout<<integerPortion;
        int j=0;
        for(;j<exponent;j++)
        {
            if(j<fractionalPortion.size())
            {
                cout<<fractionalPortion[j];
            }
            else
            {
                cout<<"0";
            }
        }
        if(j<fractionalPortion.size())
        {
            cout<<'.';
            for(;j<
            fractionalPortion.size();j++)
            {
                cout<<fractionalPortion[j];
            }
        }
        cout<<endl;
    }
    else
    {
        int flag=1;
        for(int k=0;k<exponent;k++)
        {
            cout<<'0';
            if(flag)
            {
                cout<<'.';
                flag=0;
            }
        }
        if(exponent==0)
        {
            cout<<integerPortion<<'.';
        }
        else
        {
            cout<<integerPortion;
        }
        cout<<fractionalPortion<<endl;
    }
    return 0;
}
