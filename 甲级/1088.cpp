/*
题目描述很简单，实际些起来有很多细节要考虑
*/
#include<iostream>
using namespace std;
class rationalNum   //定义一个有理数类
{
public:
    rationalNum(long long x,long long y):numerator(x),denominator(y),inergerPart(0),sign(false){}
    friend ostream &operator<<(ostream &output,rationalNum &r);
    friend long long gcd(long long x,long long y);  //辗转相除法求最大公约数
    void simplify();    //化简
    rationalNum operator+(const rationalNum &r);
    rationalNum operator-(const rationalNum &r);
    rationalNum operator*(const rationalNum &r);
    rationalNum operator/(rationalNum &r);
private:
    long long numerator;
    long long denominator;
    long long inergerPart;  //整数部分
    bool sign;  //标志是否为负数
};
int main()
{
    long long x,y;
    scanf("%lld/%lld",&x,&y);
    rationalNum num1(x,y);
    scanf("%lld/%lld",&x,&y);
    rationalNum num2(x,y);
    rationalNum sum=num1+num2,diff=num1-num2;
    rationalNum pro=num1*num2,quo=num1/num2;
    num1.simplify();num2.simplify();sum.simplify();diff.simplify();
    pro.simplify();quo.simplify();
    cout<<num1<<" + "<<num2<<" = "<<sum<<endl;
    cout<<num1<<" - "<<num2<<" = "<<diff<<endl;
    cout<<num1<<" * "<<num2<<" = "<<pro<<endl;
    cout<<num1<<" / "<<num2<<" = "<<quo<<endl;
    return 0;
}
ostream &operator<<(ostream &output,rationalNum &r)
{
    if(r.sign)  //若是负数，就加括号
        output<<"(";
    if(r.inergerPart)   //整数部分不为零，分数部分为零的话分数部分就不必输出
    {
        output<<r.inergerPart;
        if(r.numerator!=0)
            output<<" "<<r.numerator<<"/"<<r.denominator;
    }
    else
    {
        if(r.denominator==0)    //分母为零，无穷大
            output<<"Inf";
        else if(r.numerator==0) //整数分数都是零，直接输出0;
            output<<0;
        else
            output<<r.numerator<<"/"<<r.denominator;
    }
    if(r.sign)
        output<<")";
    return output;
}
long long gcd(long long x,long long y)
{
    if(y==0)
        return x;
    return gcd(y,x%y);
}
void rationalNum::simplify()
{
    if(numerator<0) //判断是否为负数
    {
        sign=true;
    }
    if(denominator==0)
        return;
    inergerPart=numerator/denominator;
    numerator=numerator-inergerPart*denominator;
    long long tmp=gcd(numerator,denominator);
    if(inergerPart<0)   //整数部分小于零，分数部分不必带符号
    {
        numerator=abs(numerator/tmp);
        denominator=abs(denominator/tmp);
    }
    else    //否则需要保留分数部分符号
    {
        tmp=abs(tmp);
        numerator=numerator/tmp;
        denominator=denominator/tmp;
    }
}
rationalNum rationalNum::operator+(const rationalNum &r)
{
    long long tmp=gcd(this->denominator,r.denominator);
    long long ansDenominator=this->denominator/tmp*r.denominator;
    long long ansNumerator=this->numerator*(ansDenominator/this->denominator)+r.numerator*(ansDenominator/r.denominator);
    return rationalNum(ansNumerator,ansDenominator);
}
rationalNum rationalNum::operator-(const rationalNum &r)
{
    long long tmp=gcd(this->denominator,r.denominator);
    long long ansDenominator=this->denominator/tmp*r.denominator;
    long long ansNumerator=this->numerator*(ansDenominator/this->denominator)-r.numerator*(ansDenominator/r.denominator);
    return rationalNum(ansNumerator,ansDenominator);
}
rationalNum rationalNum::operator*(const rationalNum &r)
{
    long long ansNumerator=this->numerator*r.numerator;
    long long ansDenominator=this->denominator*r.denominator;
    return rationalNum(ansNumerator,ansDenominator);
}
rationalNum rationalNum::operator/(rationalNum &r)
{
    int flag=0;
    if(r.numerator<0)
    {
        r.denominator=-r.denominator;
        r.numerator=-r.numerator;
        flag=1;
    }
    long long ansNumerator=this->numerator*r.denominator;
    long long ansDenominator=this->denominator*r.numerator;
    if(flag)
    {
        r.denominator=-r.denominator;
        r.numerator=-r.numerator;
    }
    return rationalNum(ansNumerator,ansDenominator);
}
