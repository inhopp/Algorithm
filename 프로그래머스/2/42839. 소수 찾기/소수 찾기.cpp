#include <string>
#include <vector>
#include <math.h>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

const int MX = 9999999+2;
int Primes[MX];

void FillPrimes()
{
    Primes[0] = 1;
    Primes[1] = 1;
    int root = sqrt(MX);
    
    for(int i = 2; i <= root; i++) {
        if (Primes[i] == 1)
            continue;
        
        for(int j = i*i; j <= MX; j += i)
            Primes[j] = 1;
    }
    
    return;
}

int solution(string numbers) {
    FillPrimes();
    
    vector<char> nums;
    for(int i = 0; i < numbers.size(); i++)
        nums.push_back(numbers[i]);
    
    sort(nums.begin(), nums.end());
    unordered_set<int> US;
    
    do {
        string s = "";
        
        for(int i = 0; i < nums.size(); i++) {
            s += nums[i];
            US.insert(stoi(s));
        }
        
    } while(next_permutation(nums.begin(), nums.end()));
    
    int answer = 0;
    
    for(int val : US) {
        if (Primes[val] == 0)
            answer += 1;
    }
    
    return answer;
}