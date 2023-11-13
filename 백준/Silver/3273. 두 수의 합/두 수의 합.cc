#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;

int A[1000001];

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    cin >> n;

    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> idx;
        A[idx]++;
    }

    int v;
    cin >> v;

    int res = 0;
    int length = sizeof(A) / sizeof(int);

    for (int i = 0; i < length; i++)
    {
        if (A[i] == 1)
        {
            if (v <= i) continue;

            if (v - i >= length) continue;

            else if (A[v - i] == 1)
            {
                res++;
            }
        }
    }

    res /= 2;
    cout << res << endl;
}