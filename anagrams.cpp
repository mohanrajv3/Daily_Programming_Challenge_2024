#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramGroups;
    
    for (string str : strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        anagramGroups[sortedStr].push_back(str);
    }
    
    vector<vector<string>> result;
    for (auto& group : anagramGroups) {
        result.push_back(group.second);
    }
    
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> groupedAnagrams = groupAnagrams(strs);
    
    for (const auto& group : groupedAnagrams) {
        cout << "[";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
