class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {

        int n=nums.size();
        mergeSort(nums,0,n-1);
        return nums;
        
    }
    void mergeSort(vector<int>&nums,int left,int right){
        if(left>=right) return;
        int mid=(left+right)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
    void merge(vector<int>&nums,int left,int mid,int right){
        vector<int>temp;
        int l=left;
        int r=mid+1;
        while(l<=mid and r<=right){
            if(nums[l]<=nums[r]){
                temp.push_back(nums[l++]);
            }
            else temp.push_back(nums[r++]);
        }

        while(l<=mid) temp.push_back(nums[l++]);
        while(r<=right) temp.push_back(nums[r++]);
        for(int i=left;i<=right;i++){
            nums[i]=temp[i-left];
        }
    }
};