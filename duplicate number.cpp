#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findDuplicate(const vector<int>& arr) {
    unordered_map<int, int> numCount;
    for (int num : arr) {
        if (++numCount[num] > 1) {
            return num;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {3, 1, 3, 4, 2};
    int duplicate = findDuplicate(arr);
    cout << "Duplicate Number: " << duplicate << endl;
    return 0;
}
