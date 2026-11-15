class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            int temp = nums[i];
            int mn = INT_MAX;
            for(int j = i; j<n;j++){
                    mn = min(mn,nums[j]);
                    temp = temp & nums[j];
                    if(temp==mn) cnt++;
            }
        }
        return cnt;
    }
};