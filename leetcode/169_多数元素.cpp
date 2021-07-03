/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。


你可以假设数组是非空的，并且给定的数组总是存在多数元素。


示例 1:

输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
 

限制：

1 <= 数组长度 <= 50000

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 摩尔投票法
        int x=0, votes=0, count=0;
        for(int num:nums){
            if(votes==0) x=num;
            votes+= x==num? 1:-1;
        }
        return x;
    }
};
