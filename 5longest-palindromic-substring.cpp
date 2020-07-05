/**
 * source: https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 * author: WEN JINGJING
 * date: 2020.7.05
 */

/**
 * Question description: 
 * Given a string s, 
 * find the longest palindrome substring in s. 
 * You can assume that the maximum length of s is 1000.
 * 
 * Example1:
 * input: "babad"
 * output: "bab"
 * 
 * Example2:
 * input: "cbbd"
 * output: "bb"
 * 
 */

class Solution {
public:
    string longestPalindrome(string s) {
        int left = 0, right = 0;
        for(int i = 0; i < s.length(); i++){
            int len1 = CenterExtension(s, i, i);
            int len2 = CenterExtension(s, i, i + 1);
            int len = max(len1, len2);
            if(right - left + 1 < len){
                left = i - (len - 1) / 2;
                right = i + len / 2;
            }
        }
        return s.substr(left, right - left + 1);
    }
    int CenterExtension(string s, int left, int right){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
};