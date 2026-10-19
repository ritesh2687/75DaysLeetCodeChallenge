class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
//     if(nums.empty()) return 0;
//        for(int i=0;i<nums.size()-1;i++){
//             if(nums[i]==nums[i+1]){
//                 nums.erase(nums.begin()+(i+1));
//                 i=i-1;

//             }
//         }

//         return nums.size();

    //     int l=0;
    //     int r=1;

    //     while(r<nums.size())
    //     if(nums[l]==nums[r]){
    //         nums.erase(nums.begin(),nums.end());
    //             l++;
    //             r++;
    //         }
    //         l++;
    //         r++;
    //     }

       
    //  }



    for(int i=0;i<nums.size()-1;i++){
     if(nums[i]==nums[i+1])
     {
        
        nums.erase(nums.begin()+i);
        i--;
     }
     
    }

    return nums.size();

}
};