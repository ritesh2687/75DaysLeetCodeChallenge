class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int l=nums.size()-1;
        int mid=s+(l-s)/2;
        while(s<=l){
            if(target==nums[mid]){
                cout<<"call";
                return mid;
            }
            else if(nums[mid]<target){
                s=mid+1;
                mid=s+(l-s)/2;
                cout<<"call2";
            }
            else if(nums[mid]>target){
                l=mid-1;
                mid=s+(l-s)/2;
                cout<<"call3";
            }
          
            

        }
        return -1;
    }
};