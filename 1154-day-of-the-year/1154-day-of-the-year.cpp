class Solution {
public:
    int dayOfYear(string date) {
        int month = ((date[5] - '0') * 10 + (date[6] - '0'))-1;
        int day = (date[8] - '0') * 10 + (date[9] - '0');

        int year = 0;
        for(int i = 0 ; i < 4 ; i++){
            year = year*10 + (date[i]-'0');
        }

        int arr[13] = {31,28,31,30,31,30,31,31,30,31,30,31};

        int ans = 0;
        for(int i = 0 ; i < month ; i++){
            ans = ans + arr[i];
        }
        if(((year%400 == 0) || (year%4 == 0 && year%100 != 0)) && month>1)
        return ans+day+1;

        return ans+day;
    }
};