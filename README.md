# 🚀 LeetCode Solutions Repository

[![LeetCode](https://img.shields.io/badge/LeetCode-Solutions-orange?style=for-the-badge&logo=leetcode)](https://leetcode.com/u/Anurag_Basuri/)
[![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)](https://www.python.org/)
[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=openjdk&logoColor=white)](https://www.java.com/)

## 📖 About This Repository

This is a dedicated repository where I document my Data Structures and Algorithms (DSA) journey through LeetCode problem-solving. The repository contains **180+ solved problems** organized by topic categories, with solutions implemented in **Python**, **C++**, and **Java**.

## 📊 Repository Statistics

- **Total Problems Solved:** 180+ _(as of December 2024)_
- **Programming Languages:** 3 (Python, C++, Java)
- **Solution Files:** 315+ _(101 Python, 160 C++, 54 Java - as of December 2024)_
- **Topics Covered:** 18 categories
- **Regularly Updated:** ✅

## 📑 Table of Contents

- [Repository Structure](#-repository-structure)
- [Problem Categories](#-problem-categories)
- [How to Use This Repository](#-how-to-use-this-repository)
- [Languages & Examples](#-languages--examples)
- [Contributing](#-contributing)
- [Connect With Me](#-connect-with-me)

## 🗂️ Repository Structure

Each problem is organized in topic-specific folders with the following structure:

```
LeetSolution/
├── Arrays/
│   ├── [problem-number]-[problem-name]/
│   │   ├── README.md                      # Problem description
│   │   ├── [problem-name].py              # Python solution
│   │   ├── [problem-name].cpp             # C++ solution
│   │   └── [problem-name].java            # Java solution (if available)
├── Binary_Trees/
├── Dynamic_Programming/
└── ... (more topic folders)
```

Each problem folder contains:

- **README.md**: Complete problem statement from LeetCode
- **Solution files**: Named after the problem, implemented in Python, C++, and/or Java
- **Optimized approaches**: Focus on time and space complexity

## 📚 Problem Categories

| Category                   | Problems | Description                                   |
| -------------------------- | -------- | --------------------------------------------- |
| 🔢 **Arrays**              | 41       | Array manipulation, searching, sorting        |
| 🌳 **Binary Trees**        | 25       | Tree traversal, construction, manipulation    |
| 🔍 **Binary Search**       | 10       | Binary search variations and applications     |
| 🌲 **Binary Search Trees** | 8        | BST operations and properties                 |
| 📊 **Graphs**              | 15       | Graph traversal, shortest paths, connectivity |
| 🎯 **Dynamic Programming** | 4        | DP patterns and optimization                  |
| 💚 **Greedy**              | 12       | Greedy algorithms and optimization            |
| 🪟 **Sliding Window**      | 15       | Window-based array/string problems            |
| 🔤 **String**              | 18       | String manipulation and pattern matching      |
| #️⃣ **Hash Table**          | 6        | Hash-based data structures                    |
| 🔲 **Matrix**              | 5        | 2D array operations                           |
| ⚡ **Bit Manipulation**    | 7        | Bitwise operations                            |
| 🔝 **Priority Queue**      | 1        | Heap-based problems                           |
| 🛤️ **Shortest Path**       | 2        | Dijkstra, Bellman-Ford algorithms             |
| 📋 **Topological Sort**    | 6        | Graph ordering problems                       |
| 👉👈 **Two Pointer**       | 5        | Two-pointer technique                         |
| 🔗 **Linked List**         | 3        | Linked list manipulation                      |
| 🔢 **Math**                | 6        | Number theory, arithmetic                     |

## 🎯 How to Use This Repository

### For Learning

1. **Browse by Topic**: Navigate to the category you're studying
2. **Read the Problem**: Each folder contains a README with the problem statement
3. **Study Solutions**: Compare implementations across different languages
4. **Understand Complexity**: Solutions focus on optimal time and space complexity

### For Interview Preparation

1. **Practice by Category**: Focus on weak areas systematically
2. **Multiple Languages**: See the same logic in Python, C++, and Java
3. **Learn Patterns**: Identify common patterns across similar problems

### Structure Example

```bash
# Navigate to a specific problem (e.g., Product of Array Except Self)
cd Arrays/238-product-of-array-except-self/

# View problem description
cat README.md

# Study solutions in different languages
cat product-of-array-except-self.py    # Python solution
cat product-of-array-except-self.cpp   # C++ solution
```

## 💻 Languages & Examples

### Python

```python
# Example: Clean, readable solutions with Pythonic approaches
def twoSum(nums, target):
    seen = {}
    for i, num in enumerate(nums):
        if target - num in seen:
            return [seen[target - num], i]
        seen[num] = i
```

### C++

```cpp
// Example: Efficient implementations with STL
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); i++) {
        if (seen.count(target - nums[i]))
            return {seen[target - nums[i]], i};
        seen[nums[i]] = i;
    }
    return {};
}
```

### Java

```java
// Example: Object-oriented solutions
public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> seen = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        int complement = target - nums[i];
        if (seen.containsKey(complement))
            return new int[]{seen.get(complement), i};
        seen.put(nums[i], i);
    }
    return new int[]{};
}
```

## 🤝 Contributing

While this is a personal learning repository, I welcome:

- 🐛 Bug reports for incorrect solutions
- 💡 Suggestions for optimization
- 📝 Alternative approaches or solutions

Feel free to open an issue for discussion!

## 🔗 Connect With Me

- **LeetCode Profile:** [Anurag Basuri](https://leetcode.com/u/Anurag_Basuri/)
- **GitHub:** [@Anurag-Basuri](https://github.com/Anurag-Basuri)

---

<div align="center">

### ⭐ Star this repository if you find it helpful!

**Happy Coding! 💻**

</div>
