#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
#define X first
#define Y second

unordered_map<string, int> Counts;
// [genre] : <play, id>
unordered_map<string, vector<pair<int, int>>> UM;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i = 0; i < genres.size(); i++) {
        string genre = genres[i];
        int play = plays[i];
        
        Counts[genre] += play;
        UM[genre].push_back({play, i});
    }
    
    vector<pair<int, string>> Temp;
    for(auto count : Counts) {
        Temp.push_back({count.Y, count.X});
    }
    sort(Temp.begin(), Temp.end());
    
    for(int i = 1; i <= Temp.size(); i++) {
        string genre = Temp[Temp.size() - i].Y;
        
        if (UM[genre].size() == 1) {
            answer.push_back(UM[genre][0].Y);
            continue;
        }
        
        sort(UM[genre].begin(), UM[genre].end(), 
             [](auto& a, auto& b){
                 if (a.X==b.X) 
                     return a.Y < b.Y; 
                 else 
                     return a.X > b.X;
             });
        answer.push_back(UM[genre][0].Y);
        answer.push_back(UM[genre][1].Y);
    }
    
    return answer;
}