class Solution {
public:
    int maxProduct(int n) {
        int max1=0;
        int max2=0;
        while(n>0){
            int f=n%10;
            if(f>max1) {
                max2=max1;
                max1=f;              
            }
            else if(f>max2){
                max2=f;
            }
           
            n=n/10;     
        }
        return max1*max2;
    }
};