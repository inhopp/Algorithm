#include <iostream>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, X;
    cin >> N >> X;
    
    for(int i=0; i<N; i++) {
        int val;
        cin >> val;
        if (val < X)
            cout << val << " ";
    }
    cout << "\n";
    
    return 0;
}