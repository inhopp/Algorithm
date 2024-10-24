#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> Q;
    int idx = 0;
    for(int p : priorities)
        Q.push({p, idx++});
    
    sort(priorities.begin(), priorities.end(), greater<int>()); 
    int max_idx = 0;
    int ans = 1;
    
    while(true) {
        auto cur = Q.front();
        Q.pop();
        
        if (cur.X != priorities[max_idx]) {
            Q.push(cur);
        }
        
        else {
            if (cur.Y == location) {
                return ans;
            }
            
            else {
                max_idx++;
                ans++;
            }
        }
    }
    
    return ans;
}