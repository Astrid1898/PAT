#include<iostream>
#include<string>
using namespace std;
bool is_number(char& c)
{
    if(c>='0'&&c<='9')
        return true;
    return false;
}
bool is_alpha(char &c)
{
    if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
        return true;
    return false;
}
bool is_dots(char &c)
{
    if(c=='.')
        return true;
    return false;
}
void check_the_pw(string &str)
{
    int num_sign=0;
    int alp_sign=0;
    if(str.size()<6)
    {
        cout<<"Your password is tai duan le."<<endl;
        return;
    }
    for(char c:str)
    {
        if(is_number(c))
            num_sign=1;
        else if(is_alpha(c))
            alp_sign=1;
        else if(is_dots(c));
        else
        {
            cout<<"Your password is tai luan le."<<endl;
            return;
        }
    }
    if(!num_sign)
        cout<<"Your password needs shu zi."<<endl;
    else if(!alp_sign)
        cout<<"Your password needs zi mu."<<endl;
    else
        cout<<"Your password is wan mei."<<endl;
}
int main()
{
    int n;
    cin>>n;
    getchar();
    for(int i=0;i<n;i++)
    {
        string str;
        getline(cin,str);
        check_the_pw(str);
    }
    return 0;
}
