class Solution {
public:
    string reversePrefix(string s, int k) {
        int i = 0;
        int j = k-1;
        while(j > i){
            swap(s[i++],s[j--]);
        }

        return s;
    }
};