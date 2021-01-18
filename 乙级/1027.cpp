#include<iostream>
using namespace std;
int main()
{
    int n;
    char sign;
    cin>>n>>sign;
    int lines=0,i=1;
    if(n!=0)
    {
        lines++;
        n=n-i;
        i=i+2;
    }
    else
    {
        cout<<n;
        return 0;
    }
    while(n>=2*i)
    {
        lines++;
        n=n-2*i;
        i=i+2;
    }
	int the_most_sign=2*lines-1;
    int line=lines;	
    do
    {
        int current_sign=2*lines-1;
        int the_left_space=(the_most_sign-current_sign)/2;
        int the_right_space=the_left_space;;
        while(the_left_space--)
        {
            cout<<' ';
        }
        while(current_sign--)
        {
            cout<<sign;
        }
        while(the_right_space--)
        {
            cout<<' ';
        }
	    cout<<endl;
    }
	while(--lines);
    lines=2;
    while(lines<=line)
    {
        int current_sign=2*lines-1;
        int the_left_space=(the_most_sign-current_sign)/2;
        int the_right_space=the_left_space;
        while(the_left_space--)
        {
            cout<<' ';
        }
        while(current_sign--)
        {
            cout<<sign;
        }
        while(the_right_space--)
        {
            cout<<' ';
        }
	    cout<<endl;
        lines++;
    }
    cout<<n;
    return 0;
}
