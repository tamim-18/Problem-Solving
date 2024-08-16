/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
         vector<int> vis(100001, 0);
        
        for(auto u:descriptions){
            int parent=u[0];
            int child=u[1];
            int pos=u[2];
            if(mp.find(parent)==mp.end()) mp[parent]=new TreeNode(parent);
            if(mp.find(child)==mp.end()) mp[child]=new TreeNode(child);
            if(pos==1) mp[parent]->left=mp[child];
            else mp[parent]->right=mp[child];
            vis[child]=1;

        }
        for(auto u:descriptions){
            if(!vis[u[0]]) return mp[u[0]];       //cecking for the root
        }
        return nullptr;
        
    }
};