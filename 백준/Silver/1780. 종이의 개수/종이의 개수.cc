#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int A[2200][2200];
int res[3];

bool check(int r, int c, int n)
{
    int v = A[r][c];
    for (int i = r; i < r + n; i++)
        for (int j = c; j < c + n; j++)
            if (A[i][j] != v)
                return false;

    return true;
}

void func(int r, int c, int n)
{
    if (n==1) {
        res[A[r][c] + 1]++;
        return;
    }

    bool flag = check(r, c, n);

    if (flag) {
        res[A[r][c] + 1]++;
        return;
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            func(r + (n / 3) * i, c + (n / 3) * j, n / 3);
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    func(0, 0, N);

    cout << res[0] << endl;
    cout << res[1] << endl;
    cout << res[2] << endl;
}