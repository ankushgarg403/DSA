class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        
        bool arr[3] = {false,false,false};

        for(int i = 0 ; i < n ; i++){
            char ch = word[i];
            if(ch >= 'A' && ch <= 'Z'){
                arr[0] = true;
                continue;
            }
            arr[0] = false;
            break;
        }

        for(int i = 0 ; i < n ; i++){
            char ch = word[i];
            if(ch >= 'a' && ch <= 'z'){
                arr[1] = true;
                continue;
            }
            arr[1] = false;
            break;
        }

        for(int i = 1 ; i < n && (word[0] >= 'A' && word[0] <= 'Z'); i++){
            char ch = word[i];
            if(ch >= 'a' && ch <= 'z'){
                arr[2] = true;
                continue;
            }
            arr[2] = false;
            break;
        }

        for(int i = 0 ; i < 3 ; i++){
            if(arr[i]){
                return true;
            }
        }

        return false;
    }
};