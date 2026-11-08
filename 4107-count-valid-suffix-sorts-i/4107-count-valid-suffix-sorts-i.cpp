class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        unordered_map<int,int> freq;

        int idx = 0;
        while(idx<n && nums[idx]==target[idx]){
            idx++;
        }

        int nonzero = 0;

        auto update = [&](int val, int delta){
            int& c = freq[val];

            if(c==0) nonzero ++;

            c+= delta;

            if(c==0) nonzero --;
        };

        int ans = 0;

        for(int i = n-1; i>=0; i--){
            if(i<n-1 && target[i]<target[i+1]) break;

            update(nums[i],1);
            update(target[i],-1);

            if(nonzero == 0 && i<= idx) ans++;
        }

        return ans;
    }
};