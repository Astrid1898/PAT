/*又是一个很有意思的题目，看似要分解数字，实际上暴力计算耗时太久，要O(n)
*的复杂度，这里采用一个巧妙地排列组合将时间复杂度降到了O(len(n))*/

/*对于数字的每一位，求其为1时的排列组合。若当前数字为零，取为1时，左边只能
*小于原来的值，右边可以任取
*而当该位数字为1时，不仅可以取上一种情况的所有取法，还可以加上左边等于原来
*的值，右边小于等与原来的值的数
*而当当前的数字大于1的时候，当该位为1时，别的位就可以任取了*/


#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int left,right,digit=1,num,cnt=0;
    while(n/digit)
    {
        left=n/(digit*10);
        right=n%digit;
        num=n/digit%10;
        if(num==0)
        {
            cnt+=left*digit;
        }
        else if(num==1)
        {
            cnt+=left*digit+right+1;
        }
        else
        {
            cnt+=(left+1)*digit;
        }
        digit=digit*10;
    }
    cout<<cnt<<endl;
    return 0;
}
