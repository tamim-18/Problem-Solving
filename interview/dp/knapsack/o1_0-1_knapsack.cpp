#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // Creating a 2D array to store the results of subproblems
        int dp[n+1][W+1];

        // Initializing the base case
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= W; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }

        // Filling the dp array
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= W; j++) {
                if(wt[i-1] <= j) {
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        // To store the result of the max value
        int res = dp[n][W];
        cout << "Maximum value: " << res << endl;

        // To store the weights and values that are included in the knapsack
        vector<int> included_weights;
        vector<int> included_values;

        int w = W;
        for(int i = n; i > 0 && res > 0; i--) {
            if(res == dp[i-1][w])
                continue; // Item not included
            else {
                // Item included
                included_weights.push_back(wt[i-1]);
                included_values.push_back(val[i-1]);
                
                // Since this weight is included, its value is deducted
                res = res - val[i-1];
                w = w - wt[i-1];
            }
        }

        // Printing the included weights and values
        cout << "Included weights: ";
        for(int i = included_weights.size() - 1; i >= 0; i--)
            cout << included_weights[i] << " ";
        cout << endl;

        cout << "Included values: ";
        for(int i = included_values.size() - 1; i >= 0; i--)
            cout << included_values[i] << " ";
        cout << endl;

        return dp[n][W];
    }
};

int main() {
    Solution sol;
    int W = 50; // Capacity of knapsack
    int wt[] = {10, 20, 30};
    int val[] = {60, 100, 120};
    int n = sizeof(val) / sizeof(val[0]);
    sol.knapSack(W, wt, val, n);
    return 0;
}
