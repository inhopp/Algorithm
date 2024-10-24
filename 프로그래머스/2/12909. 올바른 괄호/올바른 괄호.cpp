#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> S;
    
    for(int i=0; i<s.size(); i++) {
        if (s[i] == '(') {
            S.push(s[i]);
        }
        
        else {
            if (S.empty())
                return false;
            S.pop();
        }
    }
    
    if (!S.empty())
        return false;
    
    return true;
}