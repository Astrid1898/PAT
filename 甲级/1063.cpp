/*最大的问题是关于map语法的，用vector<map>的时候整个vector
*都是不会重复的，为了避开这一点，直接记录数组之后用遍历每两组
*记录在map中，从而算出结果，但是会超时，看了柳神的代码后解决了map
*的问题，果然不会超时了*/

#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<map<int,int>> pairs(n);	//记录每一组数
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        map<int,int> tmp;
        for(int j=0;j<m;j++)
        {
            int num;
            cin>>num;
            tmp[num]++;	//先弄个局部的map记录下一组的值，然后将这一组加入pairs中，不然会整个pairs都不计重复的元素
        }
        pairs[i]=tmp;
    }
    int k;
    cin>>k;
    while(k--)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        int nc=0,nt=pairs[b].size();
        for(auto it=pairs[a].begin();it!=pairs[a].end();it++)
        {
            if(pairs[b].count(it->first))
            {
                nc++;	//若b中找到了a中的一个元素，重复元计数加一
            }
            else
            {
                nt++;	//否则总元素加一
            }
        }
        float ans=float(nc)/float(nt)*100;
        cout<<setiosflags(ios::fixed)<<setprecision(1);
        cout<<ans<<"%"<<endl;
    }
    return 0;
}
