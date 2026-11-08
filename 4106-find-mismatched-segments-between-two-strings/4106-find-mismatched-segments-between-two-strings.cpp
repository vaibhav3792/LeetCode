class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        int i = 0;
        int n = s1.size();
        while(i<n){
            if(s1[i]==s2[i]){
                i++;
                continue;
            }
            string temp = "";
            string temp2 = "";
            while(i<n && s1[i]!=s2[i]){
                temp += s1[i];
                temp2 += s2[i];
                i++;
            }
            ans.push_back({temp,temp2});
        }
        return ans;
    }
};