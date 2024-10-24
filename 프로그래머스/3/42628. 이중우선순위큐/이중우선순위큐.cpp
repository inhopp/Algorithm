#include <string>
#include <vector>
#include <queue>

using namespace std;




vector<int> solution(vector<string> operations) {
    priority_queue<int> Mx;
    priority_queue<int, vector<int>, greater<int>> Mx_Deleted;
    priority_queue<int, vector<int>, greater<int>> Mn;
    priority_queue<int> Mn_Deleted;

    int cnt = 0;

    for (string s : operations) {
        if (s[0] == 'I') {
            int val = stoi(s.substr(2, s.size()));
            Mx.push(val);
            Mn.push(val);
            cnt++;
        }

        else { // 'D'
            if (cnt == 0)
                continue;

            if (s[2] == '1') {
                while (!Mn_Deleted.empty() && Mx.top() == Mn_Deleted.top()) {
                    Mx.pop();
                    Mn_Deleted.pop();
                }

                Mx_Deleted.push(Mx.top());
                Mx.pop();
            }

            else { // -1
                while (!Mx_Deleted.empty() && Mn.top() == Mx_Deleted.top()) {
                    Mn.pop();
                    Mx_Deleted.pop();
                }

                Mn_Deleted.push(Mn.top());
                Mn.pop();
            }

            cnt--;
        }
    }

    vector<int> answer;
    while (!Mn_Deleted.empty() && Mx.top() == Mn_Deleted.top()) {
        Mx.pop();
        Mn_Deleted.pop();
    }
    while (!Mx_Deleted.empty() && Mn.top() == Mx_Deleted.top()) {
        Mn.pop();
        Mx_Deleted.pop();
    }

    if (Mx.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }

    else {
        answer.push_back(Mx.top());
        answer.push_back(Mn.top());
    }

    return answer;
}