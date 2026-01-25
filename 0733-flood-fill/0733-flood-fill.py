class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if image[sr][sc] == color:
            return image
        
        currentColor = image[sr][sc]
        image[sr][sc] = color
        if sc != len(image[0]) - 1 and image[sr][sc+1] == currentColor:
            self.floodFill(image, sr, sc+1, color)
        if sr!= len(image) - 1 and image[sr+1][sc] == currentColor:
            self.floodFill(image, sr+1, sc, color)
        if sc!=0 and image[sr][sc-1] == currentColor:
            self.floodFill(image, sr, sc-1, color)
        if sr!=0 and image[sr-1][sc] == currentColor:
            self.floodFill(image, sr-1, sc, color)
        
        return image
        