#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

int V[100005];
queue<int> Q;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    Q.push(N);
    V[N] = 1;

    while(!Q.empty()) {
        int x = Q.front();
        Q.pop();

        if (x == K) {
            break;
        }

        if (2*x < 100005 && V[2*x] == 0) {
            Q.push(2 * x);
            V[2 * x] = V[x];
        }

        if (x-1 >= 0 && V[x-1] == 0) {
            Q.push(x - 1);
            V[x - 1] = V[x] + 1;
        }

        if (x+1 <= K && V[x+1] == 0) {
            Q.push(x + 1);
            V[x + 1] = V[x] + 1;
        }
    }

    cout << V[K]-1 << endl;
}