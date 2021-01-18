/*不能先转化成Kunt再计算，会超过限制*/

#include<iostream>
using namespace std;
struct Money
{
    int Galleon;
    int Sickle;
    int Knut;
};
int main()
{
    Money a,b,c;
    scanf("%d.%d.%d",&a.Galleon,&a.Sickle,&a.Knut);
    scanf("%d.%d.%d",&b.Galleon,&b.Sickle,&b.Knut);
    int sign=0;
    c.Knut=a.Knut+b.Knut;
    if(c.Knut>=29)
    {
        sign=1;
        c.Knut=c.Knut-29;
    }
    c.Sickle=a.Sickle+b.Sickle+sign;
    sign=0;
    if(c.Sickle>=17)
    {
        sign=1;
        c.Sickle-=17;
    }
    c.Galleon=a.Galleon+b.Galleon+sign;
    cout<<c.Galleon<<"."<<c.Sickle<<"."<<c.Knut<<endl;
    return 0;
}
