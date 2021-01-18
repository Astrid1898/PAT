#include<iostream>
#include<string>
using namespace std;
int main()
{
    string pw;
    cin>>pw;
    int n;
    cin>>n;
    string us_pw;
    cin>>us_pw;
    int sign=1;
    while(n&&us_pw!="#")
    {
        if(pw==us_pw)
        {
            cout<<"Welcome in"<<endl;
            sign=0;
        }
        else
            cout<<"Wrong password: "<<us_pw<<endl;
        cin>>us_pw;
        n--;
    }
    if(us_pw!="#"&&n==0&&sign)
    {
        cout<<"Account locked"<<endl;
    }
    return 0;
}
