#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>

using namespace std;


int A[9];
int B[9];
vector<int> V = {0};
int N, M;

void func(int s)
{
    if (s==M+1) {
        for (int i = 1; i <= M; i++) {
            cout << A[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = -1;

    for (int i = 1; i <= N; i++)
    {
        if (B[i]==1 || prev == V[i])
            continue;

        B[i] = 1;
        A[s] = V[i];
        prev = V[i];
        func(s + 1);
        B[i] = 0;
    }
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int v;
    for (int i = 0; i < N; i++) {
        cin >> v;
        V.push_back(v);
    }

    sort(V.begin(), V.end());

    func(1);
}