class Solution {
public:
    bool canAliceWin(int n) {
        int t=0;
        for(int c=10;c>0;c--){
            if(n>=c) n=n-c;
            else{
                t=c;
                break;
            }    
        }

        if ((t)%2==1) return true;
        else return false;
    }
};