#include<iostream>
#include<iomanip>
using namespace std;
struct node
{
    int date;
    int address;
	node():date(0),address(-1){};
};
void print_the_list(node *p,int star_adress)
{
    int next_address=star_adress;
    while(next_address!=-1)
    {
        cout<<setw(5)<<setfill('0')<<next_address;
        cout<<' '<<(p+next_address)->date;
        next_address=(p+next_address)->address;
        if(next_address==-1)
            cout<<' '<<-1<<endl;
        else
            cout<<' '<<setw(5)<<setfill('0')<<next_address<<endl;
    }
}
int main()
{
    node* p=new node[100000];
    int star_adress,n,k;
    cin>>star_adress>>n>>k;
    for(int i=0;i<n;i++)
    {
        int this_address;
        cin>>this_address;
        cin>>(p+this_address)->date>>(p+this_address)->address;
    }
    int nega_head=-1;
    node *nega_tail=nullptr;
    int k_head=-1;
    node* k_tail=nullptr;
    int sign_nega=1;
    int sign_k=1;
    while((p+star_adress)->date<=k)
    {
    if((p+star_adress)->date<0)
    {
        if(sign_nega)
            nega_head=star_adress;
        nega_tail=p+star_adress;
        star_adress=(p+star_adress)->address;
        nega_tail->address=-1;
        sign_nega=0;
    }
    else
    {
        if(sign_k)
            k_head=star_adress;
        k_tail=p+star_adress;
        star_adress=(p+star_adress)->address;
        k_tail->address=-1;
        sign_k=0;
    }
    }
    int next_address=star_adress;
	while(next_address!=-1&&((p+next_address)->address!=-1))
	{
        int sign=1;
        node* next=p+((p+next_address)->address);
        if(next->date<0)
        {
            if(sign_nega)
            {
                nega_head=(p+next_address)->address;
                nega_tail=next;
                (p+next_address)->address=next->address;
                if(next->address==-1)
                    break;
                next->address=-1;
				sign_nega=0;
                sign=0;
            }
            else
            {
                nega_tail->address=(p+next_address)->address;
                nega_tail=next;
                (p+next_address)->address=next->address;
                if(next->address==-1)
                    break;
                next->address=-1;
                sign=0;
            }
        }
        else if(next->date<=k)
        {
            if(sign_k)
            {
                k_head=(p+next_address)->address;
                k_tail=next;
                (p+next_address)->address=next->address;
                if(next->address==-1)
                    break;
                next->address=-1;
				sign_k=0;
                sign=0;
            }
            else
            {
                k_tail->address=(p+next_address)->address;
                k_tail=next;
                (p+next_address)->address=next->address;
                if(next->address==-1)
                    break;
                next->address=-1;
                sign=0;
            }
        }
        if(sign)
            next_address=(p+next_address)->address;
    }
    if(!sign_k&&!sign_nega)
    {
        k_tail->address=star_adress;
        star_adress=nega_head;
        nega_tail->address=k_head;
    }
    else if(!sign_k)
    {
        k_tail->address=star_adress;
        star_adress=k_head;
    }
    else if(!sign_nega)
    {
        nega_tail->address=star_adress;
        star_adress=nega_head;
    }
    print_the_list(p,star_adress);
    delete[] p;
	return 0;
}
