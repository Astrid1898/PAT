#include<iostream>
#include<cctype>
#include<cstdio>
using namespace std;
int main()
{
    char c;
    int aplha[26]={0},b[2]={0,0};
    while((c=toupper(getchar()))!='\n')
    {
        if(c-'A'>=0&&c-'A'<=25)
            aplha[int (c-'A')]++;
    }
    for(int i=0;i<26;i++)
    {
        if(b[0]<aplha[i])
        {
            b[0]=aplha[i];
            b[1]=i;
        }
    }        
    cout<<char('a'+b[1])<<' '<<b[0];
    return 0;
}
