#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

int A[100005];
int State[100005];

const int NOT_VISITED = 0;
const int IN_CYCLE = -1;

void Check_Cycle(int x)
{
    int cur = x;

    while(true) {
        State[cur] = x;
        cur = A[cur];

        if (State[cur] == x) {
            while(State[cur] != IN_CYCLE) {
                State[cur] = IN_CYCLE;
                cur = A[cur];
            }

            return;
        }

        if (State[cur] != 0)
            return;
    }
}

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, N;
    cin >> T;

    while(T--) {
        cin >> N;

        for (int i = 1; i <= N; i++)
            cin >> A[i];

        for (int i = 1; i <= N; i++) {
            if (State[i] == NOT_VISITED)
                Check_Cycle(i);
        }

        int cnt = 0;

        for (int i = 1; i <= N; i++)
            if (State[i] != IN_CYCLE)
                cnt++;

        cout << cnt << endl;

        fill(State, State + N + 1, 0);
    }
}