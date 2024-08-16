// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int n=word1.size();
//         int m=word2.size();
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return f(n-1,m-1,word1,word2,dp);
        
//     }
//     int f(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
//         if(i<0) return j+1;
//         if(j<0) return i+1;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s1[i]==s2[j]) return dp[i][j]=f(i-1,j-1,s1,s2,dp);
//         return dp[i][j]=1+min(f(i,j-1,s1,s2,dp),min(f(i-1,j,s1,s2,dp),f(i-1,j-1,s1,s2,dp)));
//     }
// };

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill the first row and first column
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;  // If word2 is empty, delete all characters of word1
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;  // If word1 is empty, insert all characters of word2
        }

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];  // Characters match, no operation needed
                } else {
                    dp[i][j] = 1 + min(dp[i-1][j],      // Delete
                                       min(dp[i][j-1],  // Insert
                                           dp[i-1][j-1] // Replace
                                       )
                                );
                }
            }
        }

        return dp[n][m];
    }
};

// recursive
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();
//         return f(n-1, m-1, word1, word2);
//     }

//     int f(int i, int j, string &s1, string &s2) {
//         if (i < 0) return j + 1; // If word1 is exhausted, insert remaining word2 characters
//         if (j < 0) return i + 1; // If word2 is exhausted, delete remaining word1 characters
        
//         if (s1[i] == s2[j]) return f(i-1, j-1, s1, s2); // If characters match, move both pointers
        
//         return 1 + min(f(i, j-1, s1, s2),        // Insert operation
//                        min(f(i-1, j, s1, s2),    // Delete operation
//                            f(i-1, j-1, s1, s2)   // Replace operation
//                        )
//                 );
//     }
// };
