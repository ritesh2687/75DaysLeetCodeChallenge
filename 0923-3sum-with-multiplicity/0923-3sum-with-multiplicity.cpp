class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = 0;
        int mod = 1e9 + 7;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum == target) {
                    if (arr[left] == arr[right]) {
                        int len = right - left + 1;
                        ans += len *( len - 1) / 2;
                        ans %= mod;
                        break;
                    }

                    int leftV = arr[left], rightV = arr[right];
                    int countL = 0, countR = 0;
                    while (arr[left] == leftV) {
                        left++;
                        countL++;
                    }
                    while (arr[right] == rightV) {
                        right--;
                        countR++;
                    }

                    ans += (countL * countR);
                    ans %= mod;

                } else if (sum > target)
                    right--;
                else
                    left++;
            }
        }
        return ans;
    }
};