#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int m,n,s;
    cin>>m>>n>>s;
    string str;
    vector<string> winner;
	int sign=1;
    for(int i=1;i<=m;i++)
    {	
        cin>>str;
        if(((i-s)%n==0&&(i-s)>=0)||sign==0)
        {
			for(int j=0;j<winner.size();j++)
            {
            	if(winner[j]==str&&winner[j].size()==str.size())
				{
					sign=0;
					s=i;
					break;
				}
				sign=1;
			}
			if(sign)
				winner.push_back(str);
        }
    }
    if(winner.size()==0)
        cout<<"Keep going...";
    else
    {
        for(int i=0;i<winner.size();i++)
            cout<<winner[i]<<endl;
    }
    return 0;
}
