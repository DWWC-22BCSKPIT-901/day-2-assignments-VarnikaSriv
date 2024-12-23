#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> workers(k, 0); 
        int result = INT_MAX;
        sort(jobs.rbegin(), jobs.rend()); 
        backtrack(jobs, workers, 0, k, result);
        return result;
    }
private:
    void backtrack(vector<int>& jobs, vector<int>& workers, int jobIndex, int k, int& result) {
        if (jobIndex == jobs.size()) {
            result = min(result, *max_element(workers.begin(), workers.end()));
            return;
        }
        for (int i = 0; i < k; i++) {
            workers[i] += jobs[jobIndex];
            if (workers[i] < result) { 
                backtrack(jobs, workers, jobIndex + 1, k, result);
            }
            workers[i] -= jobs[jobIndex];
            if (workers[i] == 0) break;
        }
    }
};
int main() {
    Solution solution;
    vector<int> jobs1 = {3, 2, 3};
    int k1 = 3;
    cout << "Minimum Maximum Working Time: " << solution.minimumTimeRequired(jobs1, k1) << endl;
    vector<int> jobs2 = {1, 2, 4, 7, 8};
    int k2 = 2;
    cout << "Minimum Maximum Working Time: " << solution.minimumTimeRequired(jobs2, k2) << endl;
    return 0;
}
