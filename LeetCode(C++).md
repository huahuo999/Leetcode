# LeetCode(C++)

## 二分查找法

### 35.搜索序列



```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while(low<=high){
            int mid = (low + high) / 2;
            if(nums[mid]>target) high = mid-1;
            else if(nums[mid]<target) low = mid+1;
            else{
                return mid;
            }
        }
        return low;
    }
};+
```

### 69.x的平方根



```c++
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;

    }
};
```

