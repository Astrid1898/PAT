#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<string> s;
    string k;
    while(cin>>k)
        s.push(k);
    cout<<s.top();
    s.pop();
    while(!s.empty())
    {
        cout<<" "<<s.top();
        s.pop();
    }
    return 0;
}

