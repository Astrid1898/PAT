#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string get_the_plus(string& hexadecimal_table,string& number1,string& number2)
{
    string ans;
    int table_len=hexadecimal_table.size();
    int num1_len=number1.size();
    int num2_len=number2.size();
    int sign=0;
    int min_len=num1_len>num2_len? num2_len:num1_len;
    int sum=0;
    for(int i=0;i<min_len;i++)
    {
        int num1=number1[i]-'0';
        int num2=number2[i]-'0';
        int hex=hexadecimal_table[i]-'0';
        if(hex==0)
            hex=10;
        sum=num1+num2+sign;
        sign=sum/hex;
        sum=sum%hex;
        ans.push_back(sum+'0');
    }
    for(int i=min_len;i<num1_len;i++)
    {
        int hex=hexadecimal_table[i]-'0';
        if(hex==0)
            hex=10;
        sum=number1[i]-'0'+sign;
        sum=sum%hex;
        sign=sum/hex;
        ans.push_back(sum+'0');
    }
    for(int i=min_len;i<num2_len;i++)
    {
        int hex=hexadecimal_table[i]-'0';
        if(hex==0)
            hex=10;
        sum=number2[i]-'0'+sign;
        sum=sum%hex;
        sign=sum/hex;
        ans.push_back(sum+'0');
    }
    if(sign)
    {
        sum=sign;
        ans.push_back(sum+'0');
    }

    return ans;
}
int main()
{
    string hexadecimal_table;
    cin>>hexadecimal_table;
    string number1,number2;
    cin>>number1>>number2;
    reverse(number1.begin(),number1.end());
    reverse(number2.begin(),number2.end());
    reverse(hexadecimal_table.begin(),hexadecimal_table.end());
    string ans=get_the_plus(hexadecimal_table,number1,number2);
    reverse(ans.begin(),ans.end());
    int sign=1;
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]-'0'==0&&sign);
        else
        {
            cout<<ans[i];
            sign=0;
        }
        if(!sign&&i==ans.size()-1)
            cout<<endl;
    }
    if(sign)
        cout<<0<<endl;
    return 0;
}
