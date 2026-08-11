class Solution {
public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();

        int total = n + m;

        // Initial gap
        int gap = (total + 1) / 2;

        while (gap > 0) {
            int i = 0;
            int j = gap;

            while (j < total) {

                // Both elements are in a[]
                if (i < n && j < n) {
                    if (a[i] > a[j]) {
                        swap(a[i], a[j]);
                    }
                }

                // i is in a[], j is in b[]
                else if (i < n && j >= n) {
                    if (a[i] > b[j - n]) {
                        swap(a[i], b[j - n]);
                    }
                }

                // Both elements are in b[]
                else {
                    if (b[i - n] > b[j - n]) {
                        swap(b[i - n], b[j - n]);
                    }
                }

                i++;
                j++;
            }

            // Reduce gap
            if (gap == 1)
                gap = 0;
            else
                gap = (gap + 1) / 2;
        }
    }
};