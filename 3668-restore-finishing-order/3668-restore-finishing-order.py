class Solution:
    def recoverOrder(self, order: List[int], friends: List[int]) -> List[int]:
        friendsset = set(friends)
        ans = []
        for friend in order:
            if friend in friendsset:
                ans.append(friend)
        return ans