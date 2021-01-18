#include<iostream>
using namespace std;
struct huaquan
{
    int jia_han;
    int jia_hua;
    int yi_han;
    int yi_hua;
};
bool is_jia_lose(huaquan &jiuju)
{
    int total=jiuju.jia_han+jiuju.yi_han;
    if(jiuju.yi_hua==total&&jiuju.jia_hua!=total)
        return true;
    return false;
}
bool is_yi_lose(huaquan &jiuju)
{
    int total=jiuju.jia_han+jiuju.yi_han;
        if(jiuju.jia_hua==total&&jiuju.yi_hua!=total)
            return true;
        return false;
}
int main()
{
    int n;
    cin>>n;
    huaquan jiuju[n];
    int jia_he=0,yi_he=0;
    for(int i=0;i<n;i++)
    {
        cin>>jiuju[i].jia_han>>jiuju[i].jia_hua>>jiuju[i].yi_han>>jiuju[i].yi_hua;
        if(is_jia_lose(jiuju[i]))
            jia_he++;
        else if(is_yi_lose(jiuju[i]))
            yi_he++;
    }
    cout<<jia_he<<' '<<yi_he;
    return 0;
}
