#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <array>
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
        int n = (int)s.size();
        if (n == 0) return s;

        array<int, 2> best{ 0, 0 }; // [L, R]

        for (int i = 0; i < n; ++i) {          // 关键：从 0 开始
            i = findLongest(s, i, best);
        }

        return s.substr(best[0], best[1] - best[0] + 1); // len = R-L+1
    }

    static int findLongest(const string& s, int low, array<int, 2>& best) {
        int n = (int)s.size();
        int high = low;

        // 吞掉右侧连续相同字符（处理偶数回文的关键）
        while (high < n - 1 && s[low] == s[high + 1]) ++high;
        int ans = high;

        // 向两边扩展
        while (low > 0 && high < n - 1 && s[low - 1] == s[high + 1]) {
            --low; ++high;
        }

        if (high - low > best[1] - best[0]) {
            best[0] = low;
            best[1] = high;
        }
        return ans;
    }
};
