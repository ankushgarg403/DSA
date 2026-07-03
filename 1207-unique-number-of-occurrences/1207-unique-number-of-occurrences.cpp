class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<int> ans;
        for (int i = 0 ; i < arr.size() ; i++){
            int count = 1;
            while(i+1 < arr.size() && arr[i] == arr[i+1]){
                count++;
                i++;
            }
            ans.push_back(count);
        }
        sort(ans.begin(),ans.end());

        for (int i = 1 ; i < ans.size() ; i++){
            if(ans[i] == ans[i-1]){
                return false;
            }
        }
        return true;
    }
};