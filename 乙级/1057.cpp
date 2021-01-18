#include<iostream>
#include<string>
using namespace std;
int get_the_sum(string& str)
{
    int result=0;
    for(int i=0;i<str.size();i++)
    {
        str[i]=tolower(str[i]);
        int temp=str[i]-'a'+1;
        if(temp>=1&&temp<=26)
            result+=temp;
    }
    return result;
}
int* get_binary_cont(int sum)
{
    static int p[2]={0};
    while(sum)
    {
        int quo=sum/2;
        int rem=sum%2;
        if(rem==1)
            p[1]++;
        else 
            p[0]++;
        sum=quo;
    }
    //p[0]++;
    return p;
}
int main()
{
    string str;
    getline(cin,str);
    int sum=get_the_sum(str);
    int* p;
    p=get_binary_cont(sum);
    cout<<*p<<' '<<*(p+1);
    return 0;
}
