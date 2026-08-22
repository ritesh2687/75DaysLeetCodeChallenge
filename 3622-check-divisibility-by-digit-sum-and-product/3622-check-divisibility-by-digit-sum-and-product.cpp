class Solution {
public:
    bool checkDivisibility(int n) {

        int sum=0;
        int product=1;
        int p=n;

        while(n>0){
            int temp=n%10;
            sum=sum+temp;
            product=product*temp;

            
            n=n/10;
        }
        int t=sum + product;
        if (t==0) return false;
        int ans=p%t;
        cout<<ans;
       

        if(ans>0) return false;

        else return true;
        
    }
};