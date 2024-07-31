#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <tuple>
#include <map>
#include <math.h>

using namespace std;

#define X first
#define Y second

int A[505][505];
int ans;

pair<int, int> T[19][4] = {
	{{0,0}, {0,1}, {1,0}, {1,1}},

	{{0,0}, {0,1}, {0,2}, {0,3}},
	{{0,0}, {1,0}, {2,0}, {3,0}},

	{{0,0}, {1,0}, {1,1}, {2,1}},
	{{0,1}, {0,2}, {1,0}, {1,1}},
	{{0,1}, {1,0}, {1,1}, {2,0}},
	{{0,0}, {0,1}, {1,1}, {1,2}},

	{{0,0}, {1,0}, {1,1}, {2,0}},
	{{0,1}, {1,0}, {1,1}, {1,2}},
	{{0,1}, {1,0}, {1,1}, {2,1}},
	{{0,0}, {0,1}, {0,2}, {1,1}},

	{{0,0}, {1,0}, {2,0}, {2,1}},
	{{0,0}, {0,1}, {0,2}, {1,0}},
	{{0,0}, {0,1}, {1,1}, {2,1}},
	{{0,2}, {1,0}, {1,1}, {1,2}},
	{{0,1}, {1,1}, {2,1}, {2,0}},
	{{0,0}, {1,0}, {1,1}, {1,2}},
	{{0,0}, {0,1}, {1,0}, {2,0}},
	{{0,0}, {0,1}, {0,2}, {1,2}}
};

int main(void)
{
	// freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) 
			for (int k = 0; k < 19; k++) {
				int sum = 0;

				for (int l = 0; l < 4; l++) {
					auto cur = T[k][l];
					sum += A[i + cur.X][j + cur.Y];
				}

				ans = max(ans, sum);
			}
	
	cout << ans << endl;
}