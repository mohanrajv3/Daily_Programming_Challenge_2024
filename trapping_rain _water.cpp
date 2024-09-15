#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trapRainWater(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> leftMax(n), rightMax(n);
    int waterTrapped = 0;

    leftMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    for (int i = 0; i < n; i++) {
        waterTrapped += min(leftMax[i], rightMax[i]) - height[i];
    }

    return waterTrapped;
}

int main() {
    int n;
    cout << "Enter the number of bars: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the height of the bars: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    int result = trapRainWater(height);
    cout << "Total units of water trapped: " << result << endl;

    return 0;
}
