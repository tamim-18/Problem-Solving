// using stack.. taking extra space... 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // first sort the intervals
        sort(intervals.begin(),intervals.end());
        stack<vector<int>>st;
        for(auto interval:intervals){
            if(st.empty()) st.push(interval);
            else {
                vector<int>top=st.top();
                if(interval[0]<=top[1]){
                    top[1]=max(interval[1],top[1]);
                    st.pop();
                    st.push(top); // top is a vector....
                }
                else st.push(interval);
            }
        }
        vector<vector<int>>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
        
    }
};


//Process 2 without using extra space.. O(1) space 



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals based on start time
        sort(intervals.begin(), intervals.end());

        // Step 2: Merge intervals in place
        int index = 0; // Keeps track of the position of the last non-overlapping interval
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[index][1] >= intervals[i][0]) {
                // Overlapping intervals, merge them
                intervals[index][1] = max(intervals[index][1], intervals[i][1]);
            } else {
                // Non-overlapping interval, move to the next position
                index++;
                intervals[index] = intervals[i];
            }
        }

        // Resize the vector to contain only the merged intervals
        intervals.resize(index + 1);
        return intervals;
    }
};
