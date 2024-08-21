class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        // Create a dp array to store whether a substring is a palindrome
        bool dp[n][n];
        memset(dp, 0, sizeof(dp)); // Initialize all entries to false
        
        int maxLength = 1; // Length of the longest palindrome found
        int start = 0;     // Starting index of the longest palindrome
        
        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        
        // Check for substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }
        
        // Check for substrings of length 3 and more
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                
                // Check if the current substring is a palindrome
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    
                    // Update the starting index and maxLength if a longer palindrome is found
                    if (len > maxLength) {
                        start = i;
                        maxLength = len;
                    }
                }
            }
        }
        
        // Return the longest palindromic substring
        return s.substr(start, maxLength);
    }
};


// without dp

