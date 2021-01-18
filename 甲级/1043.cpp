/*这题有点意思，首先缺了二叉树的中序遍历是不可能
*构造出唯一的二叉树的，如果硬要写会很麻烦。一个可行的
*方案就是直接从前序遍历得出后序遍历，如果二者数目相等
*就是二叉查找数，否则不是*/


#include<iostream>
#include<vector>
using namespace std;
bool isMirror=false;
vector<int> num,post;
void getPost(int front,int tail)	//假设当前序列是二叉查找树或其镜像，找到后序遍历序列
{
    if(front>tail)
        return;	//首大于尾，返回
    int i=front+1,j=tail;
    if(!isMirror)	//判断非镜像的情况
    {
        while(i<=tail&&num[front]>num[i])
        {
            i++;
        }
        while(j>front&&num[front]<=num[j])
        {
            j--;
        }
    }
    else	//镜像情况
    {
        while(i<=tail&&num[front]<=num[i])
        {
            i++;
        }
        while(j>front&&num[front]>num[j])
        {
            j--;
        }
    }
    if((i-j)!=1) return;
    getPost(front+1,i-1);
    getPost(j+1,tail);
    post.push_back(num[front]);
}
int main()
{
    int n;
    cin>>n;
    num.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    getPost(0,n-1);
    if(post.size()<n)
    {
        post.clear();
        isMirror=true;
        getPost(0,n-1);
    }
    if(post.size()<n)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        cout<<post[0];
        for(int i=1;i<post.size();i++)
        {
            cout<<" "<<post[i];
        }
        cout<<endl;
    }
    return 0;
}
