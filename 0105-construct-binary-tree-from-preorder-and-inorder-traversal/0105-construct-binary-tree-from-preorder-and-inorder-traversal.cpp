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
    TreeNode* solve(vector<int> &inorder, vector<int> &preorder , int start , int end , int &index , int n , unordered_map<int,int> &mp){
        if(index >= n || end < start){
            return NULL;
        }
        
        int el = preorder[index++];
        TreeNode* root = new TreeNode(el);
        int position = mp[el];
        
        root -> left = solve(inorder , preorder , start , position-1 , index , n , mp);
        root -> right = solve(inorder , preorder , position+1 , end , index , n , mp);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderstart = 0;
        int n = inorder.size();

        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[inorder[i]] = i;
        }

        TreeNode* ans = solve(inorder,preorder,0,n-1,preorderstart,n,mp);
        return ans;
    }
};