#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int N;
    int tag = 1;
    int n = 3, number = 0, d = 0;
    cin >> N;
    for (int i = 4; i <= N; i++)
    {
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                tag = 0;
                break;
            }
        }
        if (tag)
        {
            d = i - n;
            n = i;
        }
        if (d == 2)
        {
            number = number + 1;
        }
        tag = 1;
        d = 0;
    }
    cout << number;
    return 0;
}