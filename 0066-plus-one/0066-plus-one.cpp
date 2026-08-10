class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size();
        if(n==1 && digits[n-1] == 9){
            return {1,0};
        }

        digits[n-1] = digits[n-1] + 1;
        // int carry = 0;
        int i = n-1;
        while(i >= 0){
            if(digits[i] == 10){
                // carry = 1;
                ans.push_back(0);
                if(i==0){
                    ans.push_back(1);
                    break;
                }
                digits[i-1] ++;
            }
            else{
                ans.push_back(digits[i]);
            }
            i--;
        }

        int s = 0;
        int e = ans.size()-1;
        while(e > s){
            swap(ans[s++],ans[e--]);
        }
        return ans;
    }
};