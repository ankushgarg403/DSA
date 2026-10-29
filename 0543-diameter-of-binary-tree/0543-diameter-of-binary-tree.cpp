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
    pair<int,int> secondapproach(TreeNode* root){
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }

        pair<int,int> left = secondapproach(root -> left);
        pair<int,int> right = secondapproach(root -> right);

        int a1 = left.first;
        int a2 = right.first;
        int a3 = left.second + right.second;

        pair<int,int> ans;

        ans.first = max(a1,max(a2,a3));
        ans.second = max(left.second , right.second) + 1;
        
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {

        return secondapproach(root).first;
    }
};