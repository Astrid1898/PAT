/*这道题目想了很久还是不能有效解决，看了答案方法是如此简单
*关键是要解决好完全二叉树的先序转层序的问题，并且对于完全二叉
*搜索树来说排序的节点就是其中序遍历*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> key,level;
int n,cnt=0;
void inToLevel(int index)	//完全二叉树的中序转层序
{
    if(index>n)
        return;
    inToLevel(index*2);
    level[index]=key[cnt++];
    inToLevel(index*2+1);
}
int main()
{
    cin>>n;
    key.resize(n);level.resize(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>key[i];
    }
    sort(key.begin(),key.end());	//排序得出中序遍历
    inToLevel(1);
    cout<<level[1];
    for(int i=2;i<=n;i++)
    {
        cout<<" "<<level[i];
    }
    cout<<endl;
    return 0;
}
