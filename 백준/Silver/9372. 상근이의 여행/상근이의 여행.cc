#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T, N, M;
    cin >> T;
    
    while(T--) {
        cin >> N >> M;
        int x,y;
        
        for(int i=0; i<M; i++)
            cin >> x >> y;
        
        cout << N-1 << "\n";
    }
    
    return 0;
}