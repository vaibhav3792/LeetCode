class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        long long ans = LLONG_MAX;
        long long sum = accumulate(beans.begin(),beans.end(),0L);
        sort(beans.begin(),beans.end());
        for(int i = 0; i<n; i++){
            ans = min(ans, sum - 1LL * (n-i) * beans[i]);
        }
        return ans;
    }
};