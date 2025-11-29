class Solution(object):
    def isOneBitCharacter(self, bits):
        length = len(bits)
        if length == 1:
            return True
        i = 0
        while True:
            if bits[i] == 0:
                i += 1
            else:
                i += 2
            if i == length -1:
                return True
            if i > length -1:
                return False