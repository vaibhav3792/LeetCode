class Solution {
public:

    unordered_map<int,vector<int>> adj;
    vector<int> last;
    vector<int> result_size;

    void dfs(int curNode, string& s, vector<int>& parent){
        int c = s[curNode] - 'a';
        int nearestAncestor = last[c];

        last[c] = curNode;

        for(int child: adj[curNode]){
            dfs(child,s,parent);
        }

        last[c] = nearestAncestor;

        if(curNode!=0){
            int newParent = parent[curNode];
            if(nearestAncestor != -1){
                newParent = nearestAncestor;
            }
            parent[curNode] = newParent;
            result_size[newParent] += result_size[curNode]; 
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        for(int i = 1; i<n; i++){
            int u = parent[i];
            int v = i;
            adj[u].push_back(v);
        }

        last.assign(26,-1);
        result_size.assign(n,1);

        dfs(0,s,parent);

        return result_size;
    }
};