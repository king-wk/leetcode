/**
 * source: https://leetcode-cn.com/problems/roman-to-integer/
 * author: WEN JINGJING
 * date: 2020.7.09
 */

/**
 * Question description: 
 * Roman numerals contain the following seven characters: I, V, X, l, C, D and M.
 * I -> 1
 * V -> 5
 * X -> 10
 * L -> 50
 * C -> 100
 * D -> 500
 * M -> 1000
 * 
 * Note: Usually, the small numbers in Roman numerals are to the right of the big ones. 
 * But there are also special cases. 
 * For example, 4 is not written as IIII, but as IV. 
 * The number 1 is on the left of the number 5, 
 * which represents the number 4 obtained by subtracting the large number 5 by the decimal 1.
 *
 * Given a Roman number, convert it to an integer. Make sure the input is in the range of 1 to 3999.
 * 
 * Example1:
 * input: "III"
 * output: 3
 * 
 * Example2:
 * input: "IV"
 * output: 4
 * 
 * Example3:
 * input: "IX"
 * output: 9
 * 
 * Example4:
 * input: "LVIII"
 * output: 58
 * 
 * Example5:
 * input: "MCMXCIV"
 * output: 1994
 * 
 */

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> charToInt = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int i = 0, result = 0;
        while(i < s.size() - 1) {
            if(charToInt[s[i]] < charToInt[s[i + 1]]) {
                result -= charToInt[s[i]];
            } else {
                result += charToInt[s[i]];
            }
            i++;
        }
        result += charToInt[s[i]];
        return result;
    }
};