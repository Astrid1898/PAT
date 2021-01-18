#include<iostream>
#include<string>
using namespace std;
bool is_allowed(string str);
int main()
{
    int flag=1;
    int n;
    cin>>n;
    string id_number[n];
    for(int i=0;i<n;i++)
    {
        cin>>id_number[i];
        if(!is_allowed(id_number[i]))
            {
                flag=0;
                cout<<id_number[i]<<endl;
            }
    }
    if(flag)
        cout<<"All passed";
    return 0;
}
bool is_allowed(string str)
{
    int check=0;
    int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char m[11]={'1','0','X','9','8','7','6','5','4','3','2'};
    for(int i=0;i<17;i++)
    {
        if((str[i]-'0'>=0)&&(str[i]-'0'<=9))
            {
                check=(str[i]-'0')*(weight[i])+check;
            }
        else
            return false;
}
        check=check%11;
	cout<<m[check]<<endl;
        if(m[check]==str[17])
            return true;
        else
            return false;
}
