// top down

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int dp[n+1][m+1];
        
        // Initialize the dp array
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) dp[i][j] = 0;
            }
        }

        // Fill the dp array
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // Reconstruct the LCS from the dp array
        string lcs = "";
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (text1[i-1] == text2[j-1]) {
                lcs = text1[i-1] + lcs;
                i--;
                j--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }

        cout << "LCS: " << lcs << endl;
        return dp[n][m];
    }
};

// memorization  

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return lcs(text1, text2, n, m, dp);
    }

    int lcs(const string& x, const string& y, int n, int m, vector<vector<int>>& dp) {
        if (n == 0 || m == 0) return 0;
        if (dp[n][m] != -1) return dp[n][m];
        if (x[n - 1] == y[m - 1]) 
            return dp[n][m] = 1 + lcs(x, y, n - 1, m - 1, dp);
        else 
            return dp[n][m] = max(lcs(x, y, n, m - 1, dp), lcs(x, y, n - 1, m, dp));
    }
};



// recursion tle
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        return lcs(text1,text2,n,m);
        
    }
    int lcs(string x,string y, int n,int m){
        if(n==0 or m==0) return 0;
        if(x[n-1]==y[m-1]) return 1+lcs(x,y,n-1,m-1);
        else return max(lcs(x,y,n,m-1) , lcs(x,y,n-1,m));
    }
};

// 
