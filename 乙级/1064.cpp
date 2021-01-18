#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;
int main()
{
    int couple;
    cin>>couple;
    int id[100000];
	for(int i=0;i<100000;i++)
		id[i]=0;
    int a,b;
    for(int i=0;i<couple;i++)
    {
        cin>>a>>b;
        id[a]=b;
        id[b]=a;
    }
    int party;
    cin>>party;
    vector<int> single_dog;
    int temp[party]={0};
    for(int i=0;i<party;i++)
    {
        cin>>temp[i];
    }
	cout<<temp[6]<<endl;
    for(int i=0;i<party;i++)
    {
		int sign=1;
        if(id[temp[i]]==-1)
        {
			cout<<"aaaaa";
            single_dog.push_back(temp[i]);
            continue;
        }
        for(int j=0;j<party;j++)
        {
            if(j!=i&&id[temp[i]]==temp[j])
            	{
					sign=0;
					break;
				}
        }
		cout<<"sign="<<sign<<endl;
		if(sign)
			single_dog.push_back(temp[i]);
    }
	cout<<single_dog.size()<<endl;
    sort(single_dog.begin(),single_dog.end());
    int i=0;
    cout<<setw(5)<<setfill('0')<<single_dog[i++];
    for(i;i<single_dog.size();i++)
    {
        cout<<' '<<setw(5)<<setfill('0')<<single_dog[i];
    }
    return 0;
}
