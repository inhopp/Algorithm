#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int length = numbers.size();
    int sz = 1 << length;
    int D[length];
    
    for (int brute = 0; brute < sz; brute++) {
        int temp = brute;
        
        for(int i = 0; i < length; i++) {
            D[i] = temp % 2;
            temp = temp / 2;
        }
        
        temp = 0;
        for(int i = 0; i < length; i++) {
            if (D[i] == 0)
                temp += numbers[i];
            else
                temp -= numbers[i];
        }
        
        if (temp == target)
            answer++;
        
    }
    
    return answer;
}