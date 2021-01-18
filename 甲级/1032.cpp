/*这道题目也不难，就是找出链表中同时被两个前一个表项所指的节点的地址
*一开始没有考虑到可能会有废节点，造成了一些问题
*/

#include<iostream>
#include<iomanip>
#define MAX 100000
using namespace std;
struct Node	//节点
{
    char data;
    int nextaddress;
    bool isVisited;
};
int main()
{
    Node nodes[MAX];
    int head1,head2,n;
    cin>>head1>>head2>>n;
    while(n--)
    {
        int address,nextaddress;
        char data;
        cin>>address>>data>>nextaddress;
        nodes[address].data=data;
        nodes[address].nextaddress=nextaddress;
        nodes[address].isVisited=false;
    }
    for(int i=head1;i!=-1;i=nodes[i].nextaddress)
    {
        nodes[i].isVisited=true;	//遍历一遍，标记所有节点为访问过
    }
    for(int i=head2;i!=-1;i=nodes[i].nextaddress)
    {
        if(nodes[i].isVisited)
        {
            cout<<setw(5)<<setfill('0')<<i<<endl;	//找出第二个单词中第一个被访问过的节点，即为所求
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
