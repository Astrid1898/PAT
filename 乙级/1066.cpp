#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int m,n,a,b,x;
    cin>>m>>n>>a>>b>>x;
    int pixel[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            {
                cin>>pixel[i][j];
                if(a<=pixel[i][j]&&pixel[i][j]<=b)
                    pixel[i][j]=x;
            }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<setw(3)<<setfill('0')<<pixel[i][j];
            if(j!=(n-1))
                cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}
