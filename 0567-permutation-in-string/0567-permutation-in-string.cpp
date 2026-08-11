class Solution {
public:
    bool ismatched(int arr1[] , int arr2[]){
        for(int i = 0 ; i < 26 ; i++){
            if(arr1[i] != arr2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;

        int arr1[26] = {0};
        int arr2[26] = {0};

        for(int i = 0 ; i < n ; i++){
            int index1 = s1[i] - 'a';
            arr1[index1]++;
        }
        for(int i = 0 ; i < n ; i++){
            int index2 = s2[i] - 'a';
            arr2[index2]++;
        }

        if(ismatched(arr1,arr2)){
            return true;
        }

        for(int i = 1 ; i <= m-n ; i++){
            int index1 = s2[i-1] - 'a';
            int index2 = s2[i+n-1] - 'a';
            arr2[index1]--;
            arr2[index2]++;

            if(ismatched(arr1,arr2)){
                return true;
            }
        }
        return false;
    }
};