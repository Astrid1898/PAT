#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
struct person
{
    string name;
    int year;
    int month;
    int day;
};
bool cmp(person a,person b)
{
    if(a.year!=b.year)
        return a.year>b.year;
    else if(a.month!=b.month)
        return a.month>b.month;
    else if(a.day!=b.day)
        return a.day>b.day;
}
int main()
{
    int n=0;
    cin>>n;
    getchar();
    vector<person> population;
    for(int i=0;i<n;i++)
    {
        string tmp;
        person tmp_person;
        tmp_person.year=0;
	    tmp_person.month=0;
	    tmp_person.day=0;
        getline(cin,tmp);
        int j=0;
        while(tmp[j]!=' ')
        {
            tmp_person.name.push_back(tmp[j]);
            j++;
        }
        j++;
        for(int cont=0;cont<4;cont++)
        {
            tmp_person.year=tmp_person.year*10+(tmp[j]-'0');
            j++;
        }
        j++;
        for(int cont=0;cont<2;cont++)
        {
            tmp_person.month=tmp_person.month*10+(tmp[j]-'0');
            j++;
        }
        j++;
        for(int cont=0;cont<2;cont++)
        {
            tmp_person.day=tmp_person.day*10+(tmp[j]-'0');
            j++;
        }
        if(tmp_person.year>1814&&tmp_person.year<2014)
            population.push_back(tmp_person);
        else if((tmp_person.year==1814&&tmp_person.month>9)||(tmp_person.year==1814&&tmp_person.month==9&&tmp_person.day>=6))
            population.push_back(tmp_person);
        else if((tmp_person.year==2014&&tmp_person.month<9)||(tmp_person.year==2014&&tmp_person.month==9&&tmp_person.day<=6))
            population.push_back(tmp_person);
    }
    sort(population.begin(),population.end(),cmp);
    cout<<population.size()<<' '<<population[population.size()-1].name<<' '<<population[0].name;
    return 0;
}
