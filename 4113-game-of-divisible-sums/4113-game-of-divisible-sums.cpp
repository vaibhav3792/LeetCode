class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> dp(n+1,0);

        for(int i = n-1; i>=0; i--){
            long long s1 = nums[i];
            long long take1 = (s1%3==0) ? s1 - dp[i+1] : s1 + dp[i+1];

            long long take2 = LLONG_MIN;
            if(i+1<n){
            long long s2 = 1LL * nums[i] + nums[i+1];
            take2 = (s2%3==0) ? s2 - dp[i+2] : s2 + dp[i+2];
            }
            dp[i] = max(take1,take2);
        }

        return dp[0];
    }
};