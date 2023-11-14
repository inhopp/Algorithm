#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;


int main()
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    int A[100];
    int v = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    cin >> v;

    int res = 0;

    for (int i = 0; i < n; i++)
        if (A[i] == v)
            res++;

    cout << res << '\n';
}