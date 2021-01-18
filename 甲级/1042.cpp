/*20分的题目，还是很简单的，弄两个vector通过指针互换处理就好了*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    vector<string> deck(55);
    vector<string> deck1(55);
    vector<string> *itr1=&deck;
    vector<string> *itr2=&deck1;
    *itr2=deck1;
    int i=1;

	/*设置初始值*/
    for(int j=0;j<13;j++)	
    {
        string str;
        str+='S';
        str+=to_string(j+1);
        deck[i+j]=str;
    }
    i=i+13;
    for(int j=0;j<13;j++)
    {
        string str;
        str+='H';
        str+=to_string(1+j);
        deck[i+j]=str;
    }
    i=i+13;
    for(int j=0;j<13;j++)
    {
        string str;
        str+='C';
        str+=to_string(1+j);
        deck[i+j]=str;
    }
    i=i+13;
    for(int j=0;j<13;j++)
    {
        string str;
        str+='D';
        str+=to_string(1+j);
        deck[i+j]=str;
    }
    deck[53]="J1";deck[54]="J2";   
	int times;
    cin>>times;
    int suffing[55];
    for(int k=1;k<55;k++)
    {
        cin>>suffing[k];
    }
    int k=times;
    while(times--)	//洗牌
    {
        for(int k=1;k<55;k++)
        {
            (*itr2)[suffing[k]]=move((*itr1)[k]);
        }
        swap(itr1,itr2);
    }
    for(int k=1;k<54;k++)
    {
        cout<<(*itr1)[k]<<' ';
    }
    cout<<(*itr1)[54]<<endl;
    return 0;
}
