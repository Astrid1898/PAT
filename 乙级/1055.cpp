#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class person
{
    public:
        friend istream &operator>>(istream &input,person &temp);
        void show_name()
        {
            cout<<name;
        }
        string name;
        int height;
};
istream &operator>>(istream &input,person &temp)
{
    input>>temp.name>>temp.height;
    return input;
}
bool cmp(person a,person b)
{
    if(a.height==b.height)
        {
            return a.name<b.name;
        }
    return a.height>b.height;
}
void line_up(person[],int ,int ,int ,int );
int main()
{
    int n,k;
    cin>>n>>k;
    int per_row=n/k;
    int last_row=n-(per_row*(k-1));
    person photographer[n];
    for(int i=0;i<n;i++)
    {
        cin>>photographer[i];
    }
    sort(photographer,photographer+n,cmp);
    line_up(photographer,n,k,per_row,last_row);
    return 0;
}
void line_up(person  photographer[],int n,int k,int per_row,int last_row)
{
    bool flag=true;
    for(int i=0;i<k*per_row;i+=per_row)
    {
        int m=per_row;
        if(flag)
        {
            m=last_row;
            flag=false;
        }
        int b=m%2?m-1:m;
        int e=m%2?m:m-1;
        for(int j=b;j>1;j-=2)
        {
           photographer[i+j-1].show_name();
			cout<<' ';
        }
        for(int j=1;j<=e;j+=2)
        {
            photographer[i+j-1].show_name();
            if(j<e)
                cout<<' ';
        }
        cout<<endl;
		if(m==last_row)
			{
				i=i+last_row-per_row;
			}
    }
}
