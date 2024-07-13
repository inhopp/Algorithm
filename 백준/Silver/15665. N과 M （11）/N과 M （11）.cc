#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>

using namespace std;

int A[8];
int B[8];
int N, M;

void func(int s)
{
    if (s==M+1) {
        for (int i = 1; i <= M; i++)
            cout << B[i] << " ";
        cout << "\n";
        return;
    }

    int Prev = -1;
    for (int i = 1; i <= N; i++) {
        if (A[i] == Prev)
            continue;

        B[s] = A[i];
        Prev = A[i];
        func(s + 1);
    }
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    sort(A, A + N + 1);

    func(1);
}