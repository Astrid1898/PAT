/*
之前做过，最简单的莫过于暴力查找，但这次换了一种算法，以线性时间复杂度运行。
网上还有另一种简洁的做法，用map记录typed字符串，然后在map中查找原始数据，
虽然代码很短，但是时间复杂度介于这两种算法之间。
*/
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
    string origin,typedOut,wornOutKey;
    cin>>origin>>typedOut;
    string::iterator iter1=origin.begin();
    string::iterator iter2=typedOut.begin();
    map<char,int > mp;  //记录坏键
    char tmp;
    for(;iter2!=typedOut.end();iter2++) //遍历typedOut，找出坏键
    {
        while(*iter1!=*iter2)
        {
            tmp=toupper(*iter1);
            if(mp.count(tmp)==0)
            {
                wornOutKey=wornOutKey+tmp;
                mp[tmp]++;
            }
            iter1++;
        }
        iter1++;
    }
    while(iter1!=origin.end())  //origin多出的都是坏键
    {
        tmp=toupper(*iter1);
        if(mp.count(tmp)==0)
        {
            wornOutKey=wornOutKey+tmp;
            mp[tmp]++;
        }
        iter1++;
    }
    cout<<wornOutKey<<endl;
    return 0;
}
