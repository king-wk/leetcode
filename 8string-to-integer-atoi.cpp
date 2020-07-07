/**
 * source: https://leetcode-cn.com/problems/string-to-integer-atoi/
 * author: WEN JINGJING
 * date: 2020.7.07
 */

/**
 * Question description: 
 * Please implement an atoi function to convert a string to an integer.
 * First, the function discards the useless beginning space character as needed until the first non space character is found.
 * The following conversion rules are as follows:
 * If the first non empty character is a positive or negative sign,
 * the symbol is combined with as many consecutive numeric characters as possible to form a signed integer.
 * If the first non empty character is a number, 
 * it is directly combined with the subsequent consecutive numeric characters to form an integer.
 * There may be extra characters after the valid integer part of the string, which can be ignored and should not affect the function.
 * 
 * Note: if the first non space character in the string is not a valid integer character, 
 * the string is empty, or the string contains only white space characters, 
 * your function does not need to be converted, that is, it cannot be converted effectively.
 * In any case, return 0 if the function cannot make a valid conversion.
 * 
 * !!!Attention: 
 * The white space character in this question only includes the space character 
 * ssuming that our environment can only store 32-bit signed integers, the numerical range is [−2^31, 2^31 − 1]. 
 * If the value exceeds this range, return INT_ MAX (2^31 − 1) or INT_ MIN (−2^31)
 * 
 * 
 * Example1:
 * input: "42"
 * output: 42
 * 
 * Example2:
 * input: "   -42"
 * output: -42
 * 
 * Example3:
 * input: "4193 with words"
 * output: 4193
 * 
 * Example4:
 * input: "words and 987"
 * output: 0
 * 
 * Example5:
 * input: "-91283472332"
 * output: -2147483648
 * 
 */

class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        int i = 0;
        while(str[i] == ' '){
            i++;
        }
        int sign = 1;
        if(str[i] == '-'){
            sign = -1;
            i++;
        }else if(str[i] == '+'){
            sign = 1;
            i++;
        }
        while(i < str.size() && str[i] >= '0' && str[i] <= '9'){
            result = result * 10 + (str[i] - '0');
            i++;
            if(result * sign >= INT_MAX)
                return INT_MAX;
            if(result * sign <= INT_MIN)
                return INT_MIN;
        }
        return result * sign;
    }
};