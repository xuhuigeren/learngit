/*  
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。

 

示例 1：          5
                /  \   
               4    8
              /     / \
            11     13  4
           /  \       / \
          7    2     5   1



输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：[[5,4,11,2],[5,8,4,5]]

示例 2：
                 1
                / \   
               2   3

输入：root = [1,2,3], targetSum = 5
输出：[]
示例 3：

输入：root = [1,2], targetSum = 0
输出：[]
 

提示：

树中节点总数在范围 [0, 5000] 内
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000


*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//递归，但是多次拷贝path

class Solution {
public:
    //全局变量
    vector<vector <int>> res;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root,targetSum,path);
        return res;

    }

    void dfs(TreeNode* root, int sum, vector<int> path){
        if(!root)  return;
        sum=sum-root->val;
        path.push_back(root->val);
        //递归终止条件
        if(!root->left&&!root->right&&sum==0){
            res.push_back(path);
            return;
        }
        //递归
        dfs(root->left,sum,path);
        dfs(root->right,sum,path);

    }
};


//DFS + 回溯
class Solution {

    vector<vector <int>> res;
    vector<int> path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return res;

    }

    void dfs(TreeNode* root, int sum){
        if(!root)  return;
        sum=sum-root->val;
        path.push_back(root->val);
        if(!root->left&&!root->right&&sum==0){
            res.push_back(path);
        }
        dfs(root->left,sum);
        dfs(root->right,sum);
        //回溯，非常重要
        path.pop_back();
    }
};

