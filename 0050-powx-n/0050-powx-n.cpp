class Solution {
public:
    double myPow(double x, int n) {
        //your code goes here

        long long power=n;
        long double base=x;

        if(n<0){
            base=1.0L/base;
            power=-power;
        }
        long double ans=1.0L;
        while(power>0){
            if(power & 1){
                ans*=base;
                cout<<"asdfgh";
            }
            base*=base;
            power>>=1;
        }
        return (double)ans;
    }
};