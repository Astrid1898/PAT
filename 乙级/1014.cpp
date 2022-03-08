#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    string c1,c2,c3,c4;
    string week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    cin>>c1>>c2>>c3>>c4;
    int f1=0;
    for(int i=0;i<c1.length();i++)
    {
        if(c1[i]==c2[i]&&c1[i]-'A'>=0&&c1[i]-'A'<=6&&f1==0)
        {
            cout<<week[c1[i]-'A']<<" ";
            f1=1;
            i++;
        }
        if(c1[i]==c2[i]&&c1[i]-'0'>=0&&c1[i]-'0'<=9&&f1==1)
        {
            cout<<setw(2)<<setfill('0')<<c1[i]-'0';
            cout<<":";
            break;
        }
        if(c1[i]==c2[i]&&c1[i]-'A'>=0&&c1[i]-'A'<=13&&f1==1)
        {
            cout<<c1[i]-'A'+10;
            cout<<":";
            break;
        }
    }
        for(int i=0;i<c3.length();i++)
        {
            if(c3[i]==c4[i]&&isalpha(c3[i]))
            {
                cout<<setw(2)<<setfill('0')<<i;
                break;
            }
        }

    return 0;
}
