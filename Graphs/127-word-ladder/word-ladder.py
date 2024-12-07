class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: list[str]) -> int:
        # Create a set for fast lookup of words
        word_set = set(wordList)

        # If the endWord is not in the wordList, we cannot form a transformation
        if endWord not in word_set:
            return 0

        # BFS queue: stores (current word, transformation steps)
        queue = deque([(beginWord, 1)])
        word_set.discard(beginWord)  # Remove the starting word to avoid revisiting it

        while queue:
            word, steps = queue.popleft()

            # Try all possible transformations
            for i in range(len(word)):
                original_char = word[i]  # Save the original character

                # Replace with every possible character from 'a' to 'z'
                for ch in "abcdefghijklmnopqrstuvwxyz":
                    word = word[:i] + ch + word[i + 1 :]

                    # Check if the transformed word is the endWord
                    if word == endWord:
                        return steps + 1

                    # If the transformed word exists in the set, process it
                    if word in word_set:
                        word_set.remove(word)  # Remove the word from the set
                        queue.append((word, steps + 1))

                word = (
                    word[:i] + original_char + word[i + 1 :]
                )  # Restore the original character

        return 0  # If no transformation sequence is found
