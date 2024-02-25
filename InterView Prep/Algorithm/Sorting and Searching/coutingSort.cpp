class Solution {
public:
    void sortColors(vector<int>& nums) {
        int max_el=INT_MIN;
        int n=nums.size();
        for(auto u:nums)
        {
            max_el=max(max_el,u);
        }
        // cout<<max_el<<endl;
        int count[max_el+1];
        for(int i=0;i<max_el+1;i++) count[i]=0;
        for(int i=0;i<n;i++)
        {
            count[nums[i]]++;
        }
        // cout<<count[0];
        nums.clear();
        int i=0;
        for(int j=0;j<max_el+1;j++)
        {
            while(count[j])
            {
                nums.push_back(j);
                count[j]--;
            }
        }


        
    }
};
//counting sort
// Time: O(n)
// Space: O(n)
//Algo:
// 1. Find the maximum element in the array.
// 2. Create a count array of size max_el+1 and initialize it with 0.
// 3. Traverse the array and increment the count of the element in the count array.
// 4. Traverse the count array and fill the original array with the elements in the count array.
// 5. Done.