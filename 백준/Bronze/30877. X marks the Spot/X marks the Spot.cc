#include<iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;

    string input;
    getline(cin, input);
    
    while(N--) {
        input;
        getline(cin, input);
        
        int space = input.find(" ");
        string S,T;
        S = input.substr(0, space);
        T = input.substr(space+1, input.length());
        
        int P = S.find('x');
        if (P == -1) P = S.find('X');

        char c = T[P];
        if (c>='a' && c<='z')
            c += ('A' - 'a');

        cout << c;
    }

   return 0;
}