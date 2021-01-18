#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
struct student
{
    string name;
    int number;
    vector<int> goods;
    vector<int> contraband;
};
int main()
{
    int n,m;
    cin>>n>>m;
    int bad_stu=0,bad_goods=0;
    int con_id[m];
    for(int i=0;i<m;i++)
        cin>>con_id[i];
    for(int i=0;i<n;i++)
    {
        student* stu_to_be_checked=new student;
        cin>>stu_to_be_checked->name;
        cin>>stu_to_be_checked->number;
        int sign=0;
        int sign2=0;
        for(int j=0;j<stu_to_be_checked->number;j++)
        {
            int temp;
            cin>>temp;
            stu_to_be_checked->goods.push_back(temp);
            for(int z=0;z<m;z++)
            {
                if(temp==con_id[z])
                {
                    if(sign)
                    {
                        cout<<' '<<setw(4)<<setfill('0')<<temp;
                        bad_goods++;
                    }
                    else
                    {
                        cout<<stu_to_be_checked->name<<": "<<setw(4)<<setfill('0')<<temp;
                        bad_stu++;
                        bad_goods++;
                        sign=1;
                        sign2=1;
                    }
                }
            }
        }
        if(sign2)
            cout<<endl;
		delete stu_to_be_checked;

    }
    cout<<bad_stu<<' '<<bad_goods;
    return 0;
}
