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

#define X first
#define Y second

unordered_map<string, int> M;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, L;
    cin >> K >> L;

    int idx = 0;

    while (L--) {
        string id;
        cin >> id;

        M[id] = idx++;
    }

    vector<pair<string, int>> V(M.begin(), M.end());

    sort(V.begin(), V.end(), [](auto &a, auto &b)
         { return a.Y < b.Y; });

    int mn = min(K, int(V.size()));
    for (int i = 0; i < mn; i++)
        cout << V[i].X << "\n";
}