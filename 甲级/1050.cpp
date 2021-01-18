/*用STL中的map就能轻松解决*/

#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    string s1;
    getline(cin,s1); //读入s1;
    char c;
    map<char,int> mp;
    while(1)
    {
        scanf("%c",&c);
        if(c=='\n')
        {
            break;
        }
        mp[c]++;	//将s2中的元素记录在mp中
    }
    for(int i=0;i<s1.size();i++)
    {
        if(mp.count(s1[i]))
        {
            continue;	//若s2中出现了该元素，就不输出
        }	
        cout<<s1[i];
    }
    return 0;
}
