#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int A[9];
vector<int> V;
int N, M;

void func(int s)
{
    if (s==M+1) {
        for (int i = 1; i <= M; i++)
            cout << A[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        A[s] = V[i];
        func(s + 1);
    }
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    int v;
    V.push_back(0);
    for (int i = 0; i < N; i++)
    {
        cin >> v;
        V.push_back(v);
    }

    sort(V.begin(), V.end());

    func(1);
}