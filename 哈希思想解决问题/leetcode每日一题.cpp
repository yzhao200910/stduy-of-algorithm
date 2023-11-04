//
// Created by 16537 on 2023/10/19.
//
/**
* 1726. 同积元组
提示
中等
71
相关企业
给你一个由 不同 正整数组成的数组 nums ，请你返回满足 a * b = c * d 的元组 (a, b, c, d) 的数量。其中 a、b、c 和 d 都是 nums 中的元素，且 a != b != c != d 。



示例 1：

输入：nums = [2,3,4,6]
输出：8
解释：存在 8 个满足题意的元组：
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
示例 2：

输入：nums = [1,2,4,5,10]
输出：16
解释：存在 16 个满足题意的元组：
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,4,5)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)


提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 104
nums 中的所有元素 互不相同   来自leetcode每日一题 网址：https://leetcode.cn/problems/tuple-with-same-product/?envType=daily-question&envId=2023-10-19
 *
*/
//思路枚举加哈希表计数
#include <vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                map[nums[i] * nums[j]]++;//对乘积相同的进行哈希计数
            }
        }
        for (auto &[k, v] : map) {
            count+= v * (v - 1) * 4;//计算结果
        }
        return count;
    }
};
