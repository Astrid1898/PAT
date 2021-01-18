/*这道题也不难，构造个sting类乘2的函数，再判断数字是否一样就好了
*没什么复杂的数据结构和算法*/

#include<iostream>
#include<string>
using namespace std;
string doubleTheNum(const string &num);	//对num乘2的函数，返回string类结果
bool isAnotherPermutation(const string &num,const string &douNum); //判断num与dounum是否同一数列的排列组合
int main()
{
    string num;
    cin>>num;
    string douNum=doubleTheNum(num);
    if(isAnotherPermutation(num,douNum))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    cout<<douNum;
    return 0;
}
string doubleTheNum(const string &num)
{
    int up=0;	//保存进制
    string ans;
    for(int i=num.size()-1;i>=0;i--)
    {
        int tmp=num[i]-'0';
        tmp=tmp*2+up;	
        up=tmp/10;
        tmp=tmp-10*up;	//避免用时较久的取余运算
        ans=char(tmp+'0')+ans;
    }
    if(up)
    {
        ans=char(up+'0')+ans;
    }
    return ans;
}
bool isAnotherPermutation(const string &num,const string &douNum)
{
    int sizeNum=num.size(),sizeDouNum=douNum.size();
    if(sizeNum!=sizeDouNum)
    {
        return false;
    }
    else
    {
        int a[10]={0},b[10]={0};	//统计两个数字各位上0-9出现的次数
        for(int i=0;i<sizeNum;i++)
        {
            a[(num[i]-'0')]++;
            b[(douNum[i]-'0')]++;
        }
        for(int i=0;i<9;i++)
        {
            if(a[i]!=b[i])
            {
                return false;
            }
        }
    }
    return true;
}
