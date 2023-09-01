class Solution:

    startColor: int

    def fill4D(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if sr < 0 or sc < 0 or sr == len(image) or sc == len(image[0]) or image[sr][sc] == color or image[sr][sc] != self.startColor:
            return image
        
        image[sr][sc] = color
        image = self.fill4D(image,sr+1,sc,color)
        image = self.fill4D(image,sr,sc+1,color)
        image = self.fill4D(image,sr-1,sc,color)
        image = self.fill4D(image,sr,sc-1,color)
        return image

    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        self.startColor = image[sr][sc]
        return self.fill4D(image,sr,sc,color)