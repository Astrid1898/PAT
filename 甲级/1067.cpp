/*最快的当然是让零与该位于零位置的元素交换，这样每次交换可以令
*一个元素有序，特殊的情况是经过一次交换后零到了位置零处而仍然有元素
*处于无序状态，这会增大需要交换的次数*/

#include<iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);

	/*
	*num记录permutation，pos记录各个元素的位置信息，ans记
	*录有序的个数，cnt记录交换次数，cur与处理特殊情况有关
	*/

    int num[n],pos[n],ans=0,cnt=0,cur=1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        pos[num[i]]=i;
        ans+=(num[i]==i);	//已处于自身位置的元素不能也不需要通过交换就位，所以直接计为有序
    }
    while(ans!=n)
    {
        if(pos[0]==0)	//处理0到位置零的特殊情况
        {
            while(pos[cur]==cur)
            {
                cur++;	//找到一个没有就位的元素，令其为局部变量需要每次从头找起，会超时
            }
            swap(num[pos[0]],num[pos[cur]]);
            swap(pos[cur],pos[0]);
            ans--;	//交换将令0从应该在的位置离开，有序元素减一
        }
        else
        {
            swap(num[pos[0]],num[pos[pos[0]]]);	
            swap(pos[0],pos[pos[0]]);	//注意这里的交换顺序，该变num和pos的交换顺序也是可以的，甚至不用num都可以，有进一步优化空间
            ans+=(pos[0]==0?2:1);
        }
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
