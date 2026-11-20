class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int findMethod(vector<int>& nums, int start, int target){
        int j = lower_bound(begin(nums)+start,end(nums),target) - begin(nums);
        if(j<n && nums[j]==target) return j;
        return -1;
    }

    
    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        dp.assign(n+1,vector<int>(2,0));

        int result = 1;

        for(int i = n-1; i>=0 ; i--){
            for(int inc = 0; inc<2; inc++){
                int curVal = nums[i] + inc;
                int len = 1;

                int j = findMethod(nums,i+1,curVal);
                if(j!=-1){
                    len =  max(len,1+dp[j][1]);
                }

                j = findMethod(nums,i+1,curVal+1);
                if(j!=-1){
                    len =  max(len,1+dp[j][0]);
                }

                dp[i][inc] = len;
                result = max(result,dp[i][inc]);
            }
        }


        return result;
    }
};