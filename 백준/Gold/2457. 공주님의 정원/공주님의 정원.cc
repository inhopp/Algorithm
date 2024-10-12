#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

vector<pair<int, int>> V;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, sm, sd, em, ed;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> sm >> sd >> em >> ed;
        V.push_back({ sm * 100 + sd, em * 100 + ed });
    }

    int ans = 0, t = 301, next_t;

    while (t < 1201) {
        next_t = t;

        for (auto v : V) {
            if (v.first <= t && v.second > next_t) {
                next_t = v.second;
            }
        }

        if (t == next_t) {
            cout << 0 << endl;
            return 0;
        }

        t = next_t;
        ans++;
    }

    cout << ans << endl;
}