/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

 

示例 1：

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
 

提示：

2 <= n <= 1000
*/


/*
这题再用动态规划的话惨不忍睹，还是要看贪心
核心思路是：尽可能把绳子分成长度为3的小段，这样乘积最大

证明可参考这个题解

步骤如下：

1. 如果 n == 2，返回1，如果 n == 3，返回2，两个可以合并成n小于4的时候返回n - 1
2. 如果 n == 4，返回4
3. 如果 n > 4，分成尽可能多的长度为3的小段，每次循环长度n减去3，乘积res乘以3；
   最后返回时乘以小于等于4的最后一小段；每次乘法操作后记得取余就行
4. 以上2和3可以合并

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        int base = 1000000007;
        if (n < 4)         return n-1;
        else if (n == 4)   return n;

        long res = 1;
        while (n > 4){
            n -= 3;
            res = (res * 3) % base;
        }

        return (res * n)% base;
    }
};




int main(){
   
    int res = Solution().cuttingRope(88);


    cout << res << endl;
    return 0;    
}
