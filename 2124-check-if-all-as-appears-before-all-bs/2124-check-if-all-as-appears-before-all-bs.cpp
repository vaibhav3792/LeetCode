class Solution {
public:
    bool checkString(string s) {
        int cntB = 0;
        for(char ch: s){
            if(ch=='b') cntB++;
            if(ch=='a' && cntB!=0) return false;
        }
        return true;
    }
};