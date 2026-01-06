import os

base_path = r"d:\projects\LeetSolution"

data = {
    "Arrays": {
        "desc": "An array is a linear data structure collecting elements of the same type in contiguous memory locations. It's fundamental for building other data structures.",
        "concepts": ["Prefix Sum", "Kadane's Algorithm", "Two Pointers", "Sliding Window", "Sorting", "Binary Search"],
        "complexity": "Access: O(1) | Search: O(n) | Insert/Delete: O(n)"
    },
    "Binary_Search": {
        "desc": "Binary Search is a divide-and-conquer algorithm that locates a value in a sorted sequence by repeatedly dividing the search interval in half.",
        "concepts": ["Lower Bound", "Upper Bound", "Search Answer Space", "Rotated Sorted Array"],
        "complexity": "Time: O(log n) | Space: O(1)"
    },
    "Binary_Search_Trees": {
        "desc": "A Binary Search Tree (BST) is a binary tree where the left child is smaller and the right child is greater than the parent node.",
        "concepts": ["Inorder Traversal (Sorted)", "Insertion/Deletion", "Balancing (AVL/Red-Black)", "LCA in BST"],
        "complexity": "Search/Insert/Delete: O(h) where h is height (O(log n) balanced, O(n) skewed)"
    },
    "Binary_Trees": {
        "desc": "A Binary Tree is a hierarchical structure where each node has at most two children. It's the basis for BSTs, Heaps, and Tries.",
        "concepts": ["DFS (Pre/In/Post)", "BFS (Level Order)", "Height/Depth", "Diameter", "LCA"],
        "complexity": "Traversal: O(n) | Space: O(h)"
    },
    "Bit_Manipulation": {
        "desc": "Bit Manipulation involves applying logical operations on bit patterns. It's crucial for optimization and low-level programming.",
        "concepts": ["XOR Properties", "Bit Masking", "Shifting (<<, >>)", "Brian Kernighan's Algorithm"],
        "complexity": "Operations: O(1)"
    },
    "Dynamic_Programming": {
        "desc": "Dynamic Programming (DP) is an optimization technique that solves complex problems by breaking them into simpler overlapping subproblems.",
        "concepts": ["Memoization (Top-Down)", "Tabulation (Bottom-Up)", "Knapsack Pattern", "LCS/LIS Patterns"],
        "complexity": "Time: O(States × Transitions) | Space: O(States)"
    },
    "Graphs": {
        "desc": "A Graph is a non-linear structure consisting of vertices and edges. It models pairwise relations between objects.",
        "concepts": ["Adjacency Matrix/List", "BFS/DFS", "Connected Components", "Cycle Detection", "Bipartite Check"],
        "complexity": "BFS/DFS: O(V + E)"
    },
    "Greedy": {
        "desc": "Greedy algorithms make the locally optimal choice at each step with the hope of finding a global optimum.",
        "concepts": ["Interval Scheduling", "Huffman Coding", "Activity Selection", "Dijkstra's Algo usage"],
        "complexity": "Varies (often O(n log n) due to sorting)"
    },
    "Hash_Table": {
        "desc": "A Hash Table implements an associative array abstract data type that maps keys to values using a hash function.",
        "concepts": ["Collision Resolution", "HashMap vs HashSet", "Counting Frequencies", "Two Sum Pattern"],
        "complexity": "Access/Insert/Delete: O(1) average"
    },
    "Linked_List": {
        "desc": "A Linked List is a linear collection of nodes where each node points to the next. It allows efficient insertion and deletion.",
        "concepts": ["Fast & Slow Pointers", "Reversal", "Dummy Node", "Merge Two Lists", "Cycle Detection"],
        "complexity": "Access: O(n) | Insert/Delete: O(1) (at known position)"
    },
    "Math": {
        "desc": "Problems involving number theory, geometry, combinatorics, and basic arithmetic operations.",
        "concepts": ["GCD/LCM (Euclid)", "Sieve of Eratosthenes", "Modular Arithmetic", "Combinatorics", "Geometry"],
        "complexity": "Varies by algorithm"
    },
    "Matrix": {
        "desc": "Matrix problems involve operations on 2D arrays (grids). Common in graph traversals and DP.",
        "concepts": ["Grid Traversal (DFS/BFS)", "Matrix Rotation", "Spiral Order", "DP on Grids"],
        "complexity": "Traversal: O(R × C)"
    },
    "Priority_Queue": {
        "desc": "A Priority Queue is an abstract data type where each element has a priority. Elements are served based on priority (Heaps).",
        "concepts": ["Min-Heap / Max-Heap", "K-th Largest/Smallest", "Median from Data Stream", "Merge K Lists"],
        "complexity": "Insert/Extract: O(log n) | Peek: O(1)"
    },
    "Shortest_Path_Algo": {
        "desc": "Algorithms designed to find the shortest path between nodes in a graph.",
        "concepts": ["Dijkstra's Algorithm (Non-negative weights)", "Bellman-Ford (Negative weights)", "Floyd-Warshall (All-pairs)"],
        "complexity": "Dijkstra: O(E log V)"
    },
    "Sliding_Window": {
        "desc": "Sliding Window is a technique to optimize problems involving subarrays or substrings by maintaining a window of elements.",
        "concepts": ["Fixed Size Window", "Variable Size Window", "Shrinkable Window", "Hash Map with Window"],
        "complexity": "Time: O(n) | Space: O(1) or O(k)"
    },
    "String": {
        "desc": "String manipulation involves processing sequences of characters. Includes matching, parsing, and transformation.",
        "concepts": ["Two Pointers", "KMP Algorithm", "Rabin-Karp", "Trie", "Palindrome Properties"],
        "complexity": "Varies, often O(n)"
    },
    "Topological_Sort": {
        "desc": "Topological Sort is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every edge u->v, u comes before v.",
        "concepts": ["Kahn's Algorithm (BFS)", "DFS Approach", "Cycle Detection in DAG", "Dependency Resolution"],
        "complexity": "Time: O(V + E)"
    },
    "Two_Pointer": {
        "desc": "Two Pointers is a technique used to search for pairs or iterate structures (arrays/lists) usually to optimize time complexity.",
        "concepts": ["Opposite Direction (Sum types)", "Same Direction (Fast/Slow)", "Partitioning", "Merging"],
        "complexity": "Time: O(n) | Space: O(1)"
    }
}

template = """# 📘 {category}

{desc}

## 🧠 Key Concepts
{concepts_str}

## ⚙️ Complexity Analysis
- **Complexity**: {complexity}

## 📝 Common Patterns & Tips
- Identify the problem constraints.
- Choose the data structure that best fits the operations (access vs. search vs. update).
- Consider edge cases (empty input, single element, duplicates).

---
*Happy Coding! 🚀*
"""

for folder, info in data.items():
    folder_path = os.path.join(base_path, folder)
    if not os.path.exists(folder_path):
        print(f"Skipping {folder}, does not exist.")
        continue
        
    concepts_str = "\n".join([f"- {c}" for c in info['concepts']])
    content = template.format(
        category=folder.replace('_', ' '), 
        desc=info['desc'], 
        concepts_str=concepts_str, 
        complexity=info['complexity']
    )
    
    file_path = os.path.join(folder_path, "README.md")
    
    # Don't overwrite if it exists and is non-trivial? 
    # User asked to adds MD file, assuming overwrite or create. I'll overwrite to ensure consistency.
    with open(file_path, "w", encoding="utf-8") as f:
        f.write(content)
    print(f"Created README.md in {folder}")

print("Done creating READMEs.")
