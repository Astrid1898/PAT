/*终于全部AC了，这题目真变态，一堆坑点*/
/*
首先是范围的确定，下限显然是未知进制数组的最大数字加1,但上限却不那么显然。一个很好想到的上限应该是已知数字，但必须得考虑这又可能小于下限
数据类型要选择long long，不然转化为10进制会溢出
即使选择了long long的类型，中间也有步骤可能溢出，要处理好
采用二分法，不然会超时
*/
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
long long to_decimal(string* p,long long r) //将r进制的p转化为10进制
{
    long long ans=0;
	long long temp,e=1;
    for(int i=(*p).size()-1;i>=0;i--)
    {
        if((*p)[i]<='9'&&(*p)[i]>='0')
        {
            temp=(*p)[i]-'0';
        }
        else if((*p)[i]<='z'&&(*p)[i]>='a')
        {
            temp=(*p)[i]-'a'+10;
        }
        ans+=e*temp;
        e=e*r;
    }
    return ans;
}
int find_max(string* p) //找到进制下限
{
    char min_char='0';
    for(int i=0;i<(*p).size();i++)
    {
        if((*p)[i]>min_char)
        {
            min_char=(*p)[i];
        }
    }
    if(min_char<='9'&&min_char>='0')
    {
        return int(min_char-'0')+1;
    }
    else if(min_char>='a'&&min_char<='z')
    {
        return int(min_char-'a')+11;
    }
}
int main()
{
    string n1,n2;
    int tag,radix,sign=0;
    cin>>n1>>n2>>tag>>radix;
    string* p1=&n1;
    string* p2=&n2;
    if(tag==2)
    {
        swap(p1,p2); //始终将p2设置为未知进制，便于编写程序
    }
    long long i=find_max(p2);
    long long  t_p1=to_decimal(p1,radix);
    long long low=i,high=t_p1;
    if(high<i)
        high=i;	//这里是个坑点
    while(high>=low)
    {
        long long mid=(high+low)>>1;
        long long t_p2=to_decimal(p2,mid);
        if(t_p1==t_p2)
        {
            sign=1;
            i=mid;
            break;
        }
        else if(t_p1<t_p2||t_p2<0) //这里是个深坑，处理溢出情况
        {
            high=mid-1;
        }
        else if(t_p1>t_p2)
        {
            low=mid+1;
        }
    }
    if(sign)
    {
        cout<<i<<endl;
    }
    else
    {
        cout<<"Impossible"<<endl;
    }
    return 0;
}
