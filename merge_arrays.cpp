#include <iostream>
#include <cmath>
using namespace std;

void swapIfGreater(int arr1[], int arr2[], int i, int j) {
    if (arr1[i] > arr2[j]) {
        int temp = arr1[i];
        arr1[i] = arr2[j];
        arr2[j] = temp;
    }
}

void merge(int arr1[], int m, int arr2[], int n) {
    int gap = ceil((float)(m + n) / 2);
    while (gap > 0) {
        int i = 0, j = gap;
        while (j < (m + n)) {
            if (j < m && i < m) {
                if (arr1[i] > arr1[j]) {
                    swap(arr1[i], arr1[j]);
                }
            } else if (i < m && j >= m) {
                swapIfGreater(arr1, arr2, i, j - m);
            } else {
                if (arr2[i - m] > arr2[j - m]) {
                    swap(arr2[i - m], arr2[j - m]);
                }
            }
            i++;
            j++;
        }
        if (gap == 1) gap = 0;
        else gap = ceil((float)gap / 2);
    }
}

int main() {
    int m, n;

    cout << "Enter the number of elements in arr1: ";
    cin >> m;
    cout << "Enter the number of elements in arr2: ";
    cin >> n;

    int arr1[m], arr2[n];

    cout << "Enter elements of arr1 in sorted order: ";
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    cout << "Enter elements of arr2 in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    merge(arr1, m, arr2, n);

    cout << "Merged arr1: ";
    for (int i = 0; i < m; i++) {
        cout << arr1[i] << " ";
    }

    cout << "\nMerged arr2: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }

    return 0;
}
