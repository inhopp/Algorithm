#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    int A1[5] = {1,2,3,4,5};
    int A2[8] = {2,1,2,3,2,4,2,5};
    int A3[10] = {3,3,1,1,2,2,4,4,5,5};
    
    int cnt[3] = {0,0,0};
    
    for(int i = 0; i < answers.size(); i++) {
        int ans = answers[i];
        if (ans == A1[i%5]) cnt[0]++;
        if (ans == A2[i%8]) cnt[1]++;
        if (ans == A3[i%10]) cnt[2]++;
    }
    
    vector<int> answer;
    int mx = max({cnt[0], cnt[1], cnt[2]});
    for(int i = 0; i < 3; i++)
        if (cnt[i] == mx)
            answer.push_back(i+1);
    
    return answer;
}