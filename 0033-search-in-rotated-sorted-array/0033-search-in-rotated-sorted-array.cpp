// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(const vector<int>& nums, int target, int left = 0, int right = -1) {
        if (right == -1)right = nums.size() - 1;
        if (left > right)return -1;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)return mid;
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                return search(nums, target, left, mid - 1);
            } else {
                return search(nums, target, mid + 1, right);
            }
        }
        else {
            if (nums[mid] < target && target <= nums[right]) {
                return search(nums, target, mid + 1, right);
            } else {
                return search(nums, target, left, mid - 1);
            }
        }
    }
};