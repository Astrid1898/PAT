#include<iostream>
#include<iomanip>
using namespace std;
struct mynode
{
    int Address;
    int Date;
    int Next;
};
struct the_node
{
    int date;
    int Address;
    the_node *next;
};
int main()
{
    int the_first_address;
    int n,k;
    cin>>the_first_address>>n>>k;
    mynode the_nodes[n];
    for(int i=0;i<n;i++)
    {
        cin>>the_nodes[i].Address>>the_nodes[i].Date>>the_nodes[i].Next;
    }
    the_node* head;
    head=new the_node;
    head->date=0;
    head->Address=0;
    head->next=NULL;
    the_node* ptemp,*pnew;
    ptemp=head;
    while(the_first_address!=-1)
    {
        for(int i=0;i<n;i++)
            {
                if(the_nodes[i].Address==the_first_address)
                    {
                        pnew=new the_node;
                        pnew->date=the_nodes[i].Date;
                        pnew->Address=the_nodes[i].Address;
                        pnew->next=NULL;
                        ptemp->next=pnew;
                        ptemp=pnew;
                        the_first_address=the_nodes[i].Next;
                        break;
                    }
            }
    }
    the_node* pold;
    pnew=head->next;
    pold=pnew->next;
    for(int i=1;i<k;i++)
    {   
        ptemp=pold->next;
        pold->next=pnew;
        pnew=pold;
        pold=ptemp;
        if(pold->next==NULL)
            break;
    }
    head->next->next=pold;
    head->next=pnew;
    pnew=head;
    while(pnew->next->next!=NULL)
    {
        pnew=pnew->next;
        cout<<setw(5)<<setfill('0')<<pnew->Address<<' '<<pnew->date<<' '<<setw(5)<<setfill('0')<<pnew->next->Address<<endl;
    }
    pnew=pnew->next;
    cout<<setw(5)<<setfill('0')<<pnew->Address<<' '<<pnew->date<<' '<<-1;
    return 0;
}
