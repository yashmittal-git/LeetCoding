# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        from queue import Queue
        q = Queue()
        q.put(root)

        levelOrderTraversal = []
        while not q.empty():
            nodesAtLevel = []
            sizeOfLevel = q.qsize()
            for i in range(sizeOfLevel):
                node = q.get()
                nodesAtLevel.append(node.val)
                if node.left:
                    q.put(node.left)
                if node.right:
                    q.put(node.right)
                
            levelOrderTraversal.append(nodesAtLevel)
        
        return levelOrderTraversal

