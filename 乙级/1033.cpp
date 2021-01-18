#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
bool isAlpha(char a);
int main()
{
    string to_be_printed,bad_key;
    cin>>bad_key>>to_be_printed;
    int sign=1;
    if(bad_key.find('+')!=string::npos)
        sign=0;
    for(int i=0;i<to_be_printed.size();i++)
    {
        if(bad_key.find(toupper(to_be_printed[i]))==string::npos)
        {
            if(isAlpha(to_be_printed[i]))
            {
                if(sign)
                    cout<<to_be_printed[i];
            }
            else
                cout<<to_be_printed[i];
        }
    }
    return 0;
}
bool isAlpha(char a)
{
    if(a>='A'&&a<='Z')
        return true;
    else
        return false;
}
