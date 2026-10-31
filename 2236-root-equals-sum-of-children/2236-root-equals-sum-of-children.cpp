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
    int sum(TreeNode* root , bool &flag){
        if(root == NULL){
            return 0;
        }

        if(!root -> left && !root -> right){
            return root -> val;
        }

        int left = sum(root -> left , flag);
        int right = sum(root -> right , flag);

        if(left + right != root -> val){
            flag = false;
            return left+right;
        }
        else{
            return left+right;
        }        

    }
public:
    bool checkTree(TreeNode* root) {
        bool flag = true;

        int ans = sum(root , flag);

        return flag;
        
    }
};