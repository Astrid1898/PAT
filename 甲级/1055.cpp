/*读数据，排序，筛选，输出就完了*/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct People
{
    string name;
    int age;
    int worth;
};
bool cmp(const People &a,const People &b)
{
    return a.worth==b.worth?(a.age==b.age?a.name<b.name:a.age<b.age):a.worth>b.worth;
}
int main()
{
    int n,k;
    cin>>n>>k;
    People p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i].name>>p[i].age>>p[i].worth;
    }
    sort(p,p+n,cmp);
    for(int i=0;i<k;i++)
    {
        int m,ageMin,ageMax;
        cin>>m>>ageMin>>ageMax;
        int sign=0;
        cout<<"Case #"<<i+1<<":"<<endl;
        for(int j=0;j<n;j++)
        {
            if(m==0)
            {
                break;
            }
            if(p[j].age>=ageMin&&p[j].age<=ageMax)
            {
                sign=1;
                cout<<p[j].name<<" "<<p[j].age<<" "<<p[j].worth<<endl;
                m--;
            }
        }
        if(sign==0)
            cout<<"None"<<endl;
    }
    return 0;
}
