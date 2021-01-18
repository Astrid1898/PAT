#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    string str_n;
    int n[4]={0,0,0,0};
    int d=0,x=0,cha=0;
    cin>>str_n;
    int len=str_n.length();
    for(int i=0;i<len;i++)
        {
            n[4-len+i]=str_n[i]-'0';
        }
    if(n[0]==n[1]&&n[2]==n[3]&&n[1]==n[2])
    {
        cout<<str_n<<" - "<<str_n<<" = "<<"0000";
    }
    else
    { 
        while(cha!=6174)
        {
            sort(n,n+4,greater<int>());
            for(int i=0;i<len;i++)
            {
                d=10*d+n[i];
                x=10*x+n[3-i];
            }
            cha=d-x;
            cout<<setw(4)<<setfill('0')<<d<<" - "<<setw(4)<<setfill('0')<<x<<" = "<<setw(4)<<setfill('0')<<cha<<endl;
            n[3]=cha%10;
            n[2]=(cha/10)%10;
            n[1]=(cha/100)%10;
            n[0]=(cha/1000)%10;
            d=0;
            x=0;
        }
    }
    return 0;
}
