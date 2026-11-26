class Solution {
public:
    bool canAliceWin(int n) {
        int k = 0;
        int take = 10;
        while(n>=take){
            n -= take;
            take--;
            k++;
        }
        if(k%2==1) return true;
        return false;
    }
};