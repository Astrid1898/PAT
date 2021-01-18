/*坑点是有不是链表内的节点，这是PAT常用的手段，所以要先遍历后排序
*细节是第一行地址的格式，最后一个测试点是没有有效节点*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
#define MAX 100000
using namespace std;
struct Node
{
    Node(int k,int n):key{k},next{n}{}
    Node(int a,int k,int n):address{a},key{k},next{n}{}
    Node():address{0},key{0},next{0}{}
    int key;
    int next;
    int address;
};	//存储节点信息
bool cmp(const Node& a,const Node& b)
{
    return a.key<b.key;
}
int main()
{
    Node* p=new Node[MAX];
    int n,head;
    cin>>n>>head;
    for(int i=0;i<n;i++)
    {
        int address,key,next;
        cin>>address>>key>>next;
        p[address]=Node(key,next);	
    }
    vector<Node> valuedNodes;	//存储有效节点
    while(head!=-1)
    {
        valuedNodes.push_back(Node(head,(p[head]).key,(p[head]).next));	//遍历，并将有效节点添加到valuedNodes中
        head=(p[head]).next;
    }
    sort(valuedNodes.begin(),valuedNodes.end(),cmp);	//排序
    delete[] p;	//想来想去这里没有必要，并没有节约内存，不必用指针
    cout<<valuedNodes.size()<<" "<<valuedNodes[0].address<<endl;
    for(int i=0;i<valuedNodes.size()-1;i++)
    {
        cout<<setw(5)<<setfill('0')<<valuedNodes[i].address<<" "<<valuedNodes[i].key<<" ";
        cout<<setw(5)<<setfill('0')<<valuedNodes[i+1].address<<endl;
    }
    cout<<setw(5)<<setfill('0')<<valuedNodes[valuedNodes.size()-1].address<<" "<<valuedNodes[valuedNodes.size()-1].key<<" ";
    cout<<"-1"<<endl;
    return 0;
}
