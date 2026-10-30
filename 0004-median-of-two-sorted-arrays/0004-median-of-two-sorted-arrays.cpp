class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i = 0;
        int j = 0;

        int n = n1+n2;

        int idx1 = n/2;
        int idx2 = idx1 - 1;

        int cnt = 0;
        int el1 = -1,el2 = -1;

        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                if(cnt == idx1) el1 = nums1[i];
                if(cnt == idx2) el2 = nums1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt == idx1) el1 = nums2[j];
                if(cnt == idx2) el2 = nums2[j];
                cnt++;
                j++;
            }
        }

        while(i < n1){
            if(cnt == idx1) el1 = nums1[i];
            if(cnt == idx2) el2 = nums1[i];
            cnt++;
            i++;
        }

        while(j < n2){
            if(cnt == idx1) el1 = nums2[j];
            if(cnt == idx2) el2 = nums2[j];
            cnt++;
            j++;
        }

        if(n%2 == 1) return el1;
        
        return (el1+el2)/2.0;
    }
};