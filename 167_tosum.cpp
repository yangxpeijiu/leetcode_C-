#include <iostream>
#include <vector>

using namespace std;

/*
给定一个已经按照升序排列的有序数组，找到两个数使得它们相加
之和等于目标数。函数应该返回这两个下标值index1和index2，
其中index1必须小于index2。返回的下标值不是从零开始的，
可以假设每个输入只对应唯一的答案，而且不可以重复使用相同
的元素
*/

class Solution
{
    public:
        vector<int> twoSum(vector<int>& numbers, int target)
        {
            /*
            头尾双指针，取两数相加与target比较，大了把大数变小，
            小了把小数变大，时间复杂度O(n)，空间复杂度O(1)。
            */
           int low = 0, high = numbers.size() - 1;
           while(low<high)
           {
               if(numbers[low]+numbers[high] == target)
                   return {low+1, high+1};
                else if (numbers[low]+numbers[high] > target)
                    high--;
                else
                    low++;
           }
           return {-1, -1};
        }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = s.twoSum(nums, target);
    cout<<'[';
    for(int i = 0; i< res.size();i++)
    {
        cout<<res[i];
        if(i<res.size()-1)
            cout<<',';
    }
    cout<<']';
}