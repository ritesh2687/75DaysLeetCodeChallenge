class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        for (int i = n-1;i>=0;i--) {
            int max = 0, id = -1;
            for (int j = 0;j<=i;j++) {
                if (arr[j] > max) {
                    max = arr[j];  id = j;
                }
            }
            if (id == 0) {
                ans.push_back(i+1);
                reverse(arr,0,i);
            } else if (id != i) {
                ans.push_back(id+1);
                ans.push_back(i+1);
                reverse(arr,0,id);
                reverse(arr,0,i);
            }
        }
        return ans;
    }
    void reverse(vector<int>& arr,int left,int right) {
        while (left < right) {
            int temp = arr[left]; arr[left] = arr[right]; arr[right] = temp;
            left++; right--;
        }
    }
};