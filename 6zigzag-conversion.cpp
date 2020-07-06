/**
 * source: https://leetcode-cn.com/problems/zigzag-conversion/
 * author: WEN JINGJING
 * date: 2020.7.06
 */

/**
 * Question description: 
 * To zigzag a given string from top to bottom and from left to right according to a given number of lines.
 * 
 * Example1:
 * input: s = "LEETCODEISHIRING", numRows = 3
 * output: "LCIRETOESIIGEDHN"
 * 
 * Example2:
 * input: s = "LEETCODEISHIRING", numRows = 4
 * output: "LDREOEIIECIHNTSG"
 * 
 * as: L     D     R
 *     E   O E   I I
 *     E C   I H   N
 *     T     S     G
 * 
 */

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        string result;
        int len = s.size();
        int cycle = 2 * numRows - 2;
        for(int i = 0; i < numRows; i++){
            for(int j = 0; i + j < len; j += cycle){
                result += s[i + j];
                if(i != 0 && i != numRows - 1 && j + cycle - i < len){
                    result += s[j + cycle - i];
                }
            }
        }
        return result;
    }
};