#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;  // Start pointer
        int right = height.size() - 1;  
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int currentHeight = min(height[left], height[right]);
            int currentArea = width * currentHeight;

            // Update the maximum area found so far
            maxWater = max(maxWater, currentArea);

            // Move the pointer with the smaller height inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution solution;
    int result = solution.maxArea(height);
    cout << "The maximum amount of water the container can store is: " << result << endl;
    return 0;
}
