#include<iostream>
#include<string>
using namespace std;
int main()
{
    string sci_number,fl_num;
    cin>>sci_number;
    int num_sign=0,e_sign=0;
    int e_num=0;
    if(sci_number[0]=='+')
        num_sign=1;
    int int_num=sci_number[1]-'0';
    int i=3;
    for(i;i<sci_number.size();i++)
    {
        if(sci_number[i]!='E')
        {
            fl_num.push_back(sci_number[i]);
        }
        else
        {
            break;
        }
        
    }
    i++;
    if(sci_number[i]=='+')
        e_sign=1;
    i++;
    for(i;i<sci_number.size();i++)
    {
        e_num=sci_number[i]-'0'+e_num*10;
    }
    if(e_num==0)
    {
        if(!num_sign)
        {
            cout<<'-';
        }
        cout<<int_num<<'.'<<fl_num;
	return 0;
    }
    e_num--;
    if(!e_sign)
    {   
        if(!num_sign)
            cout<<'-';
        cout<<0<<'.';
        while(e_num)
        {
            cout<<0;
            e_num--;
        }
        cout<<int_num<<fl_num;
    }
    else
    {
	e_num++;
        if(!num_sign)
            cout<<'-';
        cout<<int_num;
        while(e_num)
        {
            if(fl_num.empty())
                cout<<0;
            else
            {
                cout<<fl_num[0];
                fl_num.erase(fl_num.begin());
            }
            e_num--;
        }
        int j=0;
        while(!fl_num.empty())
        {
            if(!j)
                cout<<'.';
            j++;
            cout<<fl_num[0];
            fl_num.erase(fl_num.begin());
        }
    }
    return 0;
}
