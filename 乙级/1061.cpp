#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int score[m];
    unsigned int right_ans[m];
    for(int i=0;i<m;i++)
        cin>>score[i];
    for(int i=0;i<m;i++)
        cin>>right_ans[i];
    unsigned int stu_ans[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>stu_ans[i][j];
    }
    for(int i=0;i<n;i++)
    {
        int temp=0;
        for(int j=0;j<m;j++)
        {
            if(stu_ans[i][j]==right_ans[j])
                temp+=score[j];
        }
        cout<<temp<<endl;
    }
    return 0;
}
