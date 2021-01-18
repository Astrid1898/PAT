/*昨晚写到太晚，没有睡好，所幸今天的这道题目很简单，知识犯了些语法上的错误*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> digits {"zero","one","two","three","four","five","six","seven","eight","nine"};//便于输出
inline string get_the_sum(const string& str)
{
    int sum=0;
    for(auto &s:str)
    {
        sum=sum+(s-'0');
    }
    return to_string(sum);	//这里返回string也是便于输出
}
inline void print_ans(const string &str)
{
    cout<<digits[str[0]-'0'];
    for(int i=1;i<str.size();i++)
    {
        cout<<' '<<digits[str[i]-'0'];
    }
    cout<<endl;
}
int main()
{
    string n;
    cin>>n;
    string ans(get_the_sum(n));
    print_ans(ans);
    return 0;
}
