#include<iostream>
#include<cmath>
using namespace std;
void print_rectangle(int chang,int kuan,char tuxing)
{
    for(int i=0;i<chang;i++)
        cout<<tuxing;
    cout<<endl;
    for(int i=1;i<kuan-1;i++)
    {   
        cout<<tuxing;
        for(int j=1;j<chang-1;j++)
            cout<<' ';
        cout<<tuxing<<endl;
    }
    for(int i=0;i<chang;i++)
        cout<<tuxing;
}
int main()
{
    int chang;
    char tuxing;
    cin>>chang>>tuxing;
    int kuan;
    kuan=round(double(chang)/2.0);
    print_rectangle(chang,kuan,tuxing);
    return 0;
}
