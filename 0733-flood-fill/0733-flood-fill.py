class Solution:
    def fill4D(self, image: List[List[int]], sr: int, sc: int, color: int, startColor: int) -> List[List[int]]:
        if sr < 0 or sc < 0 or sr == len(image) or sc == len(image[0]) or image[sr][sc] == color or image[sr][sc] != startColor:
            return image
        
        image[sr][sc] = color
        image = self.fill4D(image,sr+1,sc,color,startColor)
        image = self.fill4D(image,sr,sc+1,color,startColor)
        image = self.fill4D(image,sr-1,sc,color,startColor)
        image = self.fill4D(image,sr,sc-1,color,startColor)
        return image

    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        return self.fill4D(image,sr,sc,color,image[sr][sc])
        