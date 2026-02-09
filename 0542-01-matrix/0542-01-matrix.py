class Solution:

    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        INT_MAX = 100000
        distances = [[INT_MAX] * len(mat[0]) for _ in range(len(mat))]

        for row in range(len(mat)):
            for col in range(len(mat[row])):
                if mat[row][col] == 0:
                    distances[row][col] = 0
                else:
                    d1, d2 = INT_MAX, INT_MAX
                    if row > 0:
                        d1 = distances[row-1][col]
                    if col > 0:
                        d2 = distances[row][col-1]
                    distances[row][col] = min(d1,d2) + 1   

        for row in range(len(mat)-1,-1,-1):
            for col in range(len(mat[0])-1,-1,-1):
                if mat[row][col] != 0:
                    if row < len(mat)-1:
                        distances[row][col] = min(distances[row][col],1+distances[row+1][col])     
                    if col < len(mat[0])-1:
                        distances[row][col] = min(distances[row][col],1+distances[row][col+1])     
        
        return distances