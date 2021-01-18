/*上一题的升级版，代码写的有点乱*/
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
struct score
{
    string id;
    int c{0};
    int m{0};
    int e{0};
    int a{0};
};
istream &operator>>(istream &input,score &c)
{
    input>>c.id>>c.c>>c.m>>c.e;
    c.a=(c.c+c.m+c.e)/3.0+0.5;	//在这里求平均值，虽然不太好，但是方便，注意四舍五入，PAT标准库里没有round函数
    return input;
}
bool c_cmp(const score &a,const score &b)
{
    return a.c>b.c;
}
bool e_cmp(const score &a,const score &b)
{
    return a.e>b.e;
}
bool m_cmp(const score &a,const score &b)
{
    return a.m>b.m;
}
bool a_cmp(const score &a,const score &b)
{
    return a.a>b.a;
}
int main()
{
    int n,m;
    cin>>n>>m;
    score stu[n];
    map<string,int> a_map,c_map,m_map,e_map;	//记录名次，并且方便查找
    for(int i=0;i<n;i++)
    {
        cin>>stu[i];
    }
    int rank=1;score tmp;
    sort(stu,stu+n,a_cmp);
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            a_map[stu[i].id]=rank;
        }
        else
        {
            if(stu[i].a<tmp.a)
            {
                rank=i+1;
            }
            a_map[stu[i].id]=rank;
        }
        tmp=stu[i];
    }
    sort(stu,stu+n,c_cmp);
    rank=1;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            c_map[stu[i].id]=rank;
        }
        else
        {
            if(stu[i].c<tmp.c)
            {
                rank=i+1;	//注意这里名次计算方法
            }
            c_map[stu[i].id]=rank;
        }
        tmp=stu[i];
    }
    sort(stu,stu+n,m_cmp);
    rank=1;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            m_map[stu[i].id]=rank;
        }
        else
        {
            if(stu[i].m<tmp.m)
            {
                rank=i+1;
            }
            m_map[stu[i].id]=rank;
        }
        tmp=stu[i];
    }
    sort(stu,stu+n,e_cmp);
    rank=1;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            e_map[stu[i].id]=rank;
        }
        else
        {
            if(stu[i].e<tmp.e)
            {
                rank=i+1;
            }
            e_map[stu[i].id]=rank;
        }
        tmp=stu[i];
    }
    while(m--)
    {
        string to_serch;
        cin>>to_serch;
        if(!a_map.count(to_serch))
        {
            cout<<"N/A"<<endl;
        }
        else
        {
            int min_rank=1e6;
            char best;
            if(a_map[to_serch]<min_rank)
            {
                min_rank=a_map[to_serch];
                best='A';
            }
            if(c_map[to_serch]<min_rank)
            {
                min_rank=c_map[to_serch];
                best='C';
            }
            if(m_map[to_serch]<min_rank)
            {
                min_rank=m_map[to_serch];
                best='M';
            }
            if(e_map[to_serch]<min_rank)
            {
                min_rank=e_map[to_serch];
                best='E';
            }
            cout<<min_rank<<' '<<best<<endl;
        }
    }
    return 0;
}
