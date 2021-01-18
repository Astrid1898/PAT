#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int p=0,a=0,t=0,e=0,s=0,T=0;
    char c;
    while((c=getchar())!='\n')
    {
        if(c=='P')
            p++;
        else if(c=='A')
            a++;
        else if(c=='T')
            t++;
        else if(c=='e')
            e++;
        else if(c=='s')
            s++;
        else if(c=='t')
            T++;
    }
    while(p!=0||a!=0||t!=0||e!=0||s!=0||T!=0)
	{
        if(p!=0)
        {
            cout<<'P';
            p--;
        }
        if(a!=0)
        {
            cout<<'A';
            a--;
        }
        if(t!=0)
        {
            cout<<'T';
            t--;
        }
        if(e!=0)
        {
            cout<<'e';
            e--;
        }
        if(s!=0)
        {
            cout<<'s';
            s--;
        }
        if(T!=0)
        {
            cout<<'t';
            T--;
        }
    }
    return 0;
}
