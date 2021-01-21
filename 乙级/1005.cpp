#include <iostream>
using namespace std;
int main()
{
    int k;
    cin >> k;
    int a[k];
    int b = 0;
    int i = 0;
    while (i < k)
    {
        cin >> a[i];
        i++;
    }
    for (i = 0; i < k; i++)
    {
        b = a[i];
        while (b != 1 && b != 0)
        {
            if (b % 2)
            {
                b = (3 * b + 1) / 2;
                for (int j = 0; j < k; j++)
                {
                    if (a[j] == b)
                        a[j] = 0;
                }
            }
            else
            {
                b = b / 2;
                for (int j = 0; j < k; j++)
                {
                    if (a[j] == b)
                        a[j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = k - 1; j > i; j--)
        {
            if (a[j] > a[j - 1])
            {
                b = a[j - 1];
                a[j - 1] = a[j];
                a[j] = b;
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (a[i] != 0 && a[i] != 1 && a[i + 1] != 0 && a[i + 1] != 1)
            cout << a[i] << " ";
        else if (a[i] != 0 && a[i] != 1)
            cout << a[i];
    }
    return 0;
}