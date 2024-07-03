#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int A[65][65];

bool check(int r, int c, int n)
{
    int v = A[r][c];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (v != A[r+i][c+j])
                return false;

    return true;
}

void func(int r, int c, int n)
{
    if (check(r, c, n)) {
        cout << A[r][c];
        return;
    }

    else {
        cout << "(";
        func(r, c, n / 2);
        func(r, c + n / 2, n / 2);
        func(r + n / 2, c, n / 2);
        func(r + n / 2, c + n / 2, n / 2);
        cout << ")";
    }
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++) {
            A[i][j] = s[j] - '0';
        }
    }

    func(0, 0, N);
    cout << endl;
}