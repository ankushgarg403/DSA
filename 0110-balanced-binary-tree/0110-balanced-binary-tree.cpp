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
private:
    int height(TreeNode* root , bool &flag){
        if(root == NULL){
            return 0;
        }

        int left = height(root -> left , flag);
        int right = height(root -> right , flag);

        if(abs(left - right) > 1){
            flag = false;
        }
        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {

        bool flag = true;

        int ans = height(root,flag);

        // return (ans) ? true : false;
        return flag;
    }
};