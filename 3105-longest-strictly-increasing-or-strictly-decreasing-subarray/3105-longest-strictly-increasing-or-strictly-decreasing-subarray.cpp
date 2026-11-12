class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int mx = 1;
        int pos = 1, neg = 1;
        for(int i = 1; i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                pos++;
                neg = 1;
            } else if(nums[i]<nums[i-1]){
                neg++;
                pos = 1;
            } else{
                pos = 1;
                neg = 1;
            }
            mx = max({mx,pos,neg});
        }
        return mx;
    }
};