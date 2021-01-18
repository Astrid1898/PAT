/*这道题目分的情况略复杂，逻辑要好，不然会发生混乱，我一开始就是这样*/

#include<iostream>
#include<string>
using namespace std;
int sigNum(const string &s)	//找到指数
{
    int dotIndex=s.find('.');
    if(dotIndex==string::npos)
    {
        dotIndex=s.size();
    }
    int i;	//找到第一个有效数字位数

/*这里有一个语法问题，前面已经声明了i，在for里面不能再声明i，否则for中
*使用的将是新声明的局部变量i，在返回后i信息将丢失，卡在了这里很久*/

    for(i=0;i<s.size()&&(s[i]=='0'||s[i]=='.');i++);
    if(i<=dotIndex) return dotIndex-i;	//首位有效数字在小数点前
    else if(i==s.size()) return 0;
    else return dotIndex-i+1;	//处理指数为负情况
}
string split(const string &s,int n)
{
    string ans;
    ans.resize(n);	//要输出的n个有效数字
    int index1=0,index2=0;
    while(index1<n&&index2<s.size())
    {
        if(index1==0&&s[index2]=='0')	//略去开头的0
        {
            index2++;
        }
        else if(s[index2]=='.')	//略去小数点
        {
            index2++;
        }
        else
        {
            ans[index1++]=s[index2++];
        }
    }
    while(index1<n)
    {
        ans[index1++]='0';	//不够n位则补上0;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int siga=sigNum(a),sigb=sigNum(b);
    string ans1=split(a,n),ans2=split(b,n);
    if(siga==sigb&&ans1==ans2)
    {
        cout<<"YES 0.";
        cout<<ans1<<"*10^"<<siga<<endl;
    }
    else
    {
        cout<<"NO ";
        cout<<"0."<<ans1<<"*10^"<<siga<<" 0."<<ans2<<"*10^"<<sigb<<endl;
    }
    return 0;
}
