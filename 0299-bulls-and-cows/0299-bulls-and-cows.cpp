class Solution {
public:
    string getHint(string secret, string guess) {
        int x = 0;
        int y = 0;
        int freq[10] = {0};
        int n = secret.size();

        for(int i = 0 ; i < n ; i++){
            if(secret[i] == guess[i]){
                x++;
            }
            else{
                freq[secret[i]-'0']++;
            }
        }

        n = guess.size();
        for(int i = 0 ; i < n ; i++){
            if(secret[i] != guess[i]){
                int d = guess[i]-'0';
                if(freq[d] > 0){
                    y++;
                    freq[d]--;
                }
            }
        }

        return to_string(x) + "A" + to_string(y) + "B";
    }
};