class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int mn = INT_MAX;
        int sum;

        for (int p = l; p <= r; p++) {
            sum = 0;
            int k = p;
            for (int i = 0; i < k; i++)
                sum += nums[i];
            int j = 0;
            if (sum > 0)
                mn = min(mn, sum);
            
            while (k < n) {
                sum += nums[k];
                sum -= nums[j];
                k++;
                j++;
                if (sum > 0)
                    mn = min(mn, sum);
            }
        }

        return mn == INT_MAX ? -1 : mn;
    }
};