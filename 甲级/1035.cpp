/*这道题目很简单，硬算就是了*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<string,string>> accounts;
    for(int i=0;i<n;i++)
    {
        string name,passwd;
        int sign=0;
        cin>>name>>passwd;
        for(int i=0;i<passwd.size();i++)
        {
            switch(passwd[i])
            {
                case '1':
                {
                    passwd[i]='@';
                    sign=1;
                    break;
                }
                case '0':
                {
                    passwd[i]='%';
                    sign=1;
                    break;
                }
                case 'l':
                {
                    passwd[i]='L';
                    sign=1;
                    break;
                }
                case 'O':
                {
                    passwd[i]='o';
                    sign=1;
                    break;
                }
                default:
                {
                }
            }
        }
        if(sign)
        accounts.push_back(make_pair(name,passwd));
    }
    if(accounts.size())
    {
        cout<<accounts.size()<<endl;
        for(int i=0;i<accounts.size();i++)
        {
            cout<<accounts[i].first<<" "<<accounts[i].second<<endl;
        }
    }
    else
    {
        if(n==1)
        {
            cout<<"There is 1 account and no account is modified"<<endl;
        }
        else
        {
            cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
        }
    }
    return 0;
}
