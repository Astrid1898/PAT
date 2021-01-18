/*这道题目要用树状数组，在做这道题目之前我甚至都没听说过树状数组，
*当然，做完之后也不是很清楚，不过看了考纲说是top level的知识点，果
*然是难啊，最近看了kmp算法和这个树状数组，都是很难理解，不过绝对不能
*不能放弃啊，再等等有了一定积累回头好好看看*/

#include<iostream>
#include<stack>
#define lowbit(i) (i&(-i))
using namespace std;
const int maxn=100010;
int c[maxn]; //a[i]记录i在栈中出现的次数
stack<int> s;
void update(int x,int val)	//有元素添加或者删除的时候就更新a数组	
{
    for(int i=x;i<maxn;i+=lowbit(i))
    {
        c[i]+=val;
    }
}
int getNum(int x)	//计数1-i的元素和
{
    int ans=0;
    for(int i=x;i>=1;i-=lowbit(i))
    {
        ans+=c[i];
    }
    return ans;
}
int peekMedian(int target)
{
    int low=1,high=maxn,mid;
    while(low<high)
    {
        mid=(low+high)>>1;
        if(getNum(mid)<target)
        {
            low=mid+1;
        }
        else
        {
            high=mid;
        }
    }
    cout<<low<<endl;
}
int main()
{
    int n,tmp;
    cin>>n;
    char ch[15];
    for(int i=0;i<n;i++)
    {
        scanf("%s",ch);
        if(ch[1]=='u')
        {
            cin>>tmp;
            s.push(tmp);
            update(tmp,1);
        }
        else if(ch[1]=='o')
        {
            if(s.empty())
            {
                cout<<"Invalid"<<endl;
            }
            else
            {
                update(s.top(),-1);
                cout<<s.top()<<endl;
                s.pop();
            }
        }
        else
        {
            if(s.empty())
            {
                cout<<"Invalid"<<endl;
            }
            else
            {
                peekMedian((s.size()+1)>>1);
            }
        }
    }
    return 0;
}
