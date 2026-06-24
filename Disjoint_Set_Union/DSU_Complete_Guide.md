# Disjoint Set Union (DSU) — The Complete Guide

> **Your one-stop reference** for understanding, implementing, optimizing, and applying DSU.  
> Covers theory, code, complexity proofs, real-world usage, and common interview traps.

---

## Table of Contents

1. [What Problem Does DSU Solve?](#1-what-problem-does-dsu-solve)
2. [The Naive Approach (and Why It Fails)](#2-the-naive-approach-and-why-it-fails)
3. [DSU Mental Model — Forests of Trees](#3-dsu-mental-model--forests-of-trees)
4. [The Two Core Operations](#4-the-two-core-operations)
5. [Basic Implementation (No Optimizations)](#5-basic-implementation-no-optimizations)
6. [Optimization 1 — Union by Rank](#6-optimization-1--union-by-rank)
7. [Optimization 2 — Union by Size](#7-optimization-2--union-by-size)
8. [Optimization 3 — Path Compression](#8-optimization-3--path-compression)
9. [The Power Combo: Both Optimizations Together](#9-the-power-combo-both-optimizations-together)
10. [Full Production-Ready C++ Class](#10-full-production-ready-c-class)
11. [Time & Space Complexity Deep Dive](#11-time--space-complexity-deep-dive)
12. [0-Based vs 1-Based Indexing](#12-0-based-vs-1-based-indexing)
13. [Classic DSU Applications](#13-classic-dsu-applications)
14. [Real Interview Problems (with Approach)](#14-real-interview-problems-with-approach)
15. [Edge Cases & Common Mistakes](#15-edge-cases--common-mistakes)
16. [DSU vs BFS/DFS — When to Use What](#16-dsu-vs-bfsdfs--when-to-use-what)
17. [Advanced DSU Tricks](#17-advanced-dsu-tricks)
18. [Weighted DSU (Bonus — Very Rare, Very Powerful)](#18-weighted-dsu-bonus--very-rare-very-powerful)
19. [Quick Reference Cheat Sheet](#19-quick-reference-cheat-sheet)
20. [Practice Problems Roadmap](#20-practice-problems-roadmap)
21. **[How to Identify a DSU Problem ← NEW](#21-how-to-identify-a-dsu-problem)**
22. **[The Problem-Solving Approach — Step by Step ← NEW](#22-the-problem-solving-approach--step-by-step)**

---

## 1. What Problem Does DSU Solve?

Imagine a social network. At any point in time you need to answer:
- **"Are Alice and Bob connected (directly or indirectly)?"**
- **"Connect Alice's group with Bob's group."**

These are called **dynamic connectivity queries**. You have `n` elements, and over time you receive two types of requests:
- `union(a, b)` — merge the group of `a` with the group of `b`
- `find(a) == find(b)` — check if `a` and `b` are in the same group

Formally, you're maintaining a **partition** of a set into **disjoint** (non-overlapping) **subsets**.

```
Initially:   {0} {1} {2} {3} {4}     ← 5 separate components

union(0,1):  {0,1} {2} {3} {4}
union(1,2):  {0,1,2} {3} {4}
union(3,4):  {0,1,2} {3,4}

find(0)==find(2)?  YES  (same component)
find(0)==find(3)?  NO   (different components)
```

DSU does both operations in **near O(1)** time. That's the magic.

---

## 2. The Naive Approach (and Why It Fails)

**Brute force idea:** Store a `component_id[]` array. Every node holds its component label.

```cpp
// Naive union: re-label all nodes of one group
void union_naive(int a, int b) {
    int old_label = component[b];
    int new_label = component[a];
    for (int i = 0; i < n; i++)
        if (component[i] == old_label)
            component[i] = new_label;  // O(n) per union!
}

bool find_naive(int a, int b) {
    return component[a] == component[b];  // O(1) find
}
```

**Problem:** `union` is O(n). With n operations that's O(n²) total — catastrophic for n = 10⁵ or 10⁶.

**BFS/DFS approach:** Also O(n + E) per query. For Q queries on a graph with E edges: O(Q × (n + E)) — still terrible.

DSU gives you essentially O(1) per operation regardless.

---

## 3. DSU Mental Model — Forests of Trees

DSU represents each component as a **rooted tree**. The root is the "boss" or "ultimate parent" of that component.

```
Component {0, 1, 2, 3}:

       0         ← root (boss of this component)
      / \
     1   2
     |
     3

find(3) → follows: 3 → 1 → 0  → returns 0 (the root)
find(2) → follows: 2 → 0      → returns 0 (same root)

So find(3) == find(2) → they're in the same component ✓
```

The collection of all trees is called a **forest**. Initially, every node is its own tree (root = itself).

**Key insight:** Two nodes are in the same component **if and only if they have the same root.**

---

### Full Step-by-Step Walkthrough — 6 Nodes

Let's trace every operation and watch the `parent[]` array evolve alongside the tree diagram.

**Initial state — 6 isolated nodes (indices 0–5):**
```
parent[] = [0, 1, 2, 3, 4, 5]
index       0  1  2  3  4  5

Trees:   (0) (1) (2) (3) (4) (5)   ← every node is its own root
```

---

**After `unite(0, 1)`:**
```
parent[] = [0, 0, 2, 3, 4, 5]
                ^
                1's parent is now 0

Trees:    0   (2) (3) (4) (5)
          |
          1
```

---

**After `unite(2, 3)`:**
```
parent[] = [0, 0, 2, 2, 4, 5]
                      ^
                      3's parent is now 2

Trees:    0    2   (4) (5)
          |    |
          1    3
```

---

**After `unite(0, 2)` — merging two groups:**
```
find(0) = 0,  find(2) = 2

parent[] = [0, 0, 0, 2, 4, 5]
                  ^
                  2's parent is now 0

Trees:       0      (4) (5)
           / | \
          1  2
             |
             3

Now {0,1,2,3} are all one component.
find(3) = 3→2→0 = 0
find(1) = 1→0   = 0   ← same root, same component ✓
```

---

**After `unite(4, 5)` and then `unite(1, 4)`:**
```
Step 1: unite(4,5)
parent[] = [0, 0, 0, 2, 4, 4]   (5's parent = 4)

Step 2: unite(1, 4)
  find(1) = 1→0 = 0
  find(4) = 4
  → 4's parent = 0

parent[] = [0, 0, 0, 2, 0, 4]
                         ^
                         4 now under 0

Final tree:
           0           ← root of everything
         / | \ \
        1  2   4
           |   |
           3   5

All 6 nodes in one component.
find(5) = 5→4→0 = 0
find(3) = 3→2→0 = 0
find(5) == find(3) → true ✓
```

---

## 4. The Two Core Operations

### `find(x)` — Who is the boss?

Walk up the parent pointers from `x` until you reach a node that is its own parent (the root).

### `union(a, b)` — Merge two groups

1. Find root of `a` → call it `ra`
2. Find root of `b` → call it `rb`
3. If `ra == rb`: already in same component, do nothing
4. Otherwise: attach one root under the other

The **secret sauce** is *how* you attach (union by rank/size) and *how* you find (path compression). Both optimizations are explained below.

---

## 5. Basic Implementation (No Optimizations)

```cpp
#include <bits/stdc++.h>
using namespace std;

struct DSU_Basic {
    vector<int> parent;
    
    DSU_Basic(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }
    
    int find(int x) {
        if (parent[x] == x) return x;       // x is its own root
        return find(parent[x]);              // recurse up the tree
    }
    
    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return;               // already connected
        parent[ra] = rb;                    // attach ra under rb (arbitrary)
    }
    
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};
```

**Problem with this:**  
In the worst case (linear chain), the tree can become a linked list:
```
0 → 1 → 2 → 3 → 4 → 5
```
Then `find(0)` takes O(n). That's no better than brute force.

---

## 6. Optimization 1 — Union by Rank

**Big idea:** Keep trees short. When merging, attach the *shorter tree* under the *taller tree*.

We don't track exact heights (too expensive to maintain after path compression), so we track an approximation called **rank**.

### What is Rank?

- Initially, every node has `rank = 0`
- When two roots with **different ranks** merge: the higher-rank root wins, rank unchanged
- When two roots with **equal ranks** merge: either can win, but the winner's rank increases by 1

Rank is an *upper bound* on the actual height of the subtree.

### Why does this work?

A root with rank `r` has at least `2^r` nodes in its subtree. So rank can grow at most `log₂(n)`. This bounds the tree height to `O(log n)`.

```cpp
struct DSU_Rank {
    vector<int> parent, rank;
    
    DSU_Rank(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] == x) return x;
        return find(parent[x]);
    }
    
    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return;
        
        // Always attach lower rank under higher rank
        if (rank[ra] < rank[rb]) swap(ra, rb);
        // Now rank[ra] >= rank[rb]
        
        parent[rb] = ra;                    // rb goes under ra
        if (rank[ra] == rank[rb])
            rank[ra]++;                     // only increase if equal
    }
};
```

### Rank Rules — Visualized

```
Before:           After union(A,B) where rank[A]=1, rank[B]=0:

   A (rank=1)        A (rank=1, unchanged)
   |                / \
   x              x    B (rank=0)

Before:           After union(A,B) where rank[A]=rank[B]=1:

A(r=1)  B(r=1)      A (rank=2, increased!)
  |       |         /  \
  x       y       x     B(r=1)
                         |
                         y
```

---

## 7. Optimization 2 — Union by Size

**Alternative to rank.** Track the actual number of nodes in each component (`size` array). Attach the smaller-size tree under the larger one.

Many competitive programmers prefer this because:
- Size is a real, meaningful number (unlike rank, which is an approximation)
- You can query component size in O(1)
- Equally effective for keeping trees balanced

```cpp
struct DSU_Size {
    vector<int> parent, size;
    
    DSU_Size(int n) {
        parent.resize(n);
        size.assign(n, 1);                  // each node is its own component of size 1
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] == x) return x;
        return find(parent[x]);
    }
    
    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return;
        
        // Attach smaller under larger
        if (size[ra] < size[rb]) swap(ra, rb);
        // Now size[ra] >= size[rb]
        
        parent[rb] = ra;
        size[ra] += size[rb];               // update size of the merged component
    }
    
    int getSize(int x) {
        return size[find(x)];               // size of the component containing x
    }
};
```

### Size vs Rank — Which to Use?

| Aspect | Union by Rank | Union by Size |
|---|---|---|
| Tracks | Upper bound on height | Actual node count |
| Extra info | Just height approx | Component size (useful!) |
| Correctness | Yes | Yes |
| Performance | Same | Same |
| Preference | Older tutorials | Modern CP/interviews |

**Verdict: Use size in competitive programming.** It gives you free component-size queries.

---

## 8. Optimization 3 — Path Compression

**The second key optimization.** After finding the root during `find(x)`, make every node on the path point **directly** to the root. Future queries become O(1).

### Without Path Compression:

```
find(5) traversal:   5 → 3 → 1 → 0 (root)
Tree:   0
        |
        1
        |
        3
        |
        5
```

### With Path Compression — Detailed Trace:

```
BEFORE find(5):

parent[] = [0, 0, 0, 1, 2, 3]
index       0  1  2  3  4  5

Tree (a deep chain):
  0
  |
  1
  |
  3
  |
  5

Also separately: 0→2→4 (node 4 hangs off 2)
```

Now call `find(5)` with path compression:

```
Step 1: find(5) calls find(parent[5]) = find(3)
Step 2: find(3) calls find(parent[3]) = find(1)
Step 3: find(1) calls find(parent[1]) = find(0)
Step 4: find(0) → parent[0]==0, BASE CASE, returns 0

Now the call stack UNWINDS, setting parents:
  parent[1] = 0   (1 now points directly to root)
  parent[3] = 0   (3 now points directly to root)
  parent[5] = 0   (5 now points directly to root)
```

```
AFTER find(5):

parent[] = [0, 0, 0, 0, 2, 0]
index       0  1  2  3  4  5
                  ^        ^
                  4 still  all others
                  points   now point
                  to 2     to root 0

Tree (now almost flat):
  0
 /|\
1 3 5     ← 1, 3, 5 all point directly to root
  |
  (2 → 4 unchanged since we didn't traverse that path)
```

```
NEXT CALL: find(5)
  parent[5] == 0 == root → return immediately in ONE step!

NEXT CALL: find(3)
  parent[3] == 0 == root → return immediately in ONE step!
```

**The "expensive" first traversal pays for itself by making all future traversals on that path cost O(1).**

Next call to `find(5)` → returns in ONE step.

### Implementation (Recursive — Elegant):

```cpp
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);     // ← THE MAGIC LINE
    // sets parent[x] = root, then returns root
}
```

### Implementation (Iterative — Stack-safe for large inputs):

```cpp
int find(int x) {
    int root = x;
    while (parent[root] != root)            // find root
        root = parent[root];
    
    while (parent[x] != root) {            // path compression
        int next = parent[x];
        parent[x] = root;
        x = next;
    }
    return root;
}
```

> **Warning:** The recursive version can cause stack overflow for very deep trees (before compression) on large inputs (~10⁵+ nodes). Prefer iterative in contests.

---

## 9. The Power Combo: Both Optimizations Together

Use **both** Union by Rank/Size **AND** Path Compression together. This gives the famous near-constant time complexity.

```cpp
// find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);   // compress the path
    return parent[x];
}

// union with rank
void unite(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra == rb) return;
    if (rank[ra] < rank[rb]) swap(ra, rb);
    parent[rb] = ra;
    if (rank[ra] == rank[rb]) rank[ra]++;
}
```

**Why do they work well together?**

- Union by rank/size ensures trees are initially balanced (no deep trees)
- Path compression flattens trees during find operations
- Together: nearly all nodes point directly to their root → find is instant

---

### Full Combined Trace — 7 Nodes with Both Optimizations

Watch how `parent[]`, `size[]`, and the tree all evolve together.

```
INITIAL STATE (n=7):

parent[] = [0, 1, 2, 3, 4, 5, 6]
size[]   = [1, 1, 1, 1, 1, 1, 1]
Trees: (0)(1)(2)(3)(4)(5)(6)
```

**`unite(0, 1)`:**  size[0]=1 == size[1]=1 → 0 wins (or either, by convention)
```
parent[] = [0, 0, 2, 3, 4, 5, 6]
size[]   = [2, 1, 1, 1, 1, 1, 1]

  0
  |
  1
```

**`unite(2, 3)`:**
```
parent[] = [0, 0, 2, 2, 4, 5, 6]
size[]   = [2, 1, 2, 1, 1, 1, 1]

  0    2
  |    |
  1    3
```

**`unite(4, 5)`:**
```
parent[] = [0, 0, 2, 2, 4, 4, 6]
size[]   = [2, 1, 2, 1, 2, 1, 1]

  0    2    4
  |    |    |
  1    3    5
```

**`unite(0, 2)`:**  size[0]=2 == size[2]=2 → 0 wins, size[0] becomes 4
```
parent[] = [0, 0, 0, 2, 4, 4, 6]
size[]   = [4, 1, 2, 1, 2, 1, 1]

      0          4
    /   \         |
   1     2        5
         |
         3
```

**`unite(0, 4)`:**  size[0]=4 > size[4]=2 → 0 wins, size[0] becomes 6
```
parent[] = [0, 0, 0, 2, 0, 4, 6]
size[]   = [6, 1, 2, 1, 2, 1, 1]

        0
      / | \
     1  2   4
        |   |
        3   5
```

Now `find(3)` with path compression:
```
find(3): parent[3]=2, parent[2]=0 (root)
  → sets parent[3] = 0

parent[] = [0, 0, 0, 0, 0, 4, 6]
                      ^
                      3 now points directly to 0

Tree after compression:
        0
      / | \ \
     1  2  3  4
              |
              5

Next find(3): ONE step → parent[3]=0, done!
```

---

## 10. Full Production-Ready C++ Class

Here is a clean, reusable DSU class for both 0-based and 1-based indexing, with all features:

```cpp
#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent, sz;
    int components;

public:
    // Constructor: n nodes, 0-indexed [0, n-1]
    DSU(int n) : parent(n), sz(n, 1), components(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    // Find with path compression (iterative — stack safe)
    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];  // path halving (slightly faster)
            x = parent[x];
        }
        return x;
    }

    // Union by size — returns true if they were in different components
    bool unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;         // already connected

        if (sz[ra] < sz[rb]) swap(ra, rb);
        parent[rb] = ra;
        sz[ra] += sz[rb];
        components--;
        return true;
    }

    // Check if two nodes are in the same component
    bool connected(int a, int b) {
        return find(a) == find(b);
    }

    // Get size of the component containing node x
    int getSize(int x) {
        return sz[find(x)];
    }

    // Get number of distinct components currently
    int getComponents() {
        return components;
    }
};

// =============================================
// For 1-BASED indexing: just do DSU dsu(n+1)
// and use nodes 1 through n.
// =============================================
```

### Usage Example:

```cpp
int main() {
    int n = 6;
    DSU dsu(n);  // nodes 0 to 5

    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(3, 4);

    cout << dsu.connected(0, 2) << "\n";   // 1 (true)
    cout << dsu.connected(0, 3) << "\n";   // 0 (false)
    cout << dsu.getSize(0) << "\n";        // 3 (nodes 0,1,2)
    cout << dsu.getComponents() << "\n";   // 3 ({0,1,2}, {3,4}, {5})

    dsu.unite(2, 4);
    cout << dsu.connected(0, 3) << "\n";   // 1 (now connected)
    cout << dsu.getComponents() << "\n";   // 2

    return 0;
}
```

### Python Version:

```python
class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.components = n

    def find(self, x):
        while self.parent[x] != x:
            self.parent[x] = self.parent[self.parent[x]]  # path halving
            x = self.parent[x]
        return x

    def unite(self, a, b):
        ra, rb = self.find(a), self.find(b)
        if ra == rb:
            return False
        if self.size[ra] < self.size[rb]:
            ra, rb = rb, ra
        self.parent[rb] = ra
        self.size[ra] += self.size[rb]
        self.components -= 1
        return True

    def connected(self, a, b):
        return self.find(a) == self.find(b)

    def get_size(self, x):
        return self.size[self.find(x)]
```

### Java Version:

```java
class DSU {
    int[] parent, size;
    int components;

    DSU(int n) {
        parent = new int[n];
        size = new int[n];
        components = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    boolean unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;
        if (size[ra] < size[rb]) { int t = ra; ra = rb; rb = t; }
        parent[rb] = ra;
        size[ra] += size[rb];
        components--;
        return true;
    }

    boolean connected(int a, int b) {
        return find(a) == find(b);
    }
}
```

---

## 11. Time & Space Complexity Deep Dive

### Space Complexity
- **O(n)** — just the `parent` and `size/rank` arrays. That's it.

### Time Complexity

| Implementation | find | unite |
|---|---|---|
| No optimization | O(n) worst case | O(n) |
| Union by rank only | O(log n) | O(log n) |
| Path compression only | O(log n) amortized | O(log n) amortized |
| **Both together** | **O(α(n)) amortized** | **O(α(n)) amortized** |

### What is α(n)? The Inverse Ackermann Function

α(n) is the **inverse Ackermann function**. Here's the crazy truth:

```
α(1)         = 0
α(2)         = 1
α(4)         = 2
α(16)        = 3
α(65536)     = 4
α(2^65536)   = 5
```

For any input you will **ever** encounter in the observable universe, α(n) ≤ 4.

The number of atoms in the observable universe is about 10^80. Yet:
```
α(10^80) = 4
```

So α(n) = 4 for literally any practical n. This means DSU operations are, for all practical purposes, **O(1)**.

It's not exactly O(1) in theory — but in practice, no one has ever seen it be more than 4 steps.

### Amortized Analysis (Intuition)

"Amortized O(α(n))" means: over a sequence of m operations, the total cost is O(m × α(n)). Individual operations can occasionally cost more, but the average across all operations is O(α(n)).

Path compression's "expensive" first traversal is "paid for" by all future cheap queries on the same path.

---

## 12. 0-Based vs 1-Based Indexing

This trips up beginners constantly. Know both:

```cpp
// 0-BASED: nodes are 0, 1, 2, ..., n-1
DSU dsu(n);
// Access: dsu.find(0) to dsu.find(n-1)

// 1-BASED: nodes are 1, 2, ..., n
DSU dsu(n + 1);    // allocate one extra slot
// Access: dsu.find(1) to dsu.find(n)
// Node 0 is allocated but never used — that's fine!

// Competitive programming problems usually state
// "nodes numbered 1 to n" → use 1-based (DSU of size n+1)
```

---

## 13. Classic DSU Applications

### 1. Kruskal's Minimum Spanning Tree

The most famous application. Build MST by greedily adding edges:

```cpp
// Sort edges by weight
// For each edge (u, v, w):
//   If u and v are NOT connected → add edge to MST, unite(u, v)
//   If already connected → skip (would form a cycle)

sort(edges.begin(), edges.end());   // sort by weight
long long mst_weight = 0;
int edges_used = 0;

for (auto& [w, u, v] : edges) {
    if (dsu.unite(u, v)) {          // returns true if different components
        mst_weight += w;
        edges_used++;
        if (edges_used == n - 1) break;  // MST found
    }
}
```

**Worked Example — Kruskal's step by step:**

```
Graph (5 nodes, 7 edges):

     2       3
  0 --- 1 --- 4
  |  \     /  |
 6|   4\ /1   |5
  |     X     |
  2     |     3
  |  7  |
  3 --- 2

Edges sorted by weight:
  (1,4) weight=1   ← cheapest
  (0,1) weight=2
  (2,3) weight=7   (wait let me use a cleaner example)
```

```
Graph (4 nodes):
  Edges: (0-1, w=1), (0-2, w=4), (1-2, w=2),
         (1-3, w=5), (2-3, w=3)

  0 ---1--- 1 ---5--- 3
  |         |         |
  4         2         3
  |         |         |
  +-------- 2 --------+

Sorted edges: [(0,1,1), (1,2,2), (2,3,3), (0,2,4), (1,3,5)]

DSU starts: parent=[0,1,2,3]   components=4

Step 1: edge (0,1,w=1)
  find(0)=0, find(1)=1 → DIFFERENT → ADD to MST
  unite(0,1): parent=[0,0,2,3], MST_weight=1, edges=1

Step 2: edge (1,2,w=2)
  find(1)=0, find(2)=2 → DIFFERENT → ADD to MST
  unite(0,2): parent=[0,0,0,3], MST_weight=3, edges=2

Step 3: edge (2,3,w=3)
  find(2)=0, find(3)=3 → DIFFERENT → ADD to MST
  unite(0,3): parent=[0,0,0,0], MST_weight=6, edges=3
  edges == n-1 = 3 → STOP, MST complete!

Step 4: edge (0,2,w=4) → SKIPPED (not needed, already have n-1 edges)
Step 5: edge (1,3,w=5) → SKIPPED

MST edges: (0-1), (1-2), (2-3)   Total weight: 6
  0 ---1--- 1 ---2--- 2 ---3--- 3
```

### 2. Detecting Cycles in an Undirected Graph

```cpp
bool hasCycle(int n, vector<pair<int,int>>& edges) {
    DSU dsu(n);
    for (auto& [u, v] : edges) {
        if (dsu.connected(u, v))
            return true;            // edge connects already-connected nodes = cycle!
        dsu.unite(u, v);
    }
    return false;
}
```

### 3. Counting Connected Components

```cpp
int countComponents(int n, vector<pair<int,int>>& edges) {
    DSU dsu(n);
    for (auto& [u, v] : edges)
        dsu.unite(u, v);
    return dsu.getComponents();
}
```

### 4. Grid Problems (2D DSU)

Flatten 2D grid to 1D:
```cpp
// For an n×m grid, node (r, c) maps to index: r * m + c
// DSU of size n * m

auto idx = [&](int r, int c) { return r * m + c; };

// Unite adjacent cells
dsu.unite(idx(r, c), idx(r+1, c));  // vertical neighbor
dsu.unite(idx(r, c), idx(r, c+1));  // horizontal neighbor
```

**Worked Example — Number of Islands:**

```
Grid (4×5), '1' = land, '0' = water:

    Col:  0  1  2  3  4
Row 0:    1  1  0  0  1
Row 1:    1  0  0  1  1
Row 2:    0  0  1  0  0
Row 3:    0  1  1  0  0

Flat index mapping (row * 5 + col):
    Col:  0   1   2   3   4
Row 0:    0   1   2   3   4
Row 1:    5   6   7   8   9
Row 2:   10  11  12  13  14
Row 3:   15  16  17  18  19

Only land cells become DSU nodes:
  (0,0)=0, (0,1)=1, (0,4)=4
  (1,0)=5, (1,3)=8, (1,4)=9
  (2,2)=12
  (3,1)=16, (3,2)=17

Unions (adjacent land cells):
  unite(0,1)   ← (0,0)-(0,1) same row
  unite(0,5)   ← (0,0)-(1,0) same col
  unite(4,9)   ← (0,4)-(1,4) same col
  unite(8,9)   ← (1,3)-(1,4) same row
  unite(16,17) ← (3,1)-(3,2) same row

Components after all unions:
  {0,1,5}        ← island 1 (top-left)
  {4,8,9}        ← island 2 (top-right, connects (0,4)-(1,4)-(1,3))
  {12}           ← island 3 (lone cell)
  {16,17}        ← island 4 (bottom)

Answer: 4 islands = dsu.getComponents() (counting only land cells)
```

```cpp
// Full solution
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    DSU dsu(n * m);
    int water = 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == '0') { water++; continue; }
            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d], nc = c + dy[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m
                    && grid[nr][nc] == '1')
                    dsu.unite(r * m + c, nr * m + nc);
            }
        }
    }
    return dsu.getComponents() - water;  // subtract water cells
}
```

### 5. Online Dynamic Connectivity

When edges are added one at a time and you must answer connectivity queries between additions — DSU is the only efficient answer (note: DSU handles *additions* only, not deletions).

### 6. Friend Groups / Social Networks

```
"If A knows B and B knows C, do A and C know each other?"
→ Unite A-B, unite B-C → check if find(A) == find(C)
```

### 7. Percolation Theory (Physics)

Used in physics simulations to determine if a system "percolates" (forms a path from top to bottom through open cells). DSU is the standard algorithm.

---

## 14. Real Interview Problems (with Approach)

### Problem 1: Number of Provinces (LeetCode 547)
**Given:** `isConnected[i][j] = 1` if city i and city j are directly connected.  
**Find:** Number of provinces (groups of connected cities).

```cpp
int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    DSU dsu(n);
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if (isConnected[i][j])
                dsu.unite(i, j);
    return dsu.getComponents();
}
// Time: O(n² × α(n))
```

### Problem 2: Redundant Connection (LeetCode 684)
**Given:** Tree with one extra edge added.  
**Find:** Return that extra edge.

```cpp
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    DSU dsu(edges.size() + 1);  // 1-indexed
    for (auto& e : edges) {
        if (!dsu.unite(e[0], e[1]))  // if unite returns false, cycle found!
            return e;
    }
    return {};
}
```

### Problem 3: Accounts Merge (LeetCode 721)
**Pattern:** Each account has an owner and list of emails. Merge accounts that share any email.

```cpp
// Key insight: emails are the "nodes", accounts are groups
// Use a map<string, int> to assign ID to each unique email
// Unite all emails within the same account
// Group emails by their root → merge account info
```

### Problem 4: Number of Islands II (LeetCode 305 — Premium)
**Given:** Start with all water. Add islands one by one.  
**After each addition:** Count number of islands.

```cpp
// For each new land cell (r,c):
//   1. Add it to DSU
//   2. Check 4 neighbors — if neighbor is land, unite
//   3. Count components (subtract sea cells from total)
// → DSU shines here because it handles online additions perfectly
```

### Problem 5: Minimum Cost to Connect All Points (LeetCode 1584)
**Pattern:** Kruskal's MST with DSU.

```cpp
// Treat each point as a node
// Edge weight between points = Manhattan distance
// Run Kruskal's: sort all O(n²) edges, greedily add min-weight ones
```

### Problem 6: Most Stones Removed (LeetCode 947)
**Clever insight:** Stones in the same row or column can be removed until one remains.  
**Key:** Count connected components where stones share a row or column.

```cpp
// Unite stones that share a row or column
// Answer = n - number_of_components
```

---

## 15. Edge Cases & Common Mistakes

### Mistake 1: Forgetting to Initialize
```cpp
// WRONG: uninitialized parent array
int parent[100005];  // garbage values!

// CORRECT:
for (int i = 0; i <= n; i++) parent[i] = i;
```

### Mistake 2: Querying Non-Existent Nodes
```cpp
// If nodes are 1-indexed but DSU is of size n (not n+1):
DSU dsu(n);         // indices: 0 to n-1
dsu.find(n);        // OUT OF BOUNDS for node n!

// Fix:
DSU dsu(n + 1);     // safe for 1-indexed nodes 1..n
```

### Mistake 3: Modifying Rank After Path Compression
```cpp
// NEVER update rank after path compression changes the tree structure
// Rank is only updated during union operations
// This is why rank is called an "upper bound" — it may no longer be exact
```

### Mistake 4: Using DSU for Edge Deletion
```cpp
// DSU CANNOT efficiently handle edge/node deletions
// It only supports merging, never splitting
// For deletions: use offline processing (process deletions in reverse as additions)
// Or use Link-Cut Trees (very advanced)
```

### Mistake 5: Stack Overflow with Recursive find
```cpp
// Recursive find can stack overflow for n = 10^5 with a chain tree
// This CAN happen before any compression has occurred
// Always use iterative find in competitive programming
int find(int x) {                          // SAFE iterative version
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];    // path halving
        x = parent[x];
    }
    return x;
}
```

### Mistake 6: Not Checking if Already Connected
```cpp
// If you call unite(a, b) when a and b are already connected,
// the function should do NOTHING (and your component count shouldn't decrease)
// Make sure your unite checks: if (ra == rb) return;
```

### Mistake 7: Comparing Nodes Instead of Roots
```cpp
// WRONG:
if (a == b) return;        // checks if a and b are the SAME node, not same component

// CORRECT:
int ra = find(a), rb = find(b);
if (ra == rb) return;       // checks if they have the SAME ROOT = same component
```

---

## 16. DSU vs BFS/DFS — When to Use What

| Situation | Use |
|---|---|
| Static graph, find all components once | BFS/DFS (simpler) |
| Edges added online, repeated connectivity queries | **DSU** |
| Need shortest path | BFS (unweighted), Dijkstra (weighted) |
| Need to find if a cycle exists in undirected graph | **DSU** (elegant) |
| Minimum spanning tree | **DSU** (Kruskal's) |
| Grid flood fill | BFS/DFS |
| Grid with online cell additions and connectivity queries | **DSU** |
| Strongly connected components (directed graph) | Kosaraju/Tarjan (not DSU) |
| Biconnected components, bridges, articulation points | Tarjan's (not DSU) |

**Rule of thumb:** If edges are only being **added** (never removed) and you need **connectivity** queries → DSU is almost certainly optimal.

---

## 17. Advanced DSU Tricks

### Trick 1: Path Halving (Alternative to Full Path Compression)

Instead of pointing everything to the root, point every node to its *grandparent*. Simpler, same amortized complexity:

```cpp
int find(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];  // skip one level
        x = parent[x];
    }
    return x;
}
```

### Trick 2: Rollback DSU (DSU with Undo)

When you need to undo union operations (e.g., in offline algorithms):
- **Use union by rank only** (NOT path compression — it's irreversible)
- Keep a stack of changes
- Pop and undo when rolling back

```cpp
struct DSU_Rollback {
    vector<int> parent, rank;
    vector<pair<int*,int>> history;  // stores (pointer, old_value)

    void save(int& x) { history.push_back({&x, x}); }
    
    bool unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return false;
        if (rank[ra] < rank[rb]) swap(ra, rb);
        save(parent[rb]); parent[rb] = ra;
        save(rank[ra]);   if (rank[ra] == rank[rb]) rank[ra]++;
        return true;
    }
    
    void rollback() {
        auto [ptr, val] = history.back();
        history.pop_back();
        *ptr = val;
        // repeat for the full saved transaction
    }
    
    // find WITHOUT path compression (must be pure traversal)
    int find(int x) {
        while (parent[x] != x) x = parent[x];
        return x;
    }
};
```

This is used in problems involving "offline dynamic connectivity" with both insertions and deletions.

### Trick 3: Small-to-Large Merging (DSU-like technique)

When merging sets of data (not just tracking connectivity), use "union by size":
- Always merge the smaller set into the larger
- Total work: O(n log n)

```cpp
// Example: merge sets of strings
vector<set<string>> groups(n);
// ... initialize ...

// When uniting group a and group b:
if (groups[ra].size() < groups[rb].size()) swap(ra, rb);
for (auto& x : groups[rb])
    groups[ra].insert(x);              // insert smaller into larger
groups[rb].clear();
```

### Trick 4: Persistent DSU

In functional/persistent settings, keep DSU as an immutable tree. Use link-cut trees or version arrays. Very advanced, rarely needed.

### Trick 5: Parallel DSU

For multi-threaded programs, DSU with atomic operations is possible but requires careful locking around the find-and-unite sequence. Research-level topic.

---

## 18. Weighted DSU (Bonus — Very Rare, Very Powerful)

In standard DSU, edges are unweighted. But you can store **relative weights** along edges for problems involving ratios or differences.

**Example problem:** "Evaluate Division" (LeetCode 399) — given `a/b = 2.0, b/c = 3.0`, find `a/c`.

**Key idea:** Store edge weights as "ratio to parent". When doing path compression, multiply weights along the path.

```cpp
struct WeightedDSU {
    vector<int> parent;
    vector<double> weight;  // weight[x] = (value of x) / (value of parent[x])

    WeightedDSU(int n) : parent(n), weight(n, 1.0) {
        iota(parent.begin(), parent.end(), 0);
    }

    pair<int, double> find(int x) {
        if (parent[x] == x) return {x, 1.0};
        auto [root, w] = find(parent[x]);
        parent[x] = root;
        weight[x] *= w;               // update weight to point directly to root
        return {root, weight[x]};
    }

    void unite(int a, int b, double ratio) {
        // ratio = value[a] / value[b]
        auto [ra, wa] = find(a);
        auto [rb, wb] = find(b);
        if (ra == rb) return;
        parent[ra] = rb;
        weight[ra] = ratio * wb / wa;
    }

    double query(int a, int b) {
        auto [ra, wa] = find(a);
        auto [rb, wb] = find(b);
        if (ra != rb) return -1.0;    // not connected
        return wa / wb;
    }
};
```

This is a niche but powerful technique. It appears in problems involving:
- Ratios between values
- Differences/offsets between values (use additive weights)
- Relative orderings

---

## 19. Quick Reference Cheat Sheet

```
╔══════════════════════════════════════════════════════════╗
║               DSU CHEAT SHEET                           ║
╠══════════════════════════════════════════════════════════╣
║  Initialize:   parent[i] = i,  size[i] = 1             ║
║                                                          ║
║  find(x):      while parent[x] != x:                    ║
║                    parent[x] = parent[parent[x]]         ║
║                    x = parent[x]                         ║
║                return x                                  ║
║                                                          ║
║  unite(a,b):   ra, rb = find(a), find(b)               ║
║                if ra == rb: return                       ║
║                if size[ra] < size[rb]: swap(ra,rb)      ║
║                parent[rb] = ra                           ║
║                size[ra] += size[rb]                      ║
║                                                          ║
║  connected:    find(a) == find(b)                        ║
║  comp size:    size[find(x)]                             ║
║  num comps:    track with a counter                      ║
╠══════════════════════════════════════════════════════════╣
║  Time:   O(α(n)) ≈ O(1) per operation                  ║
║  Space:  O(n)                                            ║
╠══════════════════════════════════════════════════════════╣
║  α(10^80) = 4  → effectively constant ALWAYS            ║
║  DSU cannot handle DELETIONS                             ║
║  Use iterative find to avoid stack overflow              ║
║  1-indexed graph → create DSU of size n+1               ║
╚══════════════════════════════════════════════════════════╝
```

---

## 20. Practice Problems Roadmap

Work through these in order — they cover every pattern.

### Level 1 — Basics (Just Union/Find)
- [LeetCode 547] Number of Provinces
- [LeetCode 684] Redundant Connection
- [LeetCode 1971] Find if Path Exists in Graph
- [LeetCode 323] Number of Connected Components (Premium)

### Level 2 — Grid DSU
- [LeetCode 200] Number of Islands (try both BFS and DSU)
- [LeetCode 695] Max Area of Island
- [LeetCode 1319] Number of Operations to Make Network Connected
- [LeetCode 1905] Count Sub Islands

### Level 3 — Creative Applications
- [LeetCode 721] Accounts Merge
- [LeetCode 947] Most Stones Removed with Same Row or Column
- [LeetCode 1584] Min Cost to Connect All Points (Kruskal's)
- [LeetCode 990] Satisfiability of Equality Equations

### Level 4 — Advanced
- [LeetCode 305] Number of Islands II (Online additions)
- [LeetCode 399] Evaluate Division (Weighted DSU)
- [LeetCode 1579] Remove Max Number of Edges to Keep Graph Fully Traversable
- [LeetCode 765] Couples Holding Hands

### Codeforces Problems
- CF 1027F — Session of Exams (sorting + DSU)
- CF 1051G — Distinctification (DSU with small-to-large)
- CF 827F — Dirty Arkadiy (offline + DSU)
- CF 292E — Copying Data (segment tree + DSU — hardcore)

---

## 21. How to Identify a DSU Problem

This is the skill that separates beginners from intermediate programmers. Recognizing the pattern saves you from trying BFS, DFS, or brute force when DSU is the obvious answer.

---

### The Master Checklist — Read the Problem Statement

Go through this list when you see a new problem. If **2 or more** of these match, DSU is almost certainly the right tool.

```
□  1. Things get "grouped", "merged", "connected", "joined", or "combined" over time
□  2. You need to answer "are these two things in the same group?"
□  3. Elements start separate and connections are only ADDED (never removed)
□  4. The problem involves a network, graph, or grid with connectivity
□  5. You need to count distinct groups/components
□  6. You need the size of a group containing a specific element
□  7. You need to find a minimum spanning tree
□  8. You need to detect if adding an edge creates a cycle
□  9. The problem says "at the time of query" or queries are interleaved with updates
□ 10. Elements share a property (same row, same color, same owner) that makes them equivalent
```

---

### Keyword Radar — Phrases in Problem Statements

When you see these exact phrases, your DSU antenna should fire immediately:

**🔴 STRONG signals (almost always DSU):**
```
"same component"
"same group"
"connected components"
"number of islands"
"union-find"
"disjoint sets"
"merge the groups"
"redundant connection"
"minimum spanning tree"
"belong to the same ..."
"friends of friends"   ← transitive relationships
```

**🟡 MEDIUM signals (check other conditions):**
```
"reachable"
"path exists between"
"network of"
"cluster"
"partition into groups"
"equivalence classes"
"transitive closure"
"same category"
"link/connect"
"how many groups after k operations"
```

**🟢 CONTEXTUAL signals (DSU when combined with others):**
```
"minimum cost to connect all"  ← + spanning tree = DSU + Kruskal
"can you connect all nodes"    ← connectivity = DSU
"find if cycle exists"         ← undirected graph = DSU
"online queries"               ← real-time updates = DSU over BFS/DFS
"at each step, add edge..."    ← incremental = DSU
```

---

### Pattern Recognition by Problem Type

#### Type 1 — Pure Connectivity ("Are these two nodes connected?")

**Signals:**
- You're given a graph or list of edges
- Queries of the form: `connected(a, b)?`
- Edges may be added online (between queries)

**Examples:**
```
"Given friendships, for each query check if person A and B are friends 
 (directly or through mutual friends)"
→ Unite friends. Answer queries with find(A)==find(B).

"A network of computers. Can computer X communicate with computer Y?"
→ Each cable = edge. Unite connected computers. Query with find.
```

**DSU fit:** ⭐⭐⭐⭐⭐ Perfect.

---

#### Type 2 — Component Counting ("How many groups are there?")

**Signals:**
- "Count the number of distinct islands/clusters/provinces/components"
- Elements start disconnected; connections arrive one by one or are given all at once

**Examples:**
```
"How many provinces are there?"   (LeetCode 547)
"Count connected components in a graph"
"After adding all edges, how many separate networks remain?"
```

**DSU fit:** ⭐⭐⭐⭐⭐ Perfect. Track a counter: start at n, decrement on each successful unite.

---

#### Type 3 — Component Size ("How many elements are in this group?")

**Signals:**
- "Size of the group containing node X"
- "Largest component"
- "What is the population of the cluster?"

**Examples:**
```
"After connecting computers, what is the size of the largest network?"
"Max area of island"   (LeetCode 695)
```

**DSU fit:** ⭐⭐⭐⭐⭐ Use Union by Size — you get component sizes for free.

---

#### Type 4 — Cycle Detection in Undirected Graphs

**Signals:**
- "Is there a redundant edge?"
- "Does adding this edge create a cycle?"
- "Find the extra edge in a tree + 1 edge"

**Examples:**
```
"Given n nodes and n edges forming a tree + 1 extra edge, find it"  (LC 684)
"Does this graph have a cycle?"
```

**Trick:** If `find(u) == find(v)` BEFORE you add edge (u,v), that edge creates a cycle.

**DSU fit:** ⭐⭐⭐⭐⭐ Cleaner than DFS for this.

---

#### Type 5 — Spanning Tree ("Minimum cost to connect all nodes")

**Signals:**
- "Minimum cost to connect all nodes/cities/computers"
- "Cheapest set of cables/roads to connect the network"
- "Minimum spanning tree"

**DSU fit:** ⭐⭐⭐⭐⭐ Kruskal's Algorithm = DSU + sort edges.

---

#### Type 6 — Online Graph Construction ("Add edges one at a time, answer queries between")

**Signals:**
- "After each addition, answer a query"
- "Queries interleaved with union operations"
- "At time T, are nodes A and B connected?"

**Why not BFS/DFS?** BFS/DFS on each query = O(Q × (n+E)). DSU = O(Q × α(n)).

**DSU fit:** ⭐⭐⭐⭐⭐ DSU is the *only* efficient solution here.

---

#### Type 7 — Equivalence Relations ("If A=B and B=C, then A=C")

**Signals:**
- Transitivity is mentioned or implied
- Elements that "share a property" are grouped together
- "All elements with the same X belong to the same group"

**Examples:**
```
"Equations like a==b, b==c. Are a and c equal?"  (LC 990)
"Accounts with the same email belong to the same person"  (LC 721)
"Stones in the same row or column can be removed together"  (LC 947)
```

**Key insight:** DSU models equivalence classes perfectly. The find() root IS the equivalence class representative.

**DSU fit:** ⭐⭐⭐⭐⭐ Perfect.

---

#### Type 8 — Grid Connectivity ("Connected cells in a 2D grid")

**Signals:**
- 2D grid with cells that are "land/water", "open/blocked", "1/0"
- Questions about connected regions
- Cells are added/opened one at a time

**Examples:**
```
"Number of islands"        ← classic
"Max area of island"
"Number of islands II"     ← online, cells added one-by-one
"Surrounded regions"
```

**DSU fit:** ⭐⭐⭐⭐ (BFS/DFS also work for static grids; DSU wins for online additions)

---

### When DSU Does NOT Fit — The Anti-Patterns

Avoid DSU when:

```
❌ You need shortest paths
   → Use BFS (unweighted) or Dijkstra/Bellman-Ford (weighted)

❌ The graph is DIRECTED and you need reachability
   → Use BFS/DFS or SCC algorithms (Kosaraju/Tarjan)

❌ You need to REMOVE edges/connections (not just add)
   → DSU cannot split groups. Use offline reversal trick or Link-Cut Trees.

❌ You need articulation points, bridges, or biconnected components
   → Use Tarjan's algorithm

❌ You need strongly connected components in directed graphs
   → Use Kosaraju's or Tarjan's SCC algorithm

❌ You need to find ALL paths between two nodes
   → Use DFS/BFS with backtracking

❌ The problem has NO grouping/merging structure at all
   → Probably a different data structure entirely
```

---

### The "Smell Test" — Quick Decision in 10 Seconds

When you read a new problem, ask yourself these 3 questions:

```
Question 1: "Are things being GROUPED or CONNECTED together?"
  YES → strong DSU signal, continue

Question 2: "Are connections only ADDED (never removed)?"
  YES → DSU is viable
  NO  → need rollback DSU or a different approach

Question 3: "Do I need CONNECTIVITY or COMPONENT info?"
  (are they same group? how many groups? how large is this group?)
  YES → DSU is almost certainly correct
```

If all 3 are YES → write DSU, don't overthink it.

---

### Disguised DSU Problems — Non-Obvious Patterns

These look nothing like "find connected components" but are solved with DSU:

| Problem Description | Hidden DSU Pattern |
|---|---|
| "Merge overlapping intervals that share a category" | Intervals in same category → unite |
| "Satisfy equations like a/b=2, find a/c" | Weighted DSU on variables |
| "Find minimum extra edges to make graph connected" | Count components, need (components-1) edges |
| "String manipulation: if swap(i,j) allowed, are two strings equivalent?" | Characters at position i,j → unite |
| "Team ranking: A beats B, B beats C, who beats who?" | Implicit equivalence chain |
| "Pixels with same color are one region" | Color-based union on grid |
| "Satisfiability: can we assign True/False without contradiction?" | 2-SAT (related but uses SCC, not DSU) |

---

## 22. The Problem-Solving Approach — Step by Step

You've identified that DSU is the right tool. Now what? Follow this 6-step framework.

---

### The Framework

```
┌─────────────────────────────────────────────────────┐
│           DSU Problem-Solving Framework             │
├─────────────────────────────────────────────────────┤
│  Step 1: Identify the NODES                         │
│  Step 2: Identify the UNION condition               │
│  Step 3: Identify the QUERY type                    │
│  Step 4: MAP entities to integers (if needed)       │
│  Step 5: PROCESS unions                             │
│  Step 6: ANSWER queries                             │
└─────────────────────────────────────────────────────┘
```

---

### Step 1: Identify the Nodes

Ask: **"What are the distinct things being grouped?"**

These become your DSU nodes (integers 0 to n-1).

| Problem | Nodes are |
|---|---|
| Cities connected by roads | City IDs |
| Islands in a grid | Grid cells (r,c) |
| Accounts with emails | Email addresses (mapped to int) |
| Equations a==b | Variable names (mapped to int) |
| Pixels in an image | Pixel coordinates |
| People in a social network | Person IDs |

**Non-integer nodes:** If nodes are strings, names, or coordinates, use a `map<string, int>` or `map<pair<int,int>, int>` to assign each unique entity an integer ID.

```cpp
// Example: nodes are email strings
map<string, int> id;
int counter = 0;

auto getID = [&](string& s) {
    if (!id.count(s)) id[s] = counter++;
    return id[s];
};

DSU dsu(max_possible_nodes);
// Now use getID(email) as the node number
```

---

### Step 2: Identify the Union Condition

Ask: **"Under what condition do two nodes become part of the same group?"**

```
Problem: "Two computers are in the same network if connected by a cable"
→ Union condition: there exists an edge (cable) between them
→ For each edge (u,v): dsu.unite(u, v)

Problem: "Two accounts belong to the same person if they share an email"
→ Union condition: two accounts have at least one email in common
→ For each account, unite all its emails together

Problem: "Two grid cells are connected if both are land and adjacent"
→ Union condition: both cells are '1' and they are 4-directionally adjacent
→ For each '1' cell, check all 4 neighbors; if neighbor is '1', unite them

Problem: "Stone A and Stone B can be removed together if same row or col"
→ Union condition: same row OR same column
→ Unite all stones in the same row; unite all stones in the same column
```

---

### Step 3: Identify the Query Type

Ask: **"What does the problem actually want me to output?"**

| Query | How to Answer |
|---|---|
| "Are A and B connected?" | `find(A) == find(B)` |
| "How many components?" | `dsu.getComponents()` |
| "Size of component containing X" | `dsu.getSize(X)` |
| "Largest component" | Track max size during each unite |
| "Does adding edge create a cycle?" | Check `find(u)==find(v)` BEFORE uniting |
| "Minimum cost to connect all" | Kruskal's: sort edges, unite greedily |
| "Find the redundant edge" | The edge where `find(u)==find(v)` |

---

### Step 4: Map Entities to Integers

This step is often what trips people up. Real problems rarely give you clean integer nodes.

**Case A: Nodes are already integers 1..n**
```cpp
DSU dsu(n + 1);  // 1-indexed
// Done. Use node numbers directly.
```

**Case B: Nodes are strings**
```cpp
map<string, int> nodeID;
int cnt = 0;
auto getNode = [&](const string& s) -> int {
    if (!nodeID.count(s)) nodeID[s] = cnt++;
    return nodeID[s];
};
DSU dsu(total_unique_strings);
```

**Case C: Nodes are (row, col) pairs in a grid**
```cpp
// n rows, m cols
auto idx = [&](int r, int c) { return r * m + c; };
DSU dsu(n * m);
// Unite: dsu.unite(idx(r1,c1), idx(r2,c2))
```

**Case D: Two different types of entities must be in same DSU**
```cpp
// Example: "rows" and "columns" are both nodes
// Give rows IDs 0..n-1 and columns IDs n..n+m-1
auto rowNode = [&](int r) { return r; };
auto colNode = [&](int c) { return n + c; };
DSU dsu(n + m);
```

---

### Step 5: Process Unions

Iterate through all given connections/edges/relationships and call `unite`.

**Pattern A: Given explicit edge list**
```cpp
for (auto& [u, v] : edges)
    dsu.unite(u, v);
```

**Pattern B: Given a 2D adjacency matrix**
```cpp
for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
        if (adj[i][j] == 1)
            dsu.unite(i, j);
```

**Pattern C: Given a grid, unite land neighbors**
```cpp
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

for (int r = 0; r < n; r++)
    for (int c = 0; c < m; c++)
        if (grid[r][c] == '1')
            for (int d = 0; d < 4; d++) {
                int nr = r + dx[d], nc = c + dy[d];
                if (inBounds(nr, nc) && grid[nr][nc] == '1')
                    dsu.unite(r*m+c, nr*m+nc);
            }
```

**Pattern D: Union by shared property (e.g., same row or col)**
```cpp
// Group elements that share a column
map<int, int> lastInCol;  // col → last node seen in that col

for (auto& [r, c] : stones) {
    if (lastInCol.count(c))
        dsu.unite(idx(r,c), lastInCol[c]);
    lastInCol[c] = idx(r,c);
}
```

**Pattern E: Sort-then-unite (Kruskal's style)**
```cpp
sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
    return a.weight < b.weight;
});

for (auto& e : edges) {
    if (dsu.unite(e.u, e.v))
        mst_cost += e.weight;
}
```

---

### Step 6: Answer Queries

This is usually the simplest step once DSU is built.

```cpp
// Q: "Are u and v connected?"
bool ans = dsu.connected(u, v);  // find(u) == find(v)

// Q: "How many distinct groups?"
int ans = dsu.getComponents();

// Q: "What is the size of the group containing node x?"
int ans = dsu.getSize(x);  // size[find(x)]

// Q: "What is the largest group size?"
int maxSz = 0;
for (int i = 0; i < n; i++)
    if (dsu.find(i) == i)         // only check roots
        maxSz = max(maxSz, dsu.getSize(i));

// Q: "Minimum edges to connect all components?"
int ans = dsu.getComponents() - 1;  // need (k-1) edges to connect k components

// Q: "Does this edge create a cycle?"
bool cycle = dsu.connected(u, v);   // check BEFORE uniting
if (!cycle) dsu.unite(u, v);
```

---

### Worked Example — Applying the Framework (LeetCode 721: Accounts Merge)

**Problem:** Given a list of accounts where each account = `[name, email1, email2, ...]`. Accounts belonging to the same person share at least one email. Merge them.

**Step 1 — Identify nodes:**
Each **email** is a node. (Not the account — the email!)

**Step 2 — Union condition:**
Two emails should be in the same group if they appear in the same account.
→ For each account, unite `email[0]` with `email[1]`, `email[0]` with `email[2]`, etc.

**Step 3 — Query type:**
Group emails by their DSU root. For each group, output the owner's name + sorted emails.

**Step 4 — Map strings to integers:**
```cpp
map<string, int> emailID;
map<string, string> emailOwner;  // email → account name
int cnt = 0;

for (auto& acc : accounts) {
    string name = acc[0];
    for (int i = 1; i < acc.size(); i++) {
        if (!emailID.count(acc[i])) emailID[acc[i]] = cnt++;
        emailOwner[acc[i]] = name;
    }
}
DSU dsu(cnt);
```

**Step 5 — Process unions:**
```cpp
for (auto& acc : accounts) {
    int rootID = emailID[acc[1]];  // first email in account is the "anchor"
    for (int i = 2; i < acc.size(); i++)
        dsu.unite(rootID, emailID[acc[i]]);
}
```

**Step 6 — Answer query:**
```cpp
map<int, vector<string>> groups;  // root → list of emails
for (auto& [email, id] : emailID)
    groups[dsu.find(id)].push_back(email);

vector<vector<string>> result;
for (auto& [root, emails] : groups) {
    sort(emails.begin(), emails.end());
    emails.insert(emails.begin(), emailOwner[emails[0]]);  // prepend name
    result.push_back(emails);
}
return result;
```

**Why DSU and not BFS/DFS?**
BFS/DFS would require building a graph where accounts are nodes and shared emails are edges — much more complex to construct. DSU naturally handles the "union of accounts sharing an email" in one clean pass.

---

### Worked Example 2 — Applying the Framework (LC 990: Equations)

**Problem:** Given equations like `["a==b", "b==c", "a!=d"]`, return true if all can be satisfied simultaneously.

**Step 1 — Identify nodes:**
Each **variable** (letter) is a node. At most 26 variables (a-z).

**Step 2 — Union condition:**
`x == y` → unite(x, y)

**Step 3 — Query type:**
For each `!=` equation: check that `find(x) != find(y)`. If they're in the same component, contradiction → return false.

**Step 4 — Map to integers:**
```cpp
// 'a' → 0, 'b' → 1, ..., 'z' → 25
DSU dsu(26);
auto idx = [](char c) { return c - 'a'; };
```

**Step 5 & 6 — Process in two passes:**
```cpp
// Pass 1: process all '==' first (build groups)
for (auto& eq : equations)
    if (eq[1] == '=')
        dsu.unite(idx(eq[0]), idx(eq[3]));

// Pass 2: check all '!=' (verify no contradiction)
for (auto& eq : equations)
    if (eq[1] == '!')
        if (dsu.connected(idx(eq[0]), idx(eq[3])))
            return false;  // same group but claimed unequal → contradiction

return true;
```

**Key insight from this example:** Process `==` (union operations) FIRST, then check `!=` constraints. This two-pass trick appears in many DSU problems.

---

### Common Problem-Solving Mistakes and How to Avoid Them

**Mistake: Treating the problem as directed**
```
Problem: "If A can reach B through a series of connections..."
If it says "can reach" in an UNDIRECTED graph → DSU works
If it says "can reach" in a DIRECTED graph → DSU does NOT work, use BFS/DFS
Always check: does the connection go both ways?
```

**Mistake: Unioning the wrong things**
```
Wrong: "Accounts share an email" → uniting ACCOUNTS
Right: uniting EMAILS (the actual shared identifier)

The things you union must be the things that transitively connect.
```

**Mistake: Off-by-one on DSU size**
```
Nodes are 1..n → DSU dsu(n+1), not DSU dsu(n)
Don't access dsu.find(n) if dsu has size n (indices 0..n-1 only)
```

**Mistake: Forgetting to handle the "already same component" case**
```cpp
// When counting extra edges (e.g., redundant connections):
for (auto& [u, v] : edges) {
    if (!dsu.unite(u, v)) {
        extra_edges++;  // unite returned false → already connected → redundant edge
    }
}
```

**Mistake: Using DSU for directed connectivity**
```
DSU says: if A→B and B→C, then A and C are "connected"
But in directed graphs: A→B→C doesn't mean C can reach A
DSU merges bidirectionally. Never use it for one-way reachability.
```

---

### Decision Flowchart

```
                    Read the problem
                          │
                          ▼
              Does it involve grouping,
              merging, or connectivity?
              /                      \
            NO                       YES
             │                        │
         Probably                     ▼
         not DSU          Are connections ADDED only
                          (never deleted)?
                          /                \
                        NO                 YES
                         │                  │
                    Need rollback            ▼
                    DSU or offline     Do you need:
                    trick              - "same group?" queries
                                       - component count?
                                       - component size?
                                       - cycle detection?
                                       - MST?
                                       /              \
                                     NO               YES
                                      │                │
                                  Maybe BFS/DFS      USE DSU ✓
                                  is enough
```

---

**DSU is beautiful** because it solves a hard problem (dynamic connectivity) with just two arrays and two simple functions. The fact that its complexity touches the Inverse Ackermann function — one of the slowest-growing functions in mathematics — makes it a perfect blend of theory and practice.

Memorize the combined implementation (path compression + union by size). It's short, elegant, and will solve hundreds of problems.

```
"DSU is the hammer that makes connectivity nails disappear."
```

When you see a problem involving:
- Merging groups
- Checking if two things are "connected"
- Building a spanning tree
- Cycle detection in undirected graphs
- Online graph construction

→ Reach for DSU first.

---

*Guide written for serious learners. Good luck on your DSU journey!*
