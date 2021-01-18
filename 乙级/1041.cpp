#include<iostream>
using namespace std;
struct examinee
{
    long long id;
    int exam_seat_number;
    int test_seat_number;
};
int main()
{
    int N;
    cin>>N;
    examinee PTA_examinees[N+1];
    int temp_exam_num,temp_test_num;
	long long temp_id;
    for(int i=0;i<N;i++)
    {
        cin>>temp_id>>temp_test_num>>temp_exam_num;
        PTA_examinees[temp_test_num].id=temp_id;
        PTA_examinees[temp_test_num].test_seat_number=temp_test_num;
        PTA_examinees[temp_test_num].exam_seat_number=temp_exam_num;
    }
	cout<<temp_id<<endl;
    int n;
    cin>>n;
	cout<<n;
/*
    int to_confirm[n];
    for(int i=0;i<n;i++)
    {
        cin>>to_confirm[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<PTA_examinees[to_confirm[i]].id<<' '<<PTA_examinees[to_confirm[i]].exam_seat_number<<endl;
    }*/
    return 0;
}
