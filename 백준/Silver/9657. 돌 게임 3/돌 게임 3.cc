#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

// SK=1, CY=0
int D[1005];

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    D[1] = 1;
    D[2] = 0;
    D[3] = 1;
    D[4] = 1;

    for (int i = 5; i <= N; i++) {
        if (D[i-1]+D[i-3]+D[i-4] < 3)
            D[i] = 1;
        else
            D[i]=0;
    }

    if (D[N] == 1)
        cout << "SK" << endl;
    else
        cout << "CY" << endl;
}