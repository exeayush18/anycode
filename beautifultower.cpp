#include <iostream>
#include <vector>

using namespace std;

// Function to check if it's possible to achieve a beautiful configuration with a given maxSum
bool canAchieveBeautifulConfiguration(vector<int>& maxHeights, vector<int>& heights, int maxSum) {
    int n = maxHeights.size();
    int prev_height = 0;
    
    for (int i = 0; i < n; i++) {
        int min_height = maxHeights[i];
        int max_height = min(prev_height + maxHeights[i], heights[i]);
        
        if (min_height > max_height) {
            return false;
        }
        
        prev_height = max_height;
    }
    
    return true;
}

// Function to find the maximum possible sum of heights
int maxBuilding(vector<int>& maxHeights, vector<int>& heights) {
    int n = maxHeights.size();
    int left = 0;
    int right = 1e9; // A large upper bound for binary search
    
    while (left < right) {
        int mid = (left + right) / 2;
        if (canAchieveBeautifulConfiguration(maxHeights, heights, mid)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left - 1; // Subtract 1 to get the maximum sum of heights
}

int main() {
    vector<int> maxHeights = {4, 2, 3, 1};
    vector<int> heights = {0, 1, 2, 3}; // You can set your own heights
    int result = maxBuilding(maxHeights, heights);
    cout << "Maximum possible sum of heights: " << result << endl;
    return 0;
}
