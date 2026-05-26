class Solution {
    public int minEatingSpeed(int[] piles, int h) {

       int max=0;
       for(int x : piles ) max=Math.max(x,max);
       int left=1,right=max,ans=Integer.MAX_VALUE;
       while(left<=right) {
        int mid = (left+right)/2;
        if (valid(piles,mid,h)){
            ans=mid;right=mid-1;
        }else{
            left=mid+1;
        }
       } 
       return ans;
    }

    boolean valid(int[] piles,int speed,int h){
        int hour=0;
        for(int x:piles){
            hour +=x/speed;
            if(x%speed != 0)hour++;
            if(hour >h)return false;

        }
        if(hour <=h) return true;
        return false;
    }
}