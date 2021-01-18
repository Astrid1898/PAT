/*这道题目比较简单，做起来也没啥曲折的，直接AC了，应该是走出劝退区了吧
*就是进制转换和简单的Palindromic判断，用两个函数来实现就可以了
*一开始以为超出了int范围，还计划用string，卡在了进制转换上
后来用计算器一算，没有超过范围，顺利通过*/

#include<iostream>
#include<vector>
using namespace std;

//传入一个十进制数和进制以及一个容器，将十进制数转换为指定进制后放入容器中
void toBBase(const int&,const int&,vector<int>&);

//判断是否为Palindromic，比较简单，可以内联
inline bool isPalindromic(const vector<int>&);
int main()
{
    int n,b;
    cin>>n>>b;
    vector<int> bBaseNum;
    toBBase(n,b,bBaseNum);
    if(isPalindromic(bBaseNum))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    cout<<bBaseNum[0];
    for(int i=1;i<bBaseNum.size();i++)
    {
        cout<<' '<<bBaseNum[i];
    }
    return 0;
}
void toBBase(const int& n,const int& b,vector<int>& bBaseNum)
{
    int tmp=n;
    while(tmp)
    {
        int quo=tmp/b;
        int remainder=tmp-quo*b;
        tmp=quo;
        bBaseNum.insert(bBaseNum.begin(),remainder);
    }
}
bool isPalindromic(const vector<int>& bBaseNum)
{
    int size=bBaseNum.size();
    for(int i=0;i<size/2;i++)
    {
        if(bBaseNum[i]!=bBaseNum[size-i-1])
            return false;
    }
    return true;
}
