/*
本来觉得这样累加不行会超时，得改成logN复杂度的两两相加，但是竟然
全A了，应该没有数据特别多的测试点
*/
#include<iostream>
#include<vector>
using namespace std;
long long gcd(long long x,long long y); //返回x，y的最大公约数
class rationalNum   //无理数类
{
public:
    rationalNum():numerator(0),denominator(1){} //将分母初始化1，分母不能为0;
    void setValue(long long  x,long long y)
    {
        numerator=x;
        denominator=y;
    }
    friend long long gcd(long long x,long long y);  //声明gcd函数为友元函数
    friend ostream &operator<<(ostream &output,rationalNum &r); //定于无理数的输出
    rationalNum operator+(const rationalNum&a); 定义无理数之间的加法
private:
    long long numerator;    //分子，因为结果可能超过long，定义为long long
    long long denominator;  //分母
};
int main()
{
    int n;
    cin>>n;
    vector<rationalNum> num(n);
    rationalNum sum;
    for(int i=0;i<n;i++)
    {
        long long x,y;
        scanf("%lld/%lld",&x,&y);
        num[i].setValue(x,y);
        sum=sum+num[i]; //累加
    }
    cout<<sum<<endl;
    return 0;
}
ostream &operator<<(ostream &output,rationalNum &r)
{
    if(r.numerator==0)  //分子为0,直接输出0;
    {
        output<<0;
        return output;
    }
    if(r.denominator==1)    //结果为整数，直接输出整数
    {
        output<<r.numerator;
        return output;
    }
    long long divisor=r.numerator/r.denominator;
    long long remainder=r.numerator-divisor*r.denominator;
    if(divisor)
    {
        output<<divisor<<" ";
    }
    output<<remainder<<"/"<<r.denominator;
    return output;
}
long long gcd(long long x,long long y)     //辗转相除法，用另一种无法处理负数
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}
rationalNum rationalNum::operator+(const rationalNum&a)
{
    long long tmp=gcd(this->denominator,a.denominator);
    rationalNum r;
    long long newDenominator=this->denominator/tmp*a.denominator;
    long long newNumerator=this->numerator*(newDenominator/this->denominator)+a.numerator*(newDenominator/a.denominator);
    long long g=gcd(newNumerator,newDenominator);
    r.setValue(newNumerator/g,newDenominator/g);    //化简后的值，整数都变为n/1的形式
    return r;
}
