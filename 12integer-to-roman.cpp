/**
 * source: https://leetcode-cn.com/problems/integer-to-roman/
 * author: WEN JINGJING
 * date: 2020.7.11
 */

/**
 * Question description: 
 * Given an integer, convert it to Roman numerals.
 * Make sure the input is in the range of 1 to 3999.
 * 
 * Example1:
 * input: 3
 * output: "III"
 * 
 * Example2:
 * input: 4
 * output: "IV"
 * 
 * Example3:
 * input: 9
 * output: "IX"
 * 
 * Example4:
 * input: 58
 * output: "LVIII"
 * 
 * Example5:
 * input: 1994
 * output: "MCMXCIV"
 * 
 */
class Solution {
public:
    string intToRoman(int num) {
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string result;
        for(int i = 0; i < 13; i++){
            while(value[i] <= num){
                num -= value[i];
                result += roman[i];
            }
        }
        return result;
    }
};