class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        long long preSum = 0;
        long long evenCount = 1;
        long long oddCount = 0;
        long long ans = 0;
        for(int i = 0; i<n; i++){
            preSum += arr[i];
            if(preSum%2==0){
                ans += oddCount;
                evenCount++;
            }else{
                ans += evenCount;
                oddCount++;
            }
            ans %= MOD;
        }
        return (int)ans;
    }
};