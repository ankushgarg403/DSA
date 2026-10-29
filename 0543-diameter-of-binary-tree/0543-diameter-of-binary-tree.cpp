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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = height(root -> left);
        int right = height(root -> right);

        int ans = 1 + max(left,right);
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int a1 = diameterOfBinaryTree(root -> left);
        int a2 = diameterOfBinaryTree(root -> right);
        int a3 = height(root -> left) + height(root -> right);

        int ans = max(a1,max(a2,a3));

        return ans;
    }
};