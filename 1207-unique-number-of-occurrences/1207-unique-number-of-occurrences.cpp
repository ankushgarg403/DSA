class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> ans;
        if(arr.size() == 1){
            return true;
        }

        sort(arr.begin() , arr.end());

        int i = 0;
        int j = 1;
        while(i < arr.size() && j < arr.size()){
            if(arr[i] == arr[j]){
                j++;
                if(j > arr.size() - 1){
                    ans.push_back(j-i);
                }
            }
            else{
                ans.push_back(j-i);
                j++;
                i = j - 1;
                if(j > arr.size() - 1){
                    if(arr[j-2] == arr[j-1]){
                        ans.push_back(j-i);
                    }
                    else{
                        ans.push_back(1);
                    }
                }
            }
        }

        sort(ans.begin() , ans.end());
        for(int k = 0 ; k < ans.size()-1 ; k++){
            if(ans[k] == ans[k+1]){
                return false;
            }
        }
        return true;
    }
};