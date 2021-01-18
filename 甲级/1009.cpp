/*依然是慕课上的题目，不过是加了个cnt计项数而已*/
/*想到一个问题，题目没有考虑多项式中某一项系数为零的情况*/
#include<iostream>
#include<iomanip>
#include<cmath>
#define EPS 1e-6
using namespace std;
int cnt=0;
typedef struct node* polynomial;
struct node
{
    int exop={0};
    float coef{0.0};
    polynomial next{nullptr};
};
void attach(polynomial* cur,int e,float c) //把新的项添加到cur后面
{
    polynomial p=new node;
    p->coef=c;
    p->exop=e;
    (*cur)->next=p;
    *cur=p;
}
polynomial read_poly()
{
    int k,e;
    float c;
    cin>>k;
    polynomial cur=new node; //前面用一个空节点可以避免很多麻烦
    polynomial head=cur;
    while(k--)
    {
        cin>>e>>c;
        attach(&cur,e,c);
    }
    cur=head;head=head->next;
    delete cur;
    return head;
}
polynomial mult(polynomial a,polynomial b)
{
    polynomial t1=a,t2=b;
    int e;
    float c;
    if(!a||!b)return nullptr;
    polynomial cur=new node;
    polynomial head=cur;
    while(t2)
    {
        attach(&cur,t1->exop+t2->exop,t1->coef*t2->coef);
        t2=t2->next;
        cnt++;
    }
    t1=t1->next;
    while(t1)
    {
        t2=b,cur=head;
        while(t2)
        {
            e=t1->exop+t2->exop;
            c=t1->coef*t2->coef;
            while(cur->next&&cur->next->exop>e)
            {
                cur=cur->next;
            }
            if(cur->next&&cur->next->exop==e)
            {
                if(abs(cur->next->coef+c)>EPS)
                {
                    cur->next->coef=cur->next->coef+c;
                }
                else
                {
                    polynomial t=cur->next;
                    cur->next=t->next;
                    delete t;
                    cnt--;
                }
            }
            else
            {
                polynomial t=new node;
                t->coef=c;
                t->exop=e;
                t->next=cur->next;
                cur->next=t;
                cnt++;
            }
            t2=t2->next;
        }
        t1=t1->next;
    }
    cur=head;head=cur->next;
    delete cur;
    return head;
}
void print_poly(polynomial p)
{
    cout<<cnt;
    while(p)
    {
        cout<<' '<<p->exop<<' '<<setiosflags(ios::fixed)<<setprecision(1)<<p->coef;
        p=p->next;
    }
}
int main()
{
    polynomial a=read_poly();
    polynomial b=read_poly();
    polynomial c=mult(a,b);
    print_poly(c);
    return 0;
}
