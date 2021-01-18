/*
实际上是给出先序遍历和中序遍历求后序遍历
*/
#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;
vector<int> inorderList,postorderList,preorderList;
int sign=1; //作为空格输出的标志
void inToPost(int root,int start,int end)   //root为先序中根节点位置，start和end为中序范围
{
    if(start>end)
        return;
    int i=start;
    while(i<end&&inorderList[i]!=preorderList[root]) i++;   //找到中序遍历中root的位置
    inToPost(root+1,start,i-1); //递归左子树
    inToPost(root+1+i-start,i+1,end);   //递归右子树
    if(sign)
    {
        cout<<preorderList[root];
        sign=0;
    }
    else
        cout<<" "<<preorderList[root];
}
int main()
{
    int n;
    cin>>n;
    stack<int> s;
    for(int i=0;i<2*n;i++)
    {
        string tmp;
        cin>>tmp;
        if(tmp=="Push")
        {
            int key;
            cin>>key;
            s.push(key);
            preorderList.push_back(key);
        }
        else
        {
            inorderList.push_back(s.top());
            s.pop();
        }
    }
    inToPost(0,0,n-1);
    return 0;
}
