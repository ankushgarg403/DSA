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
    void inorder(TreeNode* p , TreeNode* q , bool &flag){
        if(p == NULL && q == NULL) return;

        if(p == NULL && q != NULL){
            flag = false;
            return;
        }
        else if(q == NULL && p != NULL){
            flag = false;
            return;
        }
        
        else if(q -> val != p -> val){
            flag = false;
        }
        inorder(p -> left , q -> left , flag);
                
        inorder(p -> right , q -> right , flag);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool flag = true;
        inorder(p,q,flag);

        return (flag);
    }
};