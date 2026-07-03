class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;

        int totalsum = 0;
        for(int i = 0 ; i < n ; i++){
            totalsum = totalsum + arr[i];
        }
        int leftsum = 0;
        int idx = -1;
        for(int i = 0 ; i < n ; i++){
            int rightsum = totalsum - leftsum - arr[i];

            if(leftsum == rightsum){
                idx = i;
                break;
            }

            leftsum += arr[i];
        }
        return idx;
    }
};