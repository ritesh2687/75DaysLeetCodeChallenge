class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> arr(n+1,0);
        for (int i = 0;i<=n;i++) {
            int l = max(0,i-ranges[i]);
            int r = min(n,i+ranges[i]);
            arr[l] = max(arr[l],r);
        }
        for (int x : arr)  cout  << x << " ";
        cout << endl;
        for (int i = 0;i<=n;i++) cout << i << " ";
        int maxi = 0, curr = 0, count = 0;
        for (int i  =0;i<arr.size()-1;i++) {
            maxi = max(maxi,arr[i]);
            if (i ==  curr) {
                count++;
                curr = maxi;
            }
        }
        if (curr<n) return -1;
        return count;
    }
};