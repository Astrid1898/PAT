#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
struct student
{   
    string id;
    int gp,gm,gf,g;
};
bool cmp(student &a,student &b)
{
    return a.g!=b.g?a.g>b.g:a.id<b.id;
}
ostream &operator<<(ostream &output,const student& t)
{
    if(t.g>=60)
        output<<t.id<<' '<<t.gp<<' '<<t.gm<<' '<<t.gf<<' '<<t.g<<endl;
    return output;
}
int main()
{
    int p,m,n,temp,cnt=1;
    cin>>p>>m>>n;
    vector<student> p_stu;
    string str;
    map<string,int> index;
    for(int i=0;i<p;i++)
    {
        cin>>str>>temp;
        if(temp>=200)
        {
            p_stu.push_back(student{str,temp,-1,-1,0});
            index[str]=cnt++;
        }
    }
    for(int i=0;i<m;i++)
    {
        cin>>str>>temp;
        if(index[str])
            p_stu[index[str]-1].gm=temp;
    }
    for(int i=0;i<n;i++)
    {
        cin>>str>>temp;
        if(index[str])
        {
            p_stu[index[str]-1].gf= p_stu[index[str]-1].g=temp;
            if(p_stu[index[str]-1].gm>p_stu[index[str]-1].gf)
                p_stu[index[str]-1].g=int(0.4*p_stu[index[str]-1].gm+0.6*p_stu[index[str]-1].gf+0.5);
        }
    }
    sort(p_stu.begin(),p_stu.end(),cmp);
    for(auto s:p_stu)
        cout<<s;
    return 0;
}
