/*排序题，没什么好说的，这道题乙级也有*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct person
{
    string id;
    int virtue;
    int talent;
    int total;
};
istream &operator>>(istream &input,person &p)
{
    input>>p.id>>p.virtue>>p.talent;
    p.total=p.virtue+p.talent;
    return input;
}
ostream &operator<<(ostream &output,const person &p)
{
    output<<p.id<<" "<<p.virtue<<" "<<p.talent;
    return output;
}
bool cmp(const person &a,const person &b)
{
    return a.total==b.total?(a.virtue==b.virtue?a.id<b.id:a.virtue>b.virtue):a.total>b.total;
}
int main()
{
	int n,l,h;
    vector<person> sage,nobleman,fool,other;
    cin>>n>>l>>h;
    while(n--)
    {
        person tmp;
        cin>>tmp;
        if(tmp.virtue<l||tmp.talent<l)
        {
            continue;
        }
        if(tmp.virtue>=h&&tmp.talent>=h)
        {
            sage.push_back(tmp);
        }
        else if(tmp.virtue>=h)
        {
            nobleman.push_back(tmp);
        }
        else if(tmp.virtue<h&&tmp.talent<h&&tmp.virtue>=tmp.talent)
        {
            fool.push_back(tmp);
        }
        else
        {
            other.push_back(tmp);
        }
    }
    cout<<sage.size()+nobleman.size()+fool.size()+other.size()<<endl;
    sort(sage.begin(),sage.end(),cmp);
    sort(nobleman.begin(),nobleman.end(),cmp);
    sort(fool.begin(),fool.end(),cmp);
    sort(other.begin(),other.end(),cmp);
    for(int i=0;i<sage.size();i++)
    {
        cout<<sage[i]<<endl;
    }
    for(int i=0;i<nobleman.size();i++)
    {
        cout<<nobleman[i]<<endl;
    }
    for(int i=0;i<fool.size();i++)
    {
        cout<<fool[i]<<endl;
    }
    for(int i=0;i<other.size();i++)
    {
        cout<<other[i]<<endl;
    }
    return 0;
}
