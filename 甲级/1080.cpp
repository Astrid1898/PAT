/*
看着题目很复杂，但是只要理清其中的逻辑就很简单了
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct applicant    //存储考生信息
{
    int id;
    int ge;
    int gi;
    double totalGrade;
    vector<int> preferredSchool;
};
struct school   //存储学校信息
{
        int id;
        int quota;
        vector<applicant> admitList;
};
bool cmp(const applicant &a,const applicant &b)
{
    return a.totalGrade==b.totalGrade?a.ge>b.ge:a.totalGrade>b.totalGrade;
}
bool cmp1(const applicant &a,const applicant &b)
{
    return a.id<b.id;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<school> schools(m);
    for(int i=0;i<m;i++)
    {
        schools[i].id=i;
        cin>>schools[i].quota;
    }
    vector<applicant> applicants(n);
    for(int i=0;i<n;i++)
    {
        applicants[i].id=i;
        cin>>applicants[i].ge>>applicants[i].gi;
        applicants[i].totalGrade=double(applicants[i].ge+applicants[i].gi)/2.0;
        while(cin.get()!='\n')  //之前以为k是最大志愿数，但是后来直到都是k，所以这里没必要
        {
            int tmp;
            cin>>tmp;
            applicants[i].preferredSchool.push_back(tmp);
        }
    }
    sort(applicants.begin(),applicants.end(),cmp);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<applicants[i].preferredSchool.size();j++)
        {
            school &thisSchool=schools[applicants[i].preferredSchool[j]];
            if(thisSchool.quota>thisSchool.admitList.size())    //如果还有配额，直接录取
            {
                thisSchool.admitList.push_back(applicants[i]);
                break;
            }
            else    //没有配额就和最后录取的比较，若总分和笔试分数相同，仍要录取
            {
                applicant &lastadmit=thisSchool.admitList[thisSchool.admitList.size()-1];
                if(lastadmit.totalGrade==applicants[i].totalGrade&&lastadmit.ge==applicants[i].ge)
                {
                    thisSchool.admitList.push_back(applicants[i]);
                    break;
                }
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        vector<applicant> &t=schools[i].admitList;
        sort(t.begin(),t.end(),cmp1);
        for(int j=0;j<t.size();j++)
        {
            if(j==0)
                cout<<t[j].id;
            else
                cout<<" "<<t[j].id;
        }
        cout<<endl;
    }
    return 0;
}
