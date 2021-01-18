#include<iostream>
using namespace std;
void play_the_game(int& n1,int& b,int& t,int& n2,int& T)
{
    if(t>T)
	{
        cout<<"Not enough tokens.  Total = "<<T<<endl;
    }
    else if((n2>n1&&b)||(n2<n1)&&!b)
    {
        T+=t;
        cout<<"Win "<<t<<"!  Total = "<<T<<endl;
    }
    else
    {
        T-=t;
        cout<<"Lose "<<t<<".  Total = "<<T<<endl;
    }
    return;
}
int main()
{
    int T,k;
    cin>>T>>k;
    int n1,b,t,n2;
    while(T&&k)
    {
        cin>>n1>>b>>t>>n2;
        play_the_game(n1,b,t,n2,T);
		k--;
    }
    if(!T)
        cout<<"Game Over.";
    return 0;
}
