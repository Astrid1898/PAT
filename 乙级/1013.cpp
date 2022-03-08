#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int i=2,j,cnt=0;
    bool isnum=false;
    while(cnt!=n)
    {
        isnum=true;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                isnum=false;
                break;
            }
        }
        if(isnum)
        {
            cnt++;
            if(cnt>=m&&cnt<n&&(cnt-m+1)%10!=0)
                cout<<i<<" ";
            else if(cnt>=m&&cnt<n&&(cnt-m+1)%10==0)
                cout<<i<<endl;
            else if(cnt==n)
                cout<<i;
        }
        i++;
    }
    return 0;
}
