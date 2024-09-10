#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(const vector<int>& arr) {
    int n = arr.size() + 1;
    int totalSum = n * (n + 1) / 2;
    int arrSum = 0;
    for (int num : arr) {
        arrSum += num;
    }
    return totalSum - arrSum;
}

int main() {
    vector<int> arr = {1, 2, 4, 5};
    int missingNumber = findMissingNumber(arr);
    cout << "Missing number: " << missingNumber << endl;
    return 0;
}
