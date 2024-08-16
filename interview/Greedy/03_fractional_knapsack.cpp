class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        double sum=0;
        vector<pair<double,int>>v;
        for(int i=0;i<n;i++){
            int val=arr[i].value;
            int w=arr[i].weight;
            double per=val/(w*1.0);
            v.push_back({per,w});
        }
        sort(v.rbegin(),v.rend());
        for(auto u:v){
            if(u.second<=w){
                sum+=(u.first)*(u.second);
                w-=u.second;
            }
            else {
                sum+=u.first*w;
                break;
            }
        }
        return sum;
        
    }
};
