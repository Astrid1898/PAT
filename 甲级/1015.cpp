/*比较简单的一道题，就是读懂题目费了点事，先把数字转成d进制*/
/*反转后转回十进制看是不是都是素数，就是进制转换和素数判断*/
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
bool isPrime(const int &n);
int reverseNum(int a,const int &d);
int toDecimal(const string &s,int d);
string toRadix(int &n,const int &d);
bool isReversiblePrime(const int &num,const int& d);
int main()
{
    while(1)
    {
        int n, d;
        cin>>n;
        if(n<0)
        {
            break;
        }
        else
        {
            cin>>d;
            if(isReversiblePrime(n,d))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}
bool isPrime(int &n)
{
    if(n<2)	//1不是素数
        return false;
    int sqrtN=sqrt(n);
    for(int i=2;i<=sqrtN;i++)
    {
        if((n/i)*i==n)
            return false;
    }
    return true;
}
int reverseNum(int a,const int &d)
{
    int tmp=a;
    string str=toRadix(tmp,d);
    reverse(str.begin(),str.end());
    return toDecimal(str,d);
}
int toDecimal(const string &s,int d)
{
    int sum=0;
    for(int i=0;i<s.size();i++)
    {
        int tmp=s[i]-'0';
        sum=sum*d+tmp;
    }
    return sum;
}
bool isReversiblePrime(const int &num,const int &d)
{
    int a=num;
    int b=reverseNum(a,d);
    if(isPrime(a)&&isPrime(b))
    {
        return true;
    }
    return false;
}
string toRadix(int &n,const int &d)
{
    string sum;
    if(!n)
    {
        sum.push_back('0');
        return sum;
    }
    while(n)
    {
        int tmp=n%d;
        sum=to_string(tmp)+sum;
        n=n/d;
    }
    return sum;
}
