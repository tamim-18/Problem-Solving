class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //first I have to find the left part
        // then the overlapping part.
        // then the right part after overlap...
        vector<vector<int>>res;
        int i=0;
        //left part
        int n=intervals.size();
        while(i<n && newInterval[0]>intervals[i][1]){
            res.push_back(intervals[i]);
            i++;
        }
        //merge all the overlapping intervals
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;

        }
        res.push_back(newInterval);
        // right part
        while(i<n) {
            res.push_back(intervals[i]);
            i++;
        }


        return res;

        
    }
};

// time complexity O(n)


// I can do everything and solve every problem inshAllah.
