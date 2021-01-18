/*模拟入栈出栈过程，没想到还挺快的*/

#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int m,n,k;
    cin>>m>>n>>k;
    while(k--)
    {
        int cnt=1;
        bool flag=true;
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            while(cnt<=tmp)
            {
                s.push(cnt++); //将tmp之前的元素统统入栈，检测是否合理
            }
            if(s.size()>m||s.top()!=tmp)
            {
                flag=false;
            }
            else
            {
                s.pop();
            }
        }
        flag?cout<<"YES"<<endl:cout<<"NO"<<endl;  
    }
    return 0;
}
