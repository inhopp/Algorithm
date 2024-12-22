#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> UM;

string solution(vector<string> participant, vector<string> completion) {
    for(string name : participant)
        UM[name] += 1;
    
    for(string name : completion) {
        UM[name] -= 1;
        if (UM[name] == 0)
            UM.erase(name);
    }
    
    string answer = (*UM.begin()).first;
    return answer;
}