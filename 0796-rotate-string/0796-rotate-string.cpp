#include<iostream>
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        string temp = "";
        for(int i = n-1 ; i >= 0 ; i--){
            char ch = s[i];
            temp = ch + temp;
            string remaining = s.substr(0,i);
            string ans = temp + remaining;
            if(ans == goal) return true;
        }
        return false;
    }
};