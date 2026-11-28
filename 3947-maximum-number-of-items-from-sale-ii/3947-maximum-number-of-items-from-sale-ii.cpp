class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n+1,0);
        
        int minPrice = INT_MAX;

        for(auto& item: items){
            freq[item[0]]++;
            minPrice = min(minPrice,item[1]);
        }

        vector<int> multiples(n+1,0);

        for(int f = 1; f<=n; f++){
            for(int j = f; j<=n; j+=f){
                multiples[f] += freq[j];
            }
        }

        vector<pair<int,int>> candidates;

        for(auto& item: items){
            int factor = item[0];
            int price = item[1];

            int gain = multiples[factor] - 1;

            if(gain>0 && price <= 2LL * minPrice){
                candidates.push_back({price,gain});
            }
        }

        sort(candidates.begin(),candidates.end());

        long long ans = 0;
        long long remaining = budget;

        for(auto & [price,gain]: candidates){
            long long take = min(
                (long long) gain,
                remaining / price
            );

            ans += 2*take;
            remaining -= take*price;
        }

        ans += remaining/ minPrice;

        return (int) ans;
    }
};