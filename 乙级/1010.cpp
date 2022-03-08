#include<iostream>
#include<vector>
using namespace std;
class number
{
    public:
    int coefficient;
    int power;
};
int main()
{
    vector<number> v;
    number num;
    char c;
    while(1)
    {
        cin>>num.coefficient>>num.power;
        v.push_back(num);
        if((c = getchar())=='\n')
            break;
    }
    vector<number>::iterator i,end=v.end();
    for(i=v.begin();i!=end;i++)
    {
        if(i==v.begin()&&i->power!=0)
            cout<<(i->coefficient)*(i->power)<<" "<<(i->power)-1;
        else if(i==v.begin()&&i->power==0)
            cout<<0<<" "<<0;
        else
        {
            if(i->power!=0)
                cout<<" "<<(i->coefficient)*(i->power)<<" "<<(i->power)-1;
        }
    }
    return 0;
}
