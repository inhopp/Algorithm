#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

#define X first
#define Y second

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return a.Y > b.Y;
}

int solution(vector<vector<int>> jobs) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, bool(*)(pair<int, int>& , pair<int, int>&)> pq(cmp); 
    
    int answer = 0;
    int time = 0;
    int idx = 0;
    
    sort(jobs.begin(), jobs.end());
    
    while(idx < jobs.size() || !pq.empty()) {
        if (pq.empty()) {
            pq.push({jobs[idx][0], jobs[idx][1]});
            idx++;
        }
        
        auto cur = pq.top();
        pq.pop();
        time = max(time, cur.X);
        time += cur.Y;
        answer += (time - cur.X);
        
        while(idx < jobs.size() && jobs[idx][0] <= time) {
            pq.push({jobs[idx][0], jobs[idx][1]});
            idx++;
        }
        
    }
    
    answer /= int(jobs.size());
    return answer;
}