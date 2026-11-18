class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        int n = s.size();
        int consecutive_count = 0;
        char curr_ch = s[0];
        for(char ch: s){
            if(ch==curr_ch){
                consecutive_count++;
            }else{
                if(consecutive_count %2 == 0){
                    consecutive_count = 1;
                } else{
                    consecutive_count = 0;
                    ans++;
                }
                curr_ch = ch;
            }
        }
        return ans;
    }
};