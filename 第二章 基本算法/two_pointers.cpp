#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        if (size < 3) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; ++i) {
            if (nums[i] > 0) return res; // 因为没有负数了，相加不可能为0
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = size - 1;
            while (left < right) {
                if (left < right && nums[left] + nums[right] < -nums[i]) left++;
                else if (left < right && nums[left] + nums[right] > -nums[i]) right--;
                else {
                    res.push_back(vector<int>{nums[left], nums[right], nums[i]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left-1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
        return  res;
    }
};


class Solution5 {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size <= 1) return s;
        // 大窗口
        for (int i = 1; i < size; ++i) {

        }

    }
};