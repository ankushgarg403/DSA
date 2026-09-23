class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // int n = gas.size();
        
        // int startidx = -1;
        
        // int currgas = 0;
        // for(int i = 0 ; i < n ; i++){
        //     currgas = currgas + gas[i] - cost[i];
            
        //     if(currgas < 0){
        //         startidx = i+1;
        //         currgas = 0;
        //     }
        // }
        
        // currgas = 0;
        // for(int i = 0 ; i < n ; i++){
        //     int j = (startidx + i)%n;
            
        //     currgas = currgas + gas[j] - cost[j];
            
        //     if(currgas < 0){
        //         return -1;
        //     }
            
        // }
        
        // return startidx;
        
        int n = gas.size();
		    int startIdx = 0;

		    // Initially tank is empty
		    int currGas = 0;

		    for(int i = 0; i < n; i++) {
		        currGas = currGas + gas[i] - cost[i];

		        // If currGas becomes less than zero, then
		        // It's not possible to proceed with this startIdx
		        if(currGas < 0) {
		            startIdx = i + 1;
		            currGas = 0;
		        }
		    }


		    // Checking if startIdx can be a valid 
		    // starting point for the Circular tour
		    currGas = 0;
		    for(int i = 0; i < n; i++) {

		        // Circular Index
		        int idx = (i + startIdx) % n;
		      	currGas = currGas + gas[idx] - cost[idx];
		        if(currGas < 0)
		            return -1;
		    }

		    return startIdx;
    }
};