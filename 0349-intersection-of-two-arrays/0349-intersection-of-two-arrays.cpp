class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        unordered_map<int,bool> check;
        vector<int> ans;

        for(int i = 0 ; i < nums1.size() ; i++){
            if(m[nums1[i]]){
                m[nums1[i]]++;
            }
            else{
                m[nums1[i]] = 1;
            }
        }

        for(int i = 0 ; i <  nums2.size() ; i++){
            if(m[nums2[i]]){
                if(check[nums2[i]]){
                    continue;
                }
                ans.push_back(nums2[i]);
                check[nums2[i]] = true;
            }
            else{
                continue;
            }
        }

        return ans;

    }
    
};