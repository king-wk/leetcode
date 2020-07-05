/**
 * source: https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * author: WEN JINGJING
 * date: 2020.7.03
 */

/**
 * Question description: 
 * Two positive (from small to large) arrays nums1 and nums2 of sizes m and n are given.
 * Please find out the median of these two positive arrays, 
 * and the time complexity of the algorithm is O(log (m + n)).
 * You can assume that nums1 and nums2 are not empty at the same time.
 * 
 * Example1:
 * input: nums1 = [1, 3]  nums2 = [2]
 * output: 2.0
 * 
 * Example2:
 * input: nums1 = [1, 2]  nums2 = [3, 4]
 * output: (2 + 3) / 2 = 2.5
 * 
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int left = (n +m + 1) / 2, right = (n + m + 2) / 2;
        return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) + getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) * 0.5;
    }
    int getKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        if(len1 > len2){
            return getKth(nums2, start2, end2, nums1, start1, end1, k);
        }
        if(len1 == 0){
            return nums2[start2 + k - 1];
        }
        if(k == 1){
            return min(nums1[start1], nums2[start2]);
        }
        int i = start1 + min(len1, k / 2) - 1;
        int j = start2 + min(len2, k / 2) - 1;
        if(nums1[i] > nums2[j]){
            return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
        }else{
            return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
        }
    }
};