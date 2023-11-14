#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
using namespace std;


int main()
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;
    int k = 0;
    int s = 0;
    int y = 0;
    int A[2][6] = { 0,  };

    cin >> n >> k;

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> y;

        A[s][y - 1]++;

        if (A[s][y - 1] == 1)
            res++;

        if (A[s][y - 1] == k)
            A[s][y - 1] = 0;
    }

    cout << res << '\n';
}