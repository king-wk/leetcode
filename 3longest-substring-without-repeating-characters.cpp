/**
 * source: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
 * author: WEN JINGJING
 * date: 2020.7.02
 */

/**
 * Question description: 
 * Given a string, please find out the length of the longest substring without repeating characters.
 * 
 * Example1:
 * input: "abcabcbb"
 * output: 3
 * as the longest substring without repeating characters: "abc"
 * 
 * Example2:
 * input: "bbbbb"
 * output: 1
 * as the longest substring without repeating characters: "b"
 * 
 * Example3:
 * input: "pwwkew"
 * output: 3
 * as the longest substring without repeating characters: "wke"
 * 
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0, head = 0;
        for(int tail = 0; tail < s.size(); tail++){
            int len = 0;
            for(int j = head; j < tail; j++){
                if(s[j] == s[tail]){
                    head = j + 1;
                }
            }
            len = tail - head;
            len++;
            if(len > maxlen){
                maxlen = len;
            }
        }
        return maxlen;
    }
};