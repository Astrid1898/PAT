/*题目本身没有什么特别难得地方，但是用cin和cout的化
*最后一个测试点会超时，要用c风格的scanf和printf*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<string>> courses(k+1);
    for(int i=0;i<n;i++)
    {
        char ch[5];
        int c;
        scanf("%s %d",ch,&c);
        string str(ch);
        while(c--)
        {
            int tmp;
            cin>>tmp;
            courses[tmp].push_back(str);
        }
    }
    for(int i=1;i<courses.size();i++)
    {
        sort((courses[i]).begin(),courses[i].end());
        printf("%d %d\n",i,courses[i].size());
        for(int j=0;j<courses[i].size();j++)
        {
            printf("%s\n",courses[i][j].c_str());
        }
    }
    return 0;
}
