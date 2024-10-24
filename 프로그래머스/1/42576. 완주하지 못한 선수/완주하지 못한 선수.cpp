#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> UM;

string solution(vector<string> participant, vector<string> completion) {
    for(string p : participant)
        UM[p] += 1;
    
    for(string c : completion) {
        if (UM[c] == 1)
            UM.erase(c);
        else
            UM[c] -= 1;
    }
    
    string answer = (*UM.begin()).first;
    return answer;
}