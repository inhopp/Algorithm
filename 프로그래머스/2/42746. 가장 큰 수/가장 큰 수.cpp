#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string& s1, string& s2) {
    return s1+s2 > s2+s1;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> V;
    for (int n : numbers) {
        V.push_back(to_string(n));
    }
    
    sort(V.begin(), V.end(), cmp);
    for(string s : V) {
        answer += s;
    }
    
    if (answer[0] == '0')
        return "0";
    
    return answer;
}