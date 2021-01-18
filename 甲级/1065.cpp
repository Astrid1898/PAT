/*考察溢出，可以写的很简短，但一开始没有意识到，就写了这么多，在最后一个点
*还出了意外，推测可能是编译器的问题，注释中有详细说明*/

#include<iostream>
using namespace std;
typedef unsigned long long ull;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        long long a,b,c;
        cin>>a>>b>>c;
        if(a>=0&&b>=0&&c>=0)
        {
            if(ull(a)+ull(b)>ull(c))
                cout<<"true"<<endl;
            else
                cout<<"false"<<endl;
        }
        else if(a>=0&&b>=0)
            cout<<"true"<<endl;
        else if(a>=0&&c>=0)
        {
            if(a+b<=c)
            {
                cout<<"false"<<endl;
            }
            else
            {
                cout<<"true"<<endl;
            }
        }
        else if(b>=0&&c>=0)
        {
            if(a+b<=c)
            {
                cout<<"false"<<endl;
            }
            else
            {
                cout<<"true"<<endl;
            }
        }
        else if(a>=0||b>=0)
        {
            if(a+b<=c)
            {
                cout<<"false"<<endl;
            }
            else
            {
                cout<<"true"<<endl;
            }
            
        }
        else if(c>=0)
        {
            cout<<"false"<<endl;
        }

/*最后一个else处理三个数都小于零的情况，因为我知道这里应该输出false，所以
*可以验证，最后一个测试点包含三个点为负的情况，并且a=-9223372036854775808，*b=-9223372036854775808，这在我的电脑上sum=0是没有问题的，但是PTA上会过不了。
*推测系统将这时的ssum==0判定为false，如果令ssum--后再判断ssum<0则就是true了
*也有可能是硬件体系结构的问题*/

        else
        {
            long long int ssum=a+b;
            ssum--;
            if(ssum>0)
                cout<<"false"<<endl;
            else
            {
                if(ssum>c)
                    cout<<"true"<<endl;
                else
                    cout<<"false"<<endl;
            }
        }
    }
    return 0;
}
