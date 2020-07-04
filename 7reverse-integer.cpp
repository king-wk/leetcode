/**
 * source: https://leetcode-cn.com/problems/reverse-integer/
 * author: WEN JINGJING
 * date: 2020.7.04
 */

/**
 * Question description: 
 * Given a 32-bit signed integer, you need to reverse the number on each of the integers.
 * 
 * !!!Attention: 
 * Assuming that our environment can only store the lower 32-bit signed integers, 
 * the numerical range is [−2^31, 2^31 − 1]. 
 * According to this assumption, if the integer overflows after inversion, it returns 0.
 * 
 * Example1:
 * input: 123
 * output: 321
 * 
 * Example2:
 * input: -123
 * output: -321
 * 
 * Example3:
 * input: 120
 * output: 21
 * 
 */

class Solution {
public:
    int reverse(int x) {
        long long y = 0;
        while(x){
            y = y * 10 + x % 10;
            x = x / 10;
        }
        return (y > INT_MAX || y < INT_MIN) ? 0 : y;
    }
};