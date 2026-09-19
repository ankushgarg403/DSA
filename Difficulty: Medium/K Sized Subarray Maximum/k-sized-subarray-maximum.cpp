class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        deque<int> d;
        vector<int> ans;

        for(int i = 0; i < arr.size(); i++) {

            // Remove indices outside the window
            while(!d.empty() && d.front() <= i-k) {
                d.pop_front();
            }

            // Remove smaller elements
            while(!d.empty() && arr[d.back()] <= arr[i]) {
                d.pop_back();
            }

            d.push_back(i);

            // Window is ready
            if(i >= k-1) {
                ans.push_back(arr[d.front()]);
            }
        }

        return ans;
    }
};