#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    vector<int> N[n];
    
    for(int i = 0; i < computers.size(); i++) {
        for(int j=0; j<computers[i].size(); j++)
            if (computers[i][j] == 1) {
                N[i].push_back(j);
                N[j].push_back(i);
            }
    }
    
    int answer = 0;
    int vis[n];
    fill(vis, vis+n, 0);
    
    for(int i = 0; i < n; i++) {
        if (vis[i] == 1)
            continue;
        
        answer++;
        queue<int> Q;
        Q.push(i);
        vis[i] = 1;
        
        while(!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            
            for(int dest : N[cur]) {
                if (vis[dest] == 1)
                    continue;
                
                Q.push(dest);
                vis[dest] = 1;
            }
        }
    }
     
    
    return answer;
}