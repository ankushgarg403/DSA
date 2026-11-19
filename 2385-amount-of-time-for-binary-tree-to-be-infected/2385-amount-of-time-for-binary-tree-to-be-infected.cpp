/**
 * Definition for a binary tree TreeNode.
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
    TreeNode* createmapping(TreeNode* root , int target , map<TreeNode* , TreeNode*> &TreeNodetoparent){
        TreeNode* res = NULL;
        
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNodetoparent[root] = NULL;
        
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            
            if(front -> val == target){
                res = front;
            }
            
            if(front -> left){
                TreeNodetoparent[front -> left] = front;
                q.push(front -> left);
            }
            
            if(front -> right){
                TreeNodetoparent[front -> right] = front;
                q.push(front -> right);
            }
        }
        return res;
    }
    
    int solve(TreeNode* root , map<TreeNode* , TreeNode*> &TreeNodetoparent){
        map<TreeNode* , bool> visited;
        
        queue<TreeNode*> q;
        q.push(root);
        
        visited[root] = true;
        
        int ans = 0;
        while(!q.empty()){
            int n = q.size();
            
            bool flag = false;
            
            for(int i = 0 ; i < n ; i++){
                TreeNode* front = q.front();
                q.pop();
                
                if(front -> left && !visited[front -> left]){
                    flag = true;
                    q.push(front -> left);
                    visited[front -> left] = 1;
                }
                
                if(front -> right && !visited[front -> right]){
                    flag = true;
                    q.push(front -> right);
                    visited[front -> right] = 1;
                }
                
                if(TreeNodetoparent[front] && !visited[TreeNodetoparent[front]]){
                    flag = true;
                    q.push(TreeNodetoparent[front]);
                    visited[TreeNodetoparent[front]] = 1;
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode* , TreeNode*> TreeNodetoparent;
        TreeNode* targetTreeNode = createmapping(root,start,TreeNodetoparent);
        
        int ans = solve(targetTreeNode , TreeNodetoparent);
        return ans;
    }
};