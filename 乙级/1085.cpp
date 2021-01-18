#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
struct school
{
    string name;
    double total_score;
    int total_stu_num;
};
struct stu
{
    string id;
    double score;
    string school_name;
};
bool cmp(const school& a,const school& b)
{
    return int(a.total_score)!=int(b.total_score)?int(a.total_score)>int(b.total_score):(a.total_stu_num!=b.total_stu_num?a.total_stu_num<b.total_stu_num:a.name<b.name);
}
istream &operator>>(istream &input,stu& s)
{
    input>>s.id>>s.score>>s.school_name;
    return input;
}
ostream &operator<<(ostream& output,const school& s)
{
    cout<<s.name<<' '<<int(s.total_score)<<' '<<s.total_stu_num<<endl;
    return output;
}
double get_the_score(const stu &s)
{
    switch(s.id[0])
    {
    case 'B':
        return s.score/1.5;
        break;
    case 'A':
        return s.score;
        break;
    case 'T':
        return s.score*1.5;
        break;
    }
}
int main()
{
    int n,cnt=1,sign=0;
    cin>>n;
    vector<school> schools;
    map<string,int> mp;
    stu temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        transform(temp.school_name.begin(),temp.school_name.end(),temp.school_name.begin(),::tolower);
        double d=get_the_score(temp);
        if(!mp[temp.school_name])
        {
            schools.push_back(school{temp.school_name,d,1});
            mp[temp.school_name]=cnt;
            cnt++;
        }
        else
        {
            int index=mp[temp.school_name]-1;
            schools[index].total_score+=d;
            schools[index].total_stu_num++;
        }
    }
    sort(schools.begin(),schools.end(),cmp);
    cout<<schools.size()<<endl;
    cnt=1;
    int last_score=int(schools[0].total_score);
    for(auto s:schools)
    {
        if(last_score==int(s.total_score))
        {
            sign++;
            cout<<cnt<<' '<<s;
        }
        else
        {
            cnt=cnt+sign;
            cout<<cnt<<' '<<s;
            sign=1;
        }
        last_score=int(s.total_score);
    }
    return 0;
}
