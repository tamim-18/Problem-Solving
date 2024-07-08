struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        //sort by the profit
        sort(arr,arr+n,cmp);
       int mx = 0;
        for(int i = 0; i < n; i++) mx = max(arr[i].dead, mx);
        // defining the slot array
       int slot[mx + 1];
       fill(slot, slot + mx + 1, -1);  // Initializes all elements to -1

        int cnt=0;
        int profit=0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>=0;j--){
                if(slot[j]==-1){
                    profit+=arr[i].profit;
                    cnt++;
                    slot[j] = i;
                    break;
                }
            }
           
            
        }
         return {cnt,profit};
        
    } 
   static bool cmp(Job a, Job b) { 
        return a.profit > b.profit; 
    }
};


/*
using dsu
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/


#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// Disjoint Set (Union-Find) class
class DisjointSet {
    vector<int> parent;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int find(int s) {
        if (s == parent[s]) return s;
        return parent[s] = find(parent[s]);
    }

    void merge(int u, int v) {
        parent[v] = u;
    }
};

class Solution {
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) {
        // Sort jobs by profit in descending order
        sort(arr, arr + n, [](Job a, Job b) { return a.profit > b.profit; });

        // Find the maximum deadline to determine the size of the disjoint set
        int mx = 0;
        for (int i = 0; i < n; i++) mx = max(arr[i].dead, mx);

        // Initialize disjoint set for managing free slots
        DisjointSet ds(mx);

        int cnt = 0;
        int profit = 0;

        // Iterate through all given jobs
        for (int i = 0; i < n; i++) {
            int availableSlot = ds.find(arr[i].dead);

            // If there's an available slot before the deadline
            if (availableSlot > 0) {
                profit += arr[i].profit;
                cnt++;
                ds.merge(ds.find(availableSlot - 1), availableSlot);  // Mark the slot as filled
            }
        }

        return {cnt, profit};
    }
};
