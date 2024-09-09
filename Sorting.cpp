#include <iostream>
#include <vector>

using namespace std;

void dutchNationalFlag(vector<int>& arr) {
    int low = 0, mid = 0, high = arr.size() - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {0, 1, 2, 1, 0, 2, 1, 0};
    dutchNationalFlag(arr1);
    printArray(arr1);

    vector<int> arr2 = {2, 2, 2, 2};
    dutchNationalFlag(arr2);
    printArray(arr2);

    vector<int> arr3 = {0, 0, 0, 0};
    dutchNationalFlag(arr3);
    printArray(arr3);

    vector<int> arr4 = {1, 1, 1, 1};
    dutchNationalFlag(arr4);
    printArray(arr4);

    vector<int> arr5 = {2, 0, 1};
    dutchNationalFlag(arr5);
    printArray(arr5);

    vector<int> arr6 = {};
    dutchNationalFlag(arr6);
    printArray(arr6);

    return 0;
}
