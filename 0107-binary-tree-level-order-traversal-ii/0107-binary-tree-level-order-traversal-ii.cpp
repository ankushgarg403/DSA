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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        
        stack<int> st;
        
        while(!q.empty()){
            int n = q.size();
            vector<int> lvl;
            for(int i = 0 ; i <  n ; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                st.push(temp -> val);
                if(temp -> right){
                    q.push(temp -> right);
                }
                if(temp -> left){
                    q.push(temp -> left);
                }
            }
            while(!st.empty()){
                lvl.push_back(st.top());
                st.pop();
            }
            ans.push_back(lvl);
        }
        int i = 0;
        int j = ans.size()-1;
        while(j > i){
            swap(ans[i++],ans[j--]);
        }      
        return ans;
    }
};