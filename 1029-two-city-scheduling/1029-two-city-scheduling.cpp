class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int>> diff;

        int n = costs.size();

        for(int i = 0 ; i < n ; i++){
            diff.push_back({costs[i][1] - costs[i][0],i});
        }

        sort(diff.begin() , diff.end());

        int sum = 0;
        for(int i = 0 ; i < diff.size()/2 ; i++){
            sum += costs[diff[i].second][1];
        }
        for(int i = diff.size()/2 ; i < diff.size() ; i++){
            sum += costs[diff[i].second][0];
        }

        return sum;
    }
};