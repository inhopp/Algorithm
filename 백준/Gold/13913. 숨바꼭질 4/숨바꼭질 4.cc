#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

int V[100005];
int P[100005];

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
    P[N] = N;

    while(!V[K]) {
        int x = Q.front();
        Q.pop();

        for(int nx : {x-1, x+1, 2*x}) {
            if (nx<0 || nx>=100001)
                continue;
            
            if (V[nx] == 0) {
                Q.push(nx);
                V[nx] = V[x] + 1;
                P[nx] = x;
            }
        }
    }

    cout << V[K] - 1 << endl;

    deque<int> track;
    track.push_front(K);

    while(track.front() != N) {
        track.push_front(P[track.front()]);
    }

    for (int t : track)
        cout << t << " ";
}