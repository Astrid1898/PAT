#include<iostream>
#include<vector>
#include<map>
using namespace std;
struct container
{
    int good_num;
    vector<int> goods;
};
istream &operator>>(istream& input,container& c)
{
    input>>c.good_num;
    for(int i=0;i<c.good_num;i++)
    {
        int temp;
        input>>temp;
        c.goods.push_back(temp);
    }
    return input;
}
int main()
{
    int n,m;
    cin>>n>>m;
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for(int i=0;i<m;i++)
    {
		int p[100000]={0};
        int flag=0;
        container temp;
        cin>>temp;
        for(int j=0;j<temp.good_num;j++)
        {
            p[temp.goods[j]]=1;
        }
        for(int k=0;k<temp.good_num;k++)
        {
            for(int j=0;j<mp[temp.goods[k]].size();j++)
            {
                if(p[mp[temp.goods[k]][j]]==1)
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        flag?cout<<"No":cout<<"Yes";
        cout<<endl;
    }

    return 0;
}
