#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int* the_matrix(int);
bool cmp(int a,int b)
{
    return a>b;
};
void print_the_matrix(int,int,int[],int);
int main()
{
    int n;
    cin>>n;
    int number[n];
    for(int i=0;i<n;i++)
    {
        cin>>number[i];
    }
    sort(number,number+n,cmp);
    int row,column;
    int *p;
    p=the_matrix(n);
    row=*p;
    column=*(p+1);
    print_the_matrix(row,column,number,n);
    return 0;
}
int * the_matrix(int cont)
{
    static int row_column[2];
    int s=sqrt(cont);
    if(s*s==cont)
    {
        row_column[0]=s;
        row_column[1]=s;
        return row_column;
    }
    else
    {
        do
        {
            s=s+1;
        }
        while(cont%s!=0);
        row_column[0]=s;
        row_column[1]=cont/s;
        return row_column;
    }
}
void print_the_matrix(int row,int column,int number[],int n)
{
    int t=0;
    int gra[row][column]={0};
    for(int i=0;i<row/2+row%2;i++)
    {
        for(int j=i;j<=column-1-i&&t<n;j++)
        {
            gra[i][j]=number[t++];
        }
        for(int k=i+1;k<=row-1-i&&t<n;k++)
        {
            gra[k][column-1-i]=number[t++];
        }
        for(int j=column-2-i;j>=i&&t<n;j--)
        {
            gra[row-1-i][j]=number[t++];
        }
        for(int k=row-2-i;k>=i+1&&t<n;k--)
        {
            gra[k][i]=number[t++];
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column-1;j++)
            cout<<gra[i][j]<<' ';
        cout<<gra[i][column-1]<<endl;
    }
}
