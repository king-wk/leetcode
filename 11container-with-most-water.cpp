/**
 * source: https://leetcode-cn.com/problems/container-with-most-water/
 * author: WEN JINGJING
 * date: 2020.7.10
 */

/**
 * Question description: 
 * Give you n nonnegative integers a1, a2,..., an, each representing a point (i, ai) in the coordinates. 
 * Draw n vertical lines in the coordinates. The two endpoints of vertical line i are (i, ai) and (i, 0). 
 * Find two of these lines so that the container they form with the x-axis can hold the most water.
 * 
 * Note: you cannot tilt the container, and the value of n is at least 2.
 * 
 * Example:
 * input: [1,8,6,2,5,4,8,3,7]
 * output: 49
 * 
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int Area = 0;
        int left = 0, right = height.size() - 1;
        while(left < right) {
            Area = max(Area, min(height[left], height[right]) * (right - left));
            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return Area;
    }
};