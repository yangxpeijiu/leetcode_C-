#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/*
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/


class Solution{
public:
    /*
    暴力搜索，O(n^2)时间复杂度，O(1)额外空间
    */
    vector<int> method1(vector<int>& nums, int target)
    {
        vector<int> ret;
        for (int i = 0; i < nums.size();i++)
        {
            for (int j = i + 1; j < nums.size();j++)
            {
                if (nums[i]+nums[j] == target)
                {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }
    /*
    方法二，采用hash,时间复杂度O(n),额外空间复杂度O(n)，
    在hash表中查询是否存在时间复杂度O(1)
    */
    vector<int> method2(vector<int>& nums, int target)
    {
        vector<int> ref (2,0);
        unordered_map<int, int> hash;
        //构建hash表，key值是原数组数值，value是数值原下标
        for(int i = nums.size();i--;hash[nums[i]]=i)
        {
            if(hash.find(target - nums[i]) == hash.end())
                continue;
            ref[0] = i;
            ref[1] = hash[target - nums[i]];   //数组下标从0开始故+1
            return ref;
        }
        return ref;  //now answer return [0,0]
    }

    vector<int> twoSum(vector<int>& nums, int target)
    {
        return method2(nums, target);
    }
};

vector<int> test(vector<int>& nums, int target)
{
    Solution s;
    return s.twoSum(nums, target);
}

int main()
{

    vector<int> nums({2, 7, 11, 15});
    int target = 9;
    vector<int> res;
    res = test(nums, target);
    cout<<'[';
    for (int i = 0; i<res.size();i++)
    {
        cout<<res[i];
        if (i != res.size()-1)
            cout<<',';
    }
    cout<<']';
}
