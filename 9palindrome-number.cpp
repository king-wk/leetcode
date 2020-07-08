/**
 * source: https://leetcode-cn.com/problems/palindrome-number/
 * author: WEN JINGJING
 * date: 2020.7.08
 */

/**
 * Question description: 
 * Determine whether an integer is a palindrome number.
 * Palindrome number refers to the number of positive (from left to right) and reverse (from right to left) read the same integer.
 * 
 * Note: Can you solve this problem without converting integers into strings?
 * 
 * Example1:
 * input: 121
 * output: true
 * 
 * Example2:
 * input: -121
 * output: false
 * 
 * Example3:
 * input: 10
 * output: false
 * 
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x > 0 && x % 10 == 0)) {
            return false;
        } else {
            long y = 0, xx = x;
            while(xx != 0){
                y = y * 10 + xx % 10;
                xx = xx / 10;
                if(y > INT_MAX) {
                    return false;
                }
            }
            if(x == y) {
                return true;
            }
            return false;
        }
    }
};