#include <string>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

int solution(string begin, string target, vector<string> words) {
    queue<pair<string, int>> Q;
    int V[words.size()];
    fill (V, V+words.size(), 0);
    
    for(int i=0; i<words.size(); i++) {
        int cnt=0;
        
        for(int j=0; j<begin.size(); j++)
            if (begin[j] != words[i][j])
                cnt++;
        
        if (cnt != 1)
            continue;
        
        Q.push({words[i], i});
        V[i] = 1;
    }
    
    while(!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        
        if (cur.X == target) {
            return V[cur.Y];
        }
        
        for(int i=0; i<words.size(); i++) {
            if (V[i] > 0)
                continue;
            
            int cnt = 0;
            for(int j=0; j<cur.X.size(); j++)
                if (cur.X[j] != words[i][j])
                    cnt++;
            
            if (cnt != 1)
                continue;
            
            Q.push({words[i], i});
            V[i] = V[cur.Y] + 1;
        }
    }
    
    return 0;
}