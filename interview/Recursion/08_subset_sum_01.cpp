class Solution {
  public:
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int>res;
        int sum=0;
        solve(0,arr,sum,res);
        return res;
    }
    void solve(int id, vector<int>&arr, int sum, vector<int>&res){
        if(id==arr.size()) {
            res.push_back(sum);
            return;
        }
        //take 
        solve(id+1,arr,sum+arr[id],res);
        //not take
        solve(id+1,arr,sum,res);
    }
};