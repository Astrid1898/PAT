/*算法分析入门题目，可以使用线性时间复杂的的联机算法运行，不过由于需要额外的子数列首尾的信息，需要稍加修改，但是改得并不成功，程序显得逻辑很混乱，可见水平还不够*/

#include<iostream>
using namespace std;
int main()
{
    int k,temp;
	cin>>k;
/*maxsum设为-1是为了正确处理0的情况，但同时也要记得把全负时候的maxsum输出前写为0,sign用于控制i遇到thissum小于0时向前推进，final_i和final_j用于记录下已经处理的数列的最大子数列的首尾值，first用于记录整个数组的首位，cnt用于判断是否全为负数*/
    int maxsum=-1,thissum=0,i=0,j=0,sign=1,tag=1,final_i,final_j,first,cnt=0;
    while(k--)
    {
        cin>>temp;
        if(tag)
        {
            first=temp;
            tag=0;
        }
        if(sign)
        {
            i=temp;
            sign=0;
        }
        thissum+=temp;
        if(thissum>maxsum)
        {
            maxsum=thissum;
            j=temp;
            final_i=i;final_j=j;
            cnt++;
        }
        else if(thissum<0)
        {
            thissum=0;
            sign=1;
        }
    }
    if(cnt==0)
    {
        final_i=first;
        final_j=i;
        maxsum=0;
    }
    cout<<maxsum<<' '<<final_i<<' '<<final_j<<endl;
    return 0;
}
