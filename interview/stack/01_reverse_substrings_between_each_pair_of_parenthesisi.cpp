// approach 1

// time complexity": O(n^2)


class Solution {
public:
    string reverseParentheses(string s) {
        string res="";
        stack<int>st;
        for(auto u:s){
            if(u=='(') st.push(res.size());
            else if(u==')') {
                int skip=st.top();
                st.pop();
                reverse(begin(res)+skip,end(res));
            }
            else res+=u;
        }

        return res;
        
    }
};

// time complexity: O(n)

//Approach-2 (Linear Approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> openBracket;
        vector<int> door(n);

        // First pass: Pair up parentheses
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                openBracket.push(i);
            } else if (s[i] == ')') {
                int j = openBracket.top();
                openBracket.pop();
                door[i] = j;
                door[j] = i;
            }
        }

        // Second pass: Build the result string
        string result;
        int direction = 1; //Left to Right
        for (int i = 0; i < n; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = door[i];
                direction = -direction;
            } else {
                result += s[i];
            }
        }
        return result;
    }
};

