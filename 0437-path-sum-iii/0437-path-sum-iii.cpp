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
    void solve(TreeNode* root , int k , int &count , long long sum , unordered_map<long long , int> &mp){
        if(root == NULL){
            return;
        }

        sum += root -> val;

        count += mp[sum-k];

        mp[sum]++;

        solve(root -> left , k , count , sum , mp);
        solve(root -> right , k , count , sum , mp);
        
        mp[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long , int> mp;

        int count = 0;
        mp[0] = 1;

        solve(root , targetSum , count , 0 , mp);

        return count;
    }
};