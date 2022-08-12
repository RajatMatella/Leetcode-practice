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
    TreeNode* solve(vector<int>& nums, int s, int e){
        if(s>e)
            return NULL;
            
        int mid = s + (e-s)/2;
        TreeNode *temp = new TreeNode();
        temp->val = nums[mid];
        
        temp->left = solve(nums, s, mid-1);
        temp->right = solve(nums, mid+1, e);
        
        return temp;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1){
            TreeNode *root = new TreeNode(nums[0]);
            return root;
        }
        
        
        return solve(nums, 0, n-1);
    }
};
