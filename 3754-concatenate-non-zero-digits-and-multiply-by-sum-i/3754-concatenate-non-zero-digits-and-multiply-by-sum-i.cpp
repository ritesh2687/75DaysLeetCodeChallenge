class Solution {
public:
    long long sumAndMultiply(int n) {
    long long sum=0;
    long long ans=0;
    long long div = 1;

    while(n>0){
        int digit=n%10;
        sum+=digit;

        if(digit!=0){
            ans=digit*div+ans;
            div*=10;
        }
        n/=10;
    }

 
    return ans*sum;
    
    }
};