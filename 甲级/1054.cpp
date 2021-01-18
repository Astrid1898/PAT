/*若采用直接创建一个颜色数组的方法记录各颜色出现的次数
需要128M的内存，超过了限制，所以这里使用了map*/

#include<iostream>
#include<map>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    map<int,int> colors;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int tmp;
			cin>>tmp;
            colors[tmp]++;
        }
    }
    int max=0,maxColor=0;
    for(auto itr=colors.begin();itr!=colors.end();itr++)
    {
        if(itr->second>max)
        {
            maxColor=itr->first;
            max=itr->second;
        }
    }
    cout<<maxColor<<endl;
    return 0;
}
/*这里附上网上的贪心算法，极为巧妙

#include <iostream>
using namespace std;
int main(){
	int n, m, temp, cnt = 0, ans = - 1;
	scanf("%d %d",&n, &m);
	for(int i = 0; i < m; ++ i)
		for(int j = 0; j < n; ++ j){
			scanf("%d", &temp);
			cnt += (temp == ans ? 1 : -1);
			if(cnt < 0){
				ans = temp;
				cnt = 0;
			}
		}	
	printf("%d", ans);
}
*/
