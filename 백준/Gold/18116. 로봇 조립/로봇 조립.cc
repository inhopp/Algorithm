#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define MX 1000000

int P[1000005];
int Count[1000005];

int find(int x)
{
    while(P[x] > 0)
        x = P[x];

    return x;
}

void uniFind(int u, int v)
{
    int r1 = find(u);
    int r2 = find(v);

    if (r1 == r2)
        return;

    if (P[r1] == P[r2]) {
        P[r1]--;
        P[r2] = r1;
        Count[r1] += Count[r2];
    }

    else {
        if (P[r1] < P[r2]) {
            P[r2] = r1;
            Count[r1] += Count[r2];
        }

        else {
            P[r1] = r2;
            Count[r2] += Count[r1];
        }
    }

    return;
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, a, b, c;
    char ch;

    cin >> N;
    fill(P + 1, P + MX + 1, -1);
    fill(Count + 1, Count + MX + 1, 1);

    while (N--)
    {
        cin >> ch;

        if (ch == 'I') {
            cin >> a >> b;
            uniFind(a, b);
        }

        else { // ch == 'Q'
            cin >> c;
            int root = find(c);
            cout << Count[root] << "\n";
        }
    }

    return 0;
}