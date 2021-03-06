// 572. 另一个树的子树
// 给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

// 示例 1:
// 给定的树 s:

//      3
//     / \
//    4   5
//   / \
//  1   2
// 给定的树 t：

//    4 
//   / \
//  1   2
// 返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

// 示例 2:
// 给定的树 s：

//      3
//     / \
//    4   5
//   / \
//  1   2
//     /
//    0
// 给定的树 t：

//    4
//   / \
//  1   2
// 返回 false。

// https://leetcode-cn.com/problems/subtree-of-another-tree/submissions/



//My Codes
// 执行结果：通过
// 执行用时 :40 ms, 在所有 C++ 提交中击败了66.30%的用户
// 内存消耗 :29.1 MB, 在所有 C++ 提交中击败了12.50%的用户
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
class Solution {
public:
    bool isSameTree(TreeNode* s, TreeNode* t) 
    {
        return (!s && !t) ? true : (s && t && s->val == t->val && isSameTree(s->left, t->left) && isSameTree(s->right, t->right));
    }

    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        return s ? (isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t)) : false;
    }
};



//nice codes:
// 遍历
class Solution {
public:
        bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        return isSubtree(s->left, t) || SameTree(s, t) || isSubtree(s->right, t);
    }

    bool SameTree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        return s->val == t->val && SameTree(s->left, t->left) && SameTree(s->right, t->right);
    }

};