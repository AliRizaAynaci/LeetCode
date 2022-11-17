class Solution:
    def computeArea(self,
                    ax1: int, ay1: int,
                    ax2: int, ay2: int,
                    bx1: int, by1: int,
                    bx2: int, by2: int) -> int:
        area_of_a = (ay2 - ay1) * (ax2 - ax1)
        area_of_b = (by2 - by1) * (bx2 - bx1)

        
        left = max(ax1, bx1)
        right = min(ax2, bx2)
        x_overlap = right - left

        
        top = min(ay2, by2)
        bottom = max(ay1, by1)
        y_overlap = top - bottom

        area_of_overlap = 0
        
        if x_overlap > 0 and y_overlap > 0:
            area_of_overlap = x_overlap * y_overlap

        total_area = area_of_a + area_of_b - area_of_overlap

        return total_area