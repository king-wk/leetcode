/**
 * source: https://leetcode-cn.com/problems/two-sum/
 * author: WEN JINGJING
 * date: 2020.6.30
 */

/**
 * Question description: 
 * Given an integer array nums and a target value, 
 * please find the two integers whose sum is the target value in the array and return their array subscripts.
 * You can assume that there is only one answer for each input. 
 * However, the same element in an array cannot be used twice.
 * 
 * Example:
 * nums = [2, 7, 11, 15], target = 9
 * nums[0] + nums[1] = 2 + 7 = 9
 * return [0, 1] 
 */
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> record;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            int difference = target - nums[i];
            if (record.find(difference) != record.end())
            {
                result.push_back(record[difference]);
                result.push_back(i);
                return result;
            }
            record[nums[i]] = i;
        }
        return {};
    }

    //another method
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++)
        {
            int difference = target - nums[i];
            if (record.find(difference) != record.end())
            {
                int result[] = {i, record[difference]};
                return vector<int>(result, result + 2);
            }
            record[nums[i]] = i;
        }
        return {};
    }
};