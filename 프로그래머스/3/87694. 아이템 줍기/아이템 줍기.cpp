#include <string>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

int Board[102][102];
int V[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void Init()
{
    for(int i=0; i<102; i++) {
        fill(Board[i], Board[i]+102, 0);
        fill(V[i], V[i]+102, 0);
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    Init();
    
    for(int i = 0; i < rectangle.size(); i++) {
        auto R = rectangle[i];
        pair<int, int> start = {R[0]*2, R[1]*2};
        pair<int, int> end = {R[2]*2, R[3]*2};
        
        for(int x = start.X; x <= end.X; x++) {
            if (Board[x][start.Y] == 0)
                Board[x][start.Y] = 1;
            
            if (Board[x][end.Y] == 0)
                Board[x][end.Y] = 1;
        }
        
        for(int y = start.Y; y <= end.Y; y++) {
            if (Board[start.X][y] == 0)
                Board[start.X][y] = 1;
            
            if (Board[end.X][y] == 0)
                Board[end.X][y] = 1;
        }
        
        for(int x = start.X+1; x < end.X; x++)
            for (int y = start.Y+1; y < end.Y; y++)
                Board[x][y] = -1;
    }
    
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    queue<pair<int, int>> Q;
    Q.push({characterX, characterY});
    V[characterX][characterY] = 1;
    
    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        
        if (cur.X == itemX && cur.Y == itemY)
            break;
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if (nx<1 || nx>100 || ny<1 || ny>100)
                continue;
            
            if (Board[nx][ny] != 1 || V[nx][ny] > 0)
                continue;
            
            Q.push({nx, ny});
            V[nx][ny] = V[cur.X][cur.Y] + 1;
        }
    }
    
    return (V[itemX][itemY] - 1)/2;
}