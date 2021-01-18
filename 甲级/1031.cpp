/*简单的打印字符串的问题
*只要推出n1,n2,n3和n关系，很好写出程序*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    cin>>str;
    int n1=0,n2=0,n3=0;
    n1=n2=(str.size()+2)/3;
    n3=(str.size()+2)-2*n1;
    int i=0;
    for(;i<n1-1;i++)
    {
        cout<<str[i];
        for(int j=0;j<n3-2;j++)
        {
            cout<<' ';
        }
        cout<<str[str.size()-1-i]<<endl;
    }
    for(int j=0;j<n3;j++)
    {
        cout<<str[i+j];
    }
    return 0;
}
