#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<string, int> UM;

int solution(vector<vector<string>> clothes) {
    for(auto clo : clothes) {
        UM[clo[1]] += 1;
    }
    
    int answer = 1;
    for(auto p : UM) {
        answer *= p.second + 1;
    }
    
    return answer - 1;
}