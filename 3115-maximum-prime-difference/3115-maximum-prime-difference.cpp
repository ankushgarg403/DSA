class Solution {
private:
    bool is_prime(int n){
        if(n < 2){
            return false;
        }

        for(int i = 2 ; i <= sqrt(n) ; i++){
            if(n%i == 0){
                return false;
            }
        }

        return true;
    }
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int first = -1;
        int last = -1;

        for(int i = 0 ; i < nums.size() ; i++){
            if(is_prime(nums[i])){
                if(first == -1) first = i;

                last = i;
            }
        }

        return last - first;
    }
};