class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long reqCost = 0;
        long long mn = min(need1,need2);
        if(costBoth<cost1+cost2){
            reqCost += costBoth*mn;
            need1 -= mn;
            need2 -= mn;
        }
        
        if(need1>0){
            reqCost += 1LL*need1*(min(cost1,costBoth));
        }
        if(need2>0){
            reqCost += 1LL*need2*(min(cost2,costBoth));
        }
        return reqCost;
    }
};