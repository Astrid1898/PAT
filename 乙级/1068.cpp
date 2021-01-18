#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int tol;
struct red
{
    int x;
    int y;
    int rgb;
};
void compare(int a,int b,int x1,int y1,int x2,int y2,int *res,int m)
{
    if(abs(a-b)<=tol)
        {
            *((int*)res+x1*m+y1)=1;
            *((int*)res+x2*m+y2)=1;
        }
}
int main()
{
    char* sign=new char[16777216];
    for(int i=0;i<16777216;i++)
        sign[i]='0';
    int m,n;
    cin>>m>>n>>tol;
	int pixel[n][m];
    int res[n][m]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>pixel[i][j];
            sign[pixel[i][j]]++;
            if(j>0)
            {
                compare(pixel[i][j-1],pixel[i][j],i,j-1,i,j,(int*) res,m);
            }
            if(i>0)
            {
                compare(pixel[i-1][j],pixel[i][j],i-1,j,i,j,(int*) res,m);
                if(j<m-1)
                    compare(pixel[i-1][j+1],pixel[i][j],i-1,j+1,i,j,(int*) res,m);
                if(j>0)
                    compare(pixel[i-1][j-1],pixel[i][j],i-1,j-1,i,j,(int*) res,m);
            }
        }
    }
    red temp;
    vector<red> reds;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(res[i][j]==0&&sign[pixel[i][j]]=='1')
            {
                temp.x=i+1;
                temp.y=j+1;
                temp.rgb=pixel[i][j];
                reds.push_back(temp);
            }
        }
    }
	delete[] sign;
    if(reds.size()==0)
        cout<<"Not Exist";
    else if(reds.size()>1)
        cout<<"Not Unique";
    else
        cout<<'('<<reds[0].y<<", "<<reds[0].x<<"): "<<reds[0].rgb;
    return 0;
}
