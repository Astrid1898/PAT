#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
bool is_legal_number(const string &);
int main()
{   
    double sum=0.0;
    int n;
    int cont=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string str_num;
        cin>>str_num;
        if(!is_legal_number(str_num))
            cout<<"ERROR: "<<str_num<<" is not a legal number"<<endl;
        else
        {
            cont++;
            sum+=stod(str_num,0);
        }
    }
    sum=sum/cont;
    if(cont==0)
        cout<<"The average of 0 numbers is Undefined";
    else
        cout<<"The average of "<<cont<<" numbers is "<<setiosflags(ios::fixed)<<setprecision(2)<<sum;
    return 0;
}
bool is_legal_number(const string & str)
{   
    int sign=0;
    double d_num=0;
    int len=0;
    for(int i=0;i<str.size();i++)
    {	
        if(((str[i]-'0')>9||(str[i]-'0')<0)&&str[i]!='.'&&str[i]!='-')
            return false;
        if(str[i]=='-')
        {
            if(i!=0)
                return false;
            continue;
        }
        if(str[i]=='.')
        {
            if(i==0||i==str.size()-1)
                return false;
            sign++;
			continue;
        }
        if(sign==0)
        {
            d_num=d_num*10+(str[i]-'0');
        }
        else if(sign==1)
        {
            len++;

            d_num=d_num+(str[i]-'0')*(pow(0.1,len));
        }
        else 
            return false;
    }
    if(d_num>1000||len>2)
        return false;
	return true;
}
