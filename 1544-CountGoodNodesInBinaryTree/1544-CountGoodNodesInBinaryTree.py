# Last updated: 12/8/2025, 11:26:13 PM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def dfs(root, cap):
            if not root:
                return 0

            count = 0
            if root.val >= cap:
                cap = root.val
                count += 1

            return count + dfs(root.left, cap) + dfs(root.right, cap)

        return dfs(root, float("-inf"))