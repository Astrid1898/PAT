/*
暴力测试，每两个寻找相同后缀的个数，最后选最小的
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<string> spokenLine;  //存储句子
    spokenLine.resize(n);
    getchar();  //去除上一行句末的换行符
    for(int i=0;i<n;i++)
    {
        getline(cin,spokenLine[i]);
    }
    int suffixNum=10000;    //后缀字符数
    for(int i=1;i<n;i++)
    {
        int tmp=0;  //记录每两个的后缀字符数
        for(int j=1;j<=spokenLine[i].size();j++)
        {
            if(spokenLine[i-1][spokenLine[i-1].size()-j]==spokenLine[i][spokenLine[i].size()-j])
            {
                tmp=j;
            }
            else
                break;
        }
        if(tmp<suffixNum)
            suffixNum=tmp;  //只取最小的
    }
    if(suffixNum==0)
    {
        cout<<"nai"<<endl;
        return 0;
    }
    for(int i=suffixNum;i>0;i--)
    {
        cout<<spokenLine[0][spokenLine[0].size()-i];
    }
    cout<<endl;
    return 0;
}
