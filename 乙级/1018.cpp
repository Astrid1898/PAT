#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char jia,yi;
    int jia_c=0,jia_j=0,jia_b=0,yi_c=0,yi_j=0,yi_b;
    int jia_win=0,yi_win=0;
    for(int i=0;i<n;i++)
    {
        cin>>jia>>yi;
        if(jia==yi);
        else if(jia=='C'&&yi=='J')
        {
            jia_win++;
            jia_c++;
        }
        else if(jia=='J'&&yi=='B')
        {
            jia_win++;
            jia_j++;
        }
        else if(jia=='B'&&yi=='C')
        {
            jia_win++;
            jia_b++;
        }
        else if(jia=='C'&&yi=='B')
        {
            yi_win++;
            yi_b++;
        }
        else if(jia=='J'&&yi=='C')
        {
            yi_win++;
            yi_c++;
        }
        else if(jia=='B'&&yi=='J')
        {
            yi_win++;
            yi_j++;
        }
    }
    cout<<jia_win<<" "<<n-jia_win-yi_win<<" "<<yi_win<<endl;
    cout<<yi_win<<" "<<n-jia_win-yi_win<<" "<<jia_win<<endl;
    if(jia_b>=jia_c&&jia_b>=jia_j)
        cout<<'B'<<" ";
    else if(jia_c>=jia_j)
        cout<<'C'<<" ";
    else
        cout<<'J'<<" ";
    if(yi_b>=yi_c&&yi_b>=yi_j)
        cout<<'B';
    else if(yi_c>=yi_j)
        cout<<'C';
    else
        cout<<'J';
    return 0;
}
