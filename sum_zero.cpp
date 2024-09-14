#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> findZeroSumSubarrays(vector<int>& arr) {
    unordered_map<int, vector<int>> prefixSumMap;
    vector<pair<int, int>> result;
    int sum = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        
        if (sum == 0) {
            result.push_back({0, i});
        }
        
        if (prefixSumMap.find(sum) != prefixSumMap.end()) {
            for (int start : prefixSumMap[sum]) {
                result.push_back({start + 1, i});
            }
        }
        
        prefixSumMap[sum].push_back(i);
    }
    
    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<pair<int, int>> subarrays = findZeroSumSubarrays(arr);

    if (subarrays.empty()) {
        cout << "No subarrays with zero sum found." << endl;
    } else {
        cout << "Subarrays with zero sum:" << endl;
        for (const auto& subarray : subarrays) {
            cout << "(" << subarray.first << ", " << subarray.second << ")" << endl;
        }
    }

    return 0;
}
