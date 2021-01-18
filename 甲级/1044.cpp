/*看似简单的一道题目，用的方法却很巧妙
*采用双指针法，一次遍历，p为左指针，q为右指针，
*取p=1时，q就遍历到p刚好是p-q的对应的数组的值的
*和大于等于目标结果，同时设一个临时结果，若此时的
*结果小于临时结果，且大于等于目标结果就清空目标数
*组，若等于，则直接存储此时的ij位置，然后p向前遍历，
*q也相应的前移以再次满足大于等于目标结果*/

#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,target,p=0,q=1,ans=0,minans=0x7fffffff;
    cin>>n>>target;
    vector<int> money(n+1),result;
    money[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>money[i];
    }
    for(;p<=n;p++)
    {
        ans-=money[p];	//剪去开头，这样就不必再遍历一次
        while(q<=n&&ans<target)
        {
            ans+=money[q++];	//向前推进
        }
        if(ans>=target&&ans<minans)
        {
            minans=ans;
            result.clear();
            result.push_back(p+1);
            result.push_back(q-1);
        }
        else if(ans==minans)
        {
            result.push_back(p+1);
            result.push_back(q-1);
        }
    }
    for(int i=0;i<result.size();i=i+2)
    {
        cout<<result[i]<<"-"<<result[i+1]<<endl;
    }
    return 0;
}
