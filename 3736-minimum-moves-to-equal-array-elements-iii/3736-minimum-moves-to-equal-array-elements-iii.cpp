class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int cnt = 0;
        for(int num: nums){
            cnt += (mx-num);
        }
        return cnt;
    }
};