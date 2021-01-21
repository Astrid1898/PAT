#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n;
    cin >> n;
    stack<int> st;
    int k(0);
    while (n != 0)
    {
        st.push(n % 10);
        n = n / 10;
    }
    k = st.size();
    switch (k)
    {
    case 3:
        for (int i = 0; i < st.top(); i++)
        {
            cout << "B";
        }
        st.pop();
    case 2:
        for (int i = 0; i < st.top(); i++)
        {
            cout << "S";
        }
        st.pop();
    case 1:
        for (int i = 1; i <= st.top(); i++)
        {
            cout << i;
        }
        st.pop();
    }
    return 0;
}