class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x: x[1], reverse=True)
        
        totalUnits = 0
        size = 0

        for box in boxTypes:
            if size + box[0] > truckSize:
                totalUnits += box[1] * (truckSize - size)
                break
            else:
                totalUnits += box[0] * box[1]
                size += box[0]
        
        return totalUnits
