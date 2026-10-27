class Solution {
private:
    void reverse(string& s , int i , int j){
        while(j > i){
            swap(s[i++],s[j--]);
        }
    }
public:
    string reverseStr(string s, int k) {
        int n = s.length();

        for(int i = 0 ; i < n ; i = i+2*k){
            reverse(s,i,min(i+k-1,n - 1));
        }
        return s;
    }
};