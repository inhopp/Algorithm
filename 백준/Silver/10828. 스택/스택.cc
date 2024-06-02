#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>

using namespace std;

stack<int> S;

int main(void)
{
    // freopen("input.txt", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string s;
    int v;

    while (N--)
    {
        cin >> s;

        if (s == "push") {
            cin >> v;
            S.push(v);
        }

        else if (s == "top") {
            if (!S.empty()) {
                cout << S.top() << "\n";
            }
            
            else
                cout << -1 << "\n";
        }

        else if (s == "pop") {
            if (!S.empty()) {
                cout << S.top() << "\n";
                S.pop();
            }

            else
                cout << -1 << "\n";
        }

        else if (s == "size") {
            cout << S.size() << "\n";
        }

        else { // "empty"
            cout << S.empty() << "\n";
        }
    }
}