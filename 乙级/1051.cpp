#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;
int main()
{	
	double a,b;
	cin>>a>>b;
	    cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout<<a;
    if(b<0)
        cout<<'-';
	else
		cout<<'+';
    cout<<fabs(b)<<'i';
return 0;
}

