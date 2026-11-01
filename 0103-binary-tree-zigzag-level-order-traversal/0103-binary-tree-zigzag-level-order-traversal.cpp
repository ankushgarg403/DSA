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
// class Solution {
// private:
//     void levelordertraversal(TreeNode* root , vector<int> &ans){
//         queue<TreeNode*> q;
//         q.push(root);
//         q.push(NULL);

//         while(!q.empty()){
//             TreeNode* temp = q.front();
//             q.pop();

//             if(temp == NULL){
//                 if(!q.empty()){
//                     q.push(NULL);
//                 }
//                 ans.push_back(-1);
//             }
//             else{
//                 ans.push_back(temp -> val);
//                 if(temp -> left){
//                     q.push(temp -> left);
//                 }
//                 if(temp -> right){
//                     q.push(temp -> right);
//                 }
//             }
//         }
//     }
// private:
//     void reverse(vector<int> &ans , int i , int j){
//         while(j > i){
//             swap(ans[i++],ans[j--]);
//         }
//     }
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<int> ans;
//         vector<vector<int>> finals;
//         levelordertraversal(root,ans);
        
//         for(int i = 0 ; i < ans.size() ; i++){
//             int el = ans[i];
//             if(ans[i] == -1){
//                 int j = i;
//                 while(j < ans.size() && ans[j] != -1){
//                     j++;
//                 }
//                 reverse(ans,i+1,j-1);
//                 i = j;
//             }
//         }

//         vector<int> temp;

//         for(int i = 0; i < ans.size(); i++) {
//             if(ans[i] == -1) {
//                 finals.push_back(temp);
//                 temp.clear();
//             }
//             else {
//                 temp.push_back(ans[i]);
//             }
//         }
        
//         return finals;
//     }
// };


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()) {
            int size = q.size();
            vector<int> level(size);

            for(int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();

                int index = leftToRight ? i : size - 1 - i;

                level[index] = temp->val;

                if(temp->left)
                    q.push(temp->left);

                if(temp->right)
                    q.push(temp->right);
            }

            ans.push_back(level);
            leftToRight = !leftToRight;
        }

        return ans;
    }
};
