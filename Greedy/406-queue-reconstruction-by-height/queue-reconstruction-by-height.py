class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key = lambda x:(-x[0], x[1]))

        result = []

        for person in people:
            result.insert(person[1], person)
        
        return result