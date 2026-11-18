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
    void solve(TreeNode* root , int k , int  &count , vector<int> output){
        if(root == NULL){
            return;
        }
        
        output.push_back(root -> val);
        
        solve(root -> left , k , count , output);
        solve(root -> right , k , count , output);
        
        long long sum = 0;
        for(int i = output.size() - 1 ; i >= 0 ; i--){
            sum += output[i];
            if(sum == k){
                count++;
            }
        }
        
        output.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> output;
        
        int count = 0;
        
        solve(root , targetSum , count , output);
        
        return count;
    }
};