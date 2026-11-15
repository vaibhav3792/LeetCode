class Solution {
public:
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for(int i = 1; i<n;i++){
            adj[parent[i]].push_back(i);
        }

        vector<int> order;
        vector<int> st;
        st.push_back(0);

        while(!st.empty()){
            int u = st.back();
            st.pop_back();
            order.push_back(u);
            for(auto it: adj[u]){
                st.push_back(it);
            }
        }

        reverse(order.begin(),order.end());

        vector<long long> dp(n,0);
        for(int u: order){
            long long sum = 0;
            long long mn = LLONG_MAX;

            for(int v: adj[u]){
                sum += dp[v];
                mn = min(mn,dp[v]);
            }
            if(adj[u].empty()) dp[u] = score[u]; // Leaf node
            else if(op[u]==0){
                dp[u] = score[u] + sum - min(mn,0LL);
            } else{
                dp[u] = score[u] + sum - mn;
            }
            
        }
        return (int)dp[0];
    }
};