/*
天真的我真的区用归并排序和插入排序了，结果发现还是sort函数香。
问题出在归并排序中，归并排序使用自上而下二分，而本题是自下而上
合并，显然不太行
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> origin,partialResult;

int main()
{
    int n,i,j;
    cin>>n;
    origin.resize(n);partialResult.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>origin[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>partialResult[i];
    }
    for(i=0;i<n-1&&partialResult[i]<=partialResult[i+1];i++);   //找出最后一个有序元素的下标i;
    for(j=i+1;origin[j]==partialResult[j]&&j<n;j++); //看i之后是否和原数组符合，若符合，即为插入排序
    if(j==n)
    {
        cout<<"Insertion Sort"<<endl;
        sort(origin.begin(),origin.begin()+i+2);    //注意这里i+2，因为sort第二个参数下界不参与排序
    }
    else    //否则按归并处理
    {
        cout<<"Merge Sort"<<endl;
        int k=1,flag=1;
        while(flag)
        {
            flag=0;
            for(i=0;i<n;i++)
            {
                if(origin[i]!=partialResult[i])
                    flag=1;
            }
            k=k*2;  //逐渐增加步长
            for(i=0;i<n/k;i++)
                sort(origin.begin()+i*k,origin.begin()+(i+1)*k);
            sort(origin.begin()+n/k*k,origin.end());
        }
    }
    cout<<origin[0];
    for(i=1;i<n;i++)
    {
        cout<<" "<<origin[i];
    }
    cout<<endl;
    return 0;
}
