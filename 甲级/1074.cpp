/*
这里尝试使用慕课中的方法，不过显然并不需要像这样真的搞一个链表出来，在19年冬试里
也有这道题目，当时我只是改变了输出的顺序，然后就全A了，现在权做联系，但是这个方法
并不会全A，最后一个测试点因为数据量很大会出现超时的问题，优化了几次都没有解决
*/
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
struct Node
{
    int data;
    int address;
    int next;
};
istream &operator>>(istream &input,Node &a)
{
    input>>a.address>>a.data>>a.next;
    return input;
}
ostream &operator<<(ostream &output,const Node &a)
{
    output<<setw(5)<<setfill('0')<<a.address<<' '<<a.data<<' ';
    if(a.next!=-1)
        cout<<setw(5)<<setfill('0')<<a.next<<endl;
    else
        cout<<a.next<<endl;
}
int main()
{
    int head,n,k;
    vector<Node> list(100000);
    cin>>head>>n>>k;
    for(int i=0;i<n;i++)
    {
        Node tmp;
        cin>>tmp;
        list[tmp.address]=tmp;
    }
    int h=head,nodes=0;
    while(h!=-1)
    {
        nodes++;
        h=list[h].next;
    }
    int times=nodes/k,sign=1,reverseHead=head,tail=reverseHead;
    while(times--)
    {
        int New,Old,Tmp;
        New=list[head].address;
        Old=list[head].next;
	    int cnt=1;
        while(cnt<k)
        {
            Tmp=list[Old].next;
            list[Old].next=New;
            New=Old;Old=Tmp;
		    cnt++;
        }
        list[tail].next=New;
        tail=head;
        head=Old;
        if(sign)
        {
            reverseHead=New;
            sign=0;
        }
        if(times==0)
        {
            list[tail].next=Old;
        }
    }
    while(reverseHead!=-1)
    {
        cout<<list[reverseHead];
        reverseHead=list[reverseHead].next;
    }
    return 0;
}
