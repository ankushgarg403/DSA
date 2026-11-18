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
    TreeNode* solve(vector<int> &inorder, vector<int> &postorder , int start , int end , int &index , int n , unordered_map<int,int> &mp){
        if(index >= n || end < start){
            return NULL;
        }
        
        int el = postorder[index--];
        TreeNode* root = new TreeNode(el);
        int position = mp[el];
        
        root -> right = solve(inorder , postorder , position+1 , end , index , n , mp);
        root -> left = solve(inorder , postorder , start , position-1 , index , n , mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int postorderstart = n-1; 

        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[inorder[i]] = i;
        }

        TreeNode* ans = solve(inorder,postorder,0,n-1,postorderstart,n,mp);
        return ans;
    }
};