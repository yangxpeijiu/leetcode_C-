#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
给定两个大小为m和n的有序数组nums1和nums2。
找出这两个有序数组的中位数，并且要求算法的
时间复杂度为O(log(m+n))。可以假设nums1和
nums2不会同时为空。
*/

class Solution {
    public:
    double mothod1(vector<int>& nums1, vector<int>& nums2){
        /*
        把两个vector拼接到一起，然后快速排序，快速排序的时间复杂度
        为O(nlogn).
        */
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        vector<int> res;
        res = quickSort(nums1);
        int n = res.size();
        cout<<n;
        if(n%2) return res[n/2];
        else return((res[n/2 -1]+res[n/2])/2);
    }
    /*
    这部分代码有问题，思路是对的，问题可能出现在类对象，指针上
    */
    vector<int> quickSort(vector<int>& num){
        if(num.size()<2)     //当空或只有一个数的时候是有序的
            return num;
        else{
            int pivot = num[0];
            vector<int> low, high;
            for(int i = 0;i<num.size();i++)
            {
                if(num[i]>pivot)
                    low.push_back(num[i]);
                else
                    high.push_back(num[i]);
            }
            vector<int> res;
            res = quickSort(low);    //result中，小的部分+标准值+大的部分
            res.push_back(pivot);
            res.insert(res.end(), quickSort(high).begin(), quickSort(high).end());
            return res;
        }
    }

    double mothod2(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        int m = nums2.size();

        if(n>m)
            return mothod2(nums2, nums1);

        int LMax1, RMin1, LMax2, RMin2, low = 0, high = 2*n, c1, c2;
        while(low<=high){
            c1 = (low+high)/2;
            c2 = m+n-c1;

            LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1-1)/2];
            RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1/2];
            LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2-1)/2];
            RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2/2];

            if(LMax1>RMin2)
                high = c1 - 1;
            else if(LMax2>RMin1)
                low = c1 + 1;
            else
                break;
        }
        return (max(LMax1, LMax2)+min(RMin1, RMin2))/2.0;
    }
};


int main(){
    Solution s;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4};
    double res = s.mothod2(nums1, nums2);
    cout<<res;
}