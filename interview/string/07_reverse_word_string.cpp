// pythoon

class Solution:
    def reverseWords(self, s: str) -> str:
        # Step 1: Split the string into words based on spaces
        words = s.split()
        
        # Step 2: Reverse the list of words
        words.reverse()
        
        # Step 3: Join the words back together with a single space
        reversed_string = ' '.join(words)
        
        return reversed_string



// js

var reverseWords = function(s) {
    // Step 1: Split the string into words based on spaces
    let words = s.trim().split(/\s+/);
    
    // Step 2: Reverse the array of words
    words.reverse();
    
    // Step 3: Join the words back together with a single space
    let reversedString = words.join(' ');
    
    return reversedString;
};


// c++

class Solution {
public:
    string reverseWords(string s) {
        s = trim(s);
        stringstream ss(s);
        vector<string> words;
        string word;
        
        // Extract words from stringstream
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Reverse the vector of words
        reverse(words.begin(), words.end());
        
        string res = "";
        
        // Build the result string with reversed words
        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) {
                res += " "; // Add space before appending the word (except for the first word)
            }
            res += words[i]; // Append the word
        }
        
        return res;
    }
    
    string trim(string & s) {
        int start = 0;
        int end = s.size() - 1;
        
        while (start <= end && s[start] == ' ') {
            start++;
        }
        
        // Trim spaces from the end
        while (end >= start && s[end] == ' ') {
            end--;
        }
        
        // Return trimmed substring
        return s.substr(start, end - start + 1);
    }
};
