/*想试一试链表，于是有了这样的解法，其实是参照浙大MOOK的例题*/
#include<iostream>
#include<iomanip>
#include<cmath>
#define EPS 1e-6	/用于float类型的数据是否等于0的判断，定义一个最小值
using namespace std;
int cnt=0;
typedef struct poly_node* polynomial;
struct poly_node
{
    int expon{0};
    float coef{0.0};
    polynomial next{nullptr};
};
void attach(int e,float c,polynomial* prear)
{
    polynomial p;
    p=new poly_node;
    p->coef=c;
    p->expon=e;
    p->next=nullptr;
    (*prear)->next=p;
    *prear=p;
}
polynomial read_poly()
{
    polynomial p,rear,t;
    int k,e;
    float c;
    cin>>k;
    p=new poly_node;
    p->next=nullptr;
    rear=p;
    while(k--)
    {
        cin>>e>>c;
        attach(e,c,&rear);
    }
    t=p;p=p->next;delete t;
    return p;
}
polynomial add(polynomial p1,polynomial p2)
{
    polynomial t1=p1,t2=p2;
    polynomial p=new poly_node; p->next=nullptr;
    polynomial rear=p,t;
    while(t1&&t2)
    {
        if(t1->expon==t2->expon)
        {
            float sum=t1->coef+t2->coef;
            if(fabs(sum)>EPS)
            {
                attach(t1->expon,sum,&rear);
                cnt++;		//由于此处计数出错，导致排查了半天
            }
            t1=t1->next;
            t2=t2->next;
        }
        else if(t1->expon<t2->expon)
        {
            attach(t2->expon,t2->coef,&rear);
            t2=t2->next;
            cnt++;
        }
        else
        {
            attach(t1->expon,t1->coef,&rear);
            t1=t1->next;
            cnt++;
        }
    }    
	while(t1)
    {
        attach(t1->expon,t1->coef,&rear);
        t1=t1->next;
        cnt++;
    }
    while(t2)
    {
        attach(t2->expon,t2->coef,&rear);
        t2=t2->next;
        cnt++;
    }
    t=p;p=p->next;delete t;
    return p;
}
void printpoly(polynomial p)
{
	cout<<cnt;
    while(p)
    {
        cout<<' '<<p->expon<<' '<<setiosflags(ios::fixed)<<setprecision(1)<<p->coef;
        p=p->next;
    }
}
int main()
{
    polynomial p1,p2,p3;
    p1=read_poly();
    p2=read_poly();
    p3=add(p1,p2);
    printpoly(p3);
    return 0;
}
