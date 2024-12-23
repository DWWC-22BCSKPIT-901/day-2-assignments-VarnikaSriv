#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> remainders(batchSize, 0);
        int happyGroups = 0;

        // Count groups that are already happy
        for (int group : groups) {
            int remainder = group % batchSize;
            if (remainder == 0) {
                happyGroups++;
            } else {
                remainders[remainder]++;
            }
        }

        // Pair remainders to maximize happy groups
        for (int i = 1; i < batchSize; i++) {
            int complement = batchSize - i;
            if (i == complement) {
                happyGroups += remainders[i] / 2;
                remainders[i] %= 2;
            } else if (i < complement) {
                int pairs = min(remainders[i], remainders[complement]);
                happyGroups += pairs;
                remainders[i] -= pairs;
                remainders[complement] -= pairs;
            }
        }

        // Use dynamic programming to handle leftovers
        unordered_map<int, int> memo;
        happyGroups += dfs(remainders, batchSize, 0, memo);
        return happyGroups;
    }

private:
    int dfs(vector<int>& remainders, int batchSize, int currentRemainder, unordered_map<int, int>& memo) {
        int key = hashKey(remainders, currentRemainder);
        if (memo.count(key)) return memo[key];

        int maxGroups = 0;
        for (int i = 1; i < batchSize; i++) {
            if (remainders[i] > 0) {
                remainders[i]--;
                int nextRemainder = (currentRemainder + i) % batchSize;
                maxGroups = max(maxGroups, ((nextRemainder == 0) ? 1 : 0) + dfs(remainders, batchSize, nextRemainder, memo));
                remainders[i]++;
            }
        }

        memo[key] = maxGroups;
        return maxGroups;
    }

    int hashKey(const vector<int>& remainders, int currentRemainder) {
        int hash = currentRemainder;
        for (int rem : remainders) {
            hash = hash * 31 + rem;
        }
        return hash;
    }
};

int main() {
    Solution solution;

    // Example 1
    int batchSize1 = 3;
    vector<int> groups1 = {1, 2, 3, 4, 5, 6};
    cout << "Maximum Happy Groups: " << solution.maxHappyGroups(batchSize1, groups1) << endl;

    // Example 2
    int batchSize2 = 4;
    vector<int> groups2 = {4, 4, 4, 4};
    cout << "Maximum Happy Groups: " << solution.maxHappyGroups(batchSize2, groups2) << endl;

    return 0;
}
