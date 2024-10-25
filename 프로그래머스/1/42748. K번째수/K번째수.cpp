#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int Temp[101];
    for(int i = 0; i < commands.size(); i++) {
        int start = commands[i][0] - 1;
        int end = commands[i][1];
        int k = commands[i][2] - 1;
        int length = end - start;
        
        memcpy(Temp, &array[start], sizeof(int)*length);
        sort(Temp, Temp + length);
        
        answer.push_back(Temp[k]);
        fill(Temp, Temp + length, 0);
    }
    
    
    return answer;
}