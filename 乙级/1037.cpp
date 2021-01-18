#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct money
{
    int Gallen;
    int Sickle;
    int Knut;
    int sign;
};
int trans_to_Knut(int Gallen,int Sickle,int Knut)
{
    int total;
    total=Gallen*17*29+Sickle*29+Knut;
    return total;
}
money trans_to_Gallen(int Knut)
{
    money change;
	change.sign=1;
    if(Knut<0)
        change.sign=0;
    Knut=abs(Knut);
    change.Gallen=Knut/(17*29);
    Knut=Knut%(17*29);
    change.Sickle=Knut/29;
    change.Knut=Knut%29;
    return change;
}
int main()
{
    money to_pay,payed,change;
    scanf("%d.%d.%d",&to_pay.Gallen,&to_pay.Sickle,&to_pay.Knut);
    scanf("%d.%d.%d",&payed.Gallen,&payed.Sickle,&payed.Knut);
    int change_Knut=0;  
    change_Knut=trans_to_Knut(payed.Gallen,payed.Sickle,payed.Knut)-trans_to_Knut(to_pay.Gallen,to_pay.Sickle,to_pay.Knut);
    change=trans_to_Gallen(change_Knut);
    cout<<change.Gallen<<'.'<<change.Sickle<<'.'<<change.Knut;
    return 0;
}
