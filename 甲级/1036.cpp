/*这道题目也不难，感觉有点像乙级的题目，不用使用复杂的
*的数据结构，用STL就可以解决*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Student
{
    string name;
    char gender;
    string id;
    int grade;
};
bool cmp1(const Student &a,const Student &b)
{
    return a.grade>b.grade;
}
bool cmp2(const Student &a,const Student &b)
{
    return a.grade<b.grade;
}
int main()
{
    int n;
    vector<Student> female,male;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        Student tmp;
        cin>>tmp.name>>tmp.gender>>tmp.id>>tmp.grade;
        if(tmp.gender=='F')
        {
            female.push_back(tmp);
        }
        else
        {
            male.push_back(tmp);
        }
    }
    sort(female.begin(),female.end(),cmp1);
    sort(male.begin(),male.end(),cmp2);
    if(female.size())
    {
        cout<<female[0].name<<" "<<female[0].id<<endl;
    }
    else
    {
        cout<<"Absent"<<endl;
    }
    if(male.size())
    {
        cout<<male[0].name<<" "<<male[0].id<<endl;
    }
    else
    {
        cout<<"Absent"<<endl;
    }
    if(male.size()&&female.size())
    {
        cout<<female[0].grade-male[0].grade<<endl;
    }
    else
    {
        cout<<"NA"<<endl;
    }
    return 0;
}
