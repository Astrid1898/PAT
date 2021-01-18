#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{   
    string str;
    cin>>str;
    int p=0,pa=0,pat=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='P')
        {
            p++;
        }
        if(str[i]=='A')
        {
            pa=pa+p;
        }
        if(str[i]=='T')
        {
            pat=pat+pa;
        }
    }
    pat=pat%1000000007;
    cout<<pat;
    return 0;
}
