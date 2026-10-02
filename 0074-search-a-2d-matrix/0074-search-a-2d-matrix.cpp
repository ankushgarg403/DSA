class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s = 0;
        int e = matrix.size()*matrix[0].size() - 1;

        while(e >= s){
            int mid = s + (e-s)/2;
            int el = matrix[mid/matrix[0].size()][mid%matrix[0].size()];

            if(el == target) return true;
            else if(el > target) e = mid - 1;
            else s = mid + 1;
        }

        return false;
    }
};