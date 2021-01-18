#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cin.get();
    string zerototw[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
    string gaowei[13]={" ","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
    string num[n]={""};
    string num1[n]={""};
    for(int i=0;i<n;i++)
    {
        getline(cin,num[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(num[i][0]-'0'>=0&&num[i][0]-'0'<=9)
        {   
            int earth_num=0;
            for(int j=0;j<num[i].size();j++)
            {	
		int temp=0;
                temp=num[i][j]-'0';
		earth_num=earth_num*10+temp;
		
            }
            int shang=earth_num/13;
            int yushu=earth_num%13;
            if(shang!=0)
            {
                num1[i]+=gaowei[shang];
		if(yushu!=0)
     		{
		    num1[i].push_back(' ');
                    num1[i]+=zerototw[yushu];
		}
            }
            else
            {
                num1[i]+=zerototw[yushu];
            }
        }
        else
        {
            int earth_num=0;
            for(int k=1;k<13;k++)
            {
                if((num[i].find(gaowei[k]))!=string::npos)
                {
                    earth_num+=13*k;
                    break;
                }
            }
            for(int k=0;k<13;k++)
            {
                if((num[i].find(zerototw[k]))!=string::npos)
                {
                    earth_num+=k;
                    break;
                }
            }
	    num1[i]+=(to_string(earth_num));
        }
    }
    for(int i=0;i<n;i++)
        cout<<num1[i]<<endl;
    return 0;
}
