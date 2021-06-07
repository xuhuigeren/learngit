/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。


示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

限制：

0 <= matrix.length <= 100
0 <= matrix[i].length <= 100

*/

/*
算法流程：
空值处理： 当 matrix 为空时，直接返回空列表 {} 即可。
初始化： 矩阵 左、右、上、下 四个边界 l , r , t , b ，用于打印的结果列表 res 。
循环打印： “从左向右、从上向下、从右向左、从下向上” 四个方向循环，每个方向打印中做以下三件事 
（各方向的具体信息见下表） ；
根据边界打印，即将元素按顺序添加至列表 res 尾部；
边界向内收缩 1 （代表已被打印）；
判断是否打印完毕（边界是否相遇），若打印完毕则跳出。
返回值： 返回 res 即可。
打印方向	1. 根据边界打印	2. 边界向内收缩	3. 是否打印完毕
从左向右	左边界l ， 右边界r	上边界 t 加 1	是否 t > b
从上向下	上边界 t ，下边界b	右边界 r 减 1	是否 l > r
从右向左	右边界 r ，左边界l	下边界 b 减 1	是否 t > b
从下向上	下边界 b ，上边界t	左边界 l 加 1	是否 l > r
复杂度分析：
时间复杂度 O(MN) ： M, NM,N 分别为矩阵行数和列数。
空间复杂度 O(1) ： 四个边界 l , r , t , b 使用常数大小的 额外 空间（ res 为必须使用的空间）。

*/


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};

        vector<int> res;
        int m=matrix.size(), n=matrix[0].size(); // 行，列
        int left=0, right=n-1, top=0, bottom=m-1;

        while(true){
            // left--> right
            for(int i=left;i<=right;++i)   res.push_back(matrix[top][i]);
            if(++top>bottom) break;

            // top-->bottom
            for(int i=top;i<=bottom;++i)   res.push_back(matrix[i][right]);
            if(--right<left) break;

            // right-->left
            for(int i=right;i>=left;--i)   res.push_back(matrix[bottom][i]);
            if(--bottom<top) break;

            // bottom-->top
            for(int i=bottom;i>=top;--i)   res.push_back(matrix[i][left]);
            if(++left>right) break;
        }

        return res;

    }
};