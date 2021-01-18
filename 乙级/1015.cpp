#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct score
{
    int id,de,cai;
};
int cmp(score a,score b)
{
    if((a.de+a.cai)!=(b.de+b.cai))
        return a.de+a.cai>b.de+b.cai;
    else 
        return a.de!=b.de? a.de>b.de : a.id<b.id;
}
int main()
{
    int N,L,H;
    cin>>N>>L>>H;
    vector<score> v[4];
    score tmp;
    int cnt;
    for(int i=0;i<N;i++)
    {
        cin>>tmp.id>>tmp.de>>tmp.cai;
        if(tmp.de>=H&&tmp.cai>=H)
        {
            v[0].push_back(tmp);
            cnt++;
        }
        else if(tmp.de>=H&&tmp.cai>=L)
        {
            v[1].push_back(tmp);
            cnt++;
        }
        else if(tmp.de>=L&&tmp.cai>=L&&tmp.de>=tmp.cai)
        {
            v[2].push_back(tmp);
            cnt++;
        }
        else if(tmp.de>=L&&tmp.cai>=L)
        {
            v[3].push_back(tmp);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<4;i++)
    {
        sort(v[i].begin(),v[i].end(),cmp);
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j].id<<" "<<v[i][j].de<<" "<<v[i][j].cai<<endl;
        }
    }
    return 0;
}
