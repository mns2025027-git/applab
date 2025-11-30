My bad! I assumed you wanted Kahn's because it's often the default for "Topological Sort" in many labs. But **DFS** is actually cleaner to write (shorter code) because it uses recursion instead of managing a queue and in-degrees.

Here is the **DFS** version using the **Adjacency List**.

### 1. The Logic (DFS Approach)

The logic is "Reverse Post-Order":
1.  Start a standard DFS traversal.
2.  **The Trick:** You only add a node to the "Result Stack" **AFTER** you have visited all its children.
3.  **Why?** If Node A points to Node B (`A -> B`), the recursion goes to B first, finishes B, puts B on the stack. Then it returns to A, finishes A, and puts A on the stack.
4.  When you pop the stack, A comes out before B. Order preserved!

### 2. The Code (DFS + Adjacency List)

I have used the same Adjacency List structure as before, but added a simple **Stack** array.


http://googleusercontent.com/immersive_entry_chip/0



[Image of Stack Data Structure]


### 3. Visual Explanation (The "Stack" Trick)

Let's trace `addEdge(graph, 5, 2)` and `addEdge(graph, 2, 3)` (So `5 -> 2 -> 3`).

1.  **Start at 5:**
    * Call `dfs(5)`. Mark 5 visited.
    * Find neighbor 2. Call `dfs(2)`.
2.  **Inside 2:**
    * Mark 2 visited.
    * Find neighbor 3. Call `dfs(3)`.
3.  **Inside 3:**
    * Mark 3 visited.
    * Any neighbors? No.
    * **PUSH 3 to Stack.** (Stack: `[3]`)
    * Return to 2.
4.  **Back Inside 2:**
    * Any other neighbors? No.
    * **PUSH 2 to Stack.** (Stack: `[3, 2]`)
    * Return to 5.
5.  **Back Inside 5:**
    * Any other neighbors? No.
    * **PUSH 5 to Stack.** (Stack: `[3, 2, 5]`)

**Printing:**
We pop from the top: `5`, then `2`, then `3`.
Result: **5 -> 2 -> 3**.

See? Because we pushed **after** recursion returned, the "deepest" node (3) ended up at the bottom of the stack, and the "starter" node (5) ended up at the top.

Does this DFS version feel easier than the Kahn's version? (Most people find the code shorter).