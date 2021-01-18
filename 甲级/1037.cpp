/*这道题目看似很长很复杂，实际上核心只是一个sort函数
*排序后分别让最大的正数相乘，最小的负数相乘即可*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int totalBack=0;
    vector<int> pocoupon,necouopn,poproduct,neproduct;	//正负数分开排序，可以更快
    int nc,np;
	cin>>nc;
    while(nc--)
    {
        int tmp;
        cin>>tmp;
        if(tmp>0)
        {
            pocoupon.push_back(tmp);
        }
        else
        {
            necouopn.push_back(tmp);
        }
    }
	cin>>np;
    while(np--)
    {
        int tmp;
        cin>>tmp;
        if(tmp>0)
        {
            poproduct.push_back(tmp);
        }
        else
        {
            neproduct.push_back(tmp);
        }
    }
    sort(pocoupon.begin(),pocoupon.end(),greater<int>());
    sort(necouopn.begin(),necouopn.end());
    sort(poproduct.begin(),poproduct.end(),greater<int>());
    sort(neproduct.begin(),neproduct.end());
	auto it1=pocoupon.begin();
	auto it2=poproduct.begin();
    for(;it1!=pocoupon.end()&&it2!=poproduct.end();it1++,it2++)
    {
        totalBack+=(*it1)*(*it2);
    }
    it1=necouopn.begin();
    it2=neproduct.begin();
    for(;it1!=necouopn.end()&&it2!=neproduct.end();it1++,it2++)
    {
        totalBack+=(*it1)*(*it2);
    }
    cout<<totalBack<<endl;
    return 0;
}
