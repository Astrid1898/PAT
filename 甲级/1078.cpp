/*
平凡探测散列
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int nextPrime(int m);
inline bool isPrime(int);
int sign=0;
int main()
{
    int m,n;
    cin>>m>>n;
    m=nextPrime(m); //确定大小
    vector<int> hashTable(m,-1);
    while(n--)
    {
        int tmp;
        cin>>tmp;
        int hashValue=tmp%m;
        int success=0;
        for(int i=0;i<m;i++)    //解决冲突
        {
            if(hashTable[(hashValue+i*i)%m]==-1)
            {
                hashValue=(hashValue+i*i)%m;
                hashTable[hashValue]=tmp;
                success=1;
                break;
            }

        }
        if(success==0)
        {
            if(sign)
                cout<<" -";
            else
            {
                cout<<"-";
                sign=1;
            }
        }
        else
        {
            if(sign)
                cout<<" "<<hashValue;
            else
            {
                cout<<hashValue;
                sign=1;
            }
        }
    }
    cout<<endl;
    return 0;
}
int nextPrime(int m)
{
    while(!isPrime(m))
    {
        m++;
    }
    return m;
}
inline bool isPrime(int m)
{
    if(m<=1)
        return false;
    for(int i=2;i<=sqrt(m);i++)
    {
        if(m%i==0)
        {
            return false;
        }
    }
    return true;
}
