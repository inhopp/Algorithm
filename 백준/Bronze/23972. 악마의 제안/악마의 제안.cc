#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
    long long K, N;
    cin >> K >> N;
    
    if (N == 1)
        cout << -1 << endl;
    
    else {
        long long res = (N * K) / (N - 1);
        if ((N*K) % (N-1) != 0)
            res++;
        cout << res << endl;
    }
        
    
}